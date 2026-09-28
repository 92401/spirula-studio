# Scene partitioning: train a reconstruction in parts and merge the models

`spirula partition` and the GUI's Partition panel (dataset screen, beside
"Open in Trainer" and "Edit Reconstruction") split one reconstruction into
parts that each fit a single training run, and merge the trained parts back
into one model. The code is portable host code in `data/ScenePartition.h`,
`data/LabelField.h`, `data/Region.h`, `data/RegionProgram.h`,
`core/GraphCut.h` and `checkpoint/SplatMerge.h`; the device test is
`shaders/region.slang` behind `kernels/densify/RegionWeight.cu`; the trainer
hooks are `--partition` / `--partition-part` and `--roi-region`
(`TrainerSession::apply_partition_config`, `setup_region`).

## Why not Voronoi over the cameras

The obvious split -- k-means on positions, Voronoi cells, crop by cell at the
merge -- already leaves surprisingly few visible seams, because a Gaussian's
look is set by nearby cameras. What survives comes from four places: Gaussians
straddling a cell boundary, sky and far geometry that every part reconstructs
on its own, per-image appearance drift between parts, and floaters that one
part grows in front of another part's cameras. The scheme here targets the
first and the last two directly; appearance drift is left for a later shared
initialization (see "Not done").

## Regions first (the default, `--method spatial`)

Cutting the *cameras* first (steps 2 and 3 below, `--method viewgraph`)
groups cameras that look the same way even when they stand far apart, and a
part's region is then wherever those cameras happened to look. On Atrium at
800 images a part's cameras saw on average only 23-53% of their own part,
and each part borrowed a ring 1.3-2.2 times its core. So the default cuts
*space* first and hands out cameras afterwards (`spatial_cut`, `home_parts`):

- The observed points are cut by a plane, recursively. For the region with
  the heaviest camera load, the candidates are 13 positions (20th to 80th
  percentile) across each of its two widest principal axes -- never the
  thinnest, which would split a floor from its ceiling and leave every camera
  seeing both; each is scored by the cameras the two halves would need -- a
  half needs a camera holding `--ring` (0.2) or half of that camera's view --
  as `(l + r)(1 + |l - r| / (l + r))`: few cameras in total, split evenly.
  Splitting stops when every region needs at most `--max-images` cameras (or
  at `--parts` regions).
- Within 1% of a cut (of the 5th-95th percentile extent -- the full extent,
  stretched by stray SfM points, once widened the band over the whole region
  and turned it into a per-point vote), a point goes to the side its
  observers stand on, so a wall's two photographed faces each stay with
  their own side.
- A camera's home (its core part) is the region most of its view is in; it
  also joins the ring of any other region holding `--ring` of its view. A
  region no camera calls home goes to the home its observers vote for.

On Atrium at `--max-images 800` this gives 12 compact parts, each needing
424-772 cameras in all, whose cameras see 44-69% of their own part (the CLI
prints this per part); ownership interleaves 3% of nearest neighbours.
Cameras standing together may belong to different parts when they look at
different regions; that is intended. Without point observations (poses
only) the view-graph method is used.

Measured on Atrium, 6000 steps per part, every 8th frame held out,
colour-corrected PSNR / SSIM of the merge against one model trained on
everything (22.73 / 0.793, 459 s); per-view differences pair views by their
ground-truth image, since two runs visit held-out views in different orders:

| split | merge | mean dPSNR | views < -3 dB | worst | train time |
|---|---|---|---|---|---|
| view graph, ring 0.05 (before) | 22.58 / 0.801 | -0.15 | 3 | -3.9 | 1285 s |
| regions first | 22.37 / 0.805 | -0.36 | 15 | -4.4 | 1035 s |
| regions first + region masks (default) | 22.46 / 0.803 | -0.27 | 9 | -4.8 | 884 s |
| regions first + opacity decay 0.5 | 20.39 / 0.773 | | | | 943 s |

## The pipeline

1. **Covisibility graph** over the cameras (`build_covisibility`). One node per
   frame, edge weight = number of 3D points two frames both observe. Where the
   observations come from is the only thing that changes per dataset:
   - a COLMAP model (including this tool's own SfM output): its tracks, read by
     `read_sparse_stats`;
   - a Nerfstudio or Metashape dataset: the seed cloud projected into every
     frame with the host camera models (`camhost::ray_in_frame`), which is a
     covisibility proxy that ignores occlusion; at most `max_projected_points`
     points are projected and their observers are shared with the unsampled
     points beside them;
   - poses only: k nearest camera centres, weighted `1 + cos(view angle)`.
   `Auto` takes the first of these that works.
2. **Cut** (view-graph method; `graph::cut_labels`): recursive normalized-cut bisection by the
   Fiedler vector of the normalized Laplacian, the same code the bottom-up SfM
   mapper uses for its atoms, with three things the mapper does not want:
   each side of a bisection must hold at least 30% of the parent (a free
   normalized cut shaves off weakly attached clumps one at a time, which is
   what left a utias part in 437 pieces), a half the sweep left in pieces
   hands every piece but its largest to the other half, and a few passes of
   boundary refinement move a camera to the part it shares more with while
   the sizes stay within a quarter of the mean. Either exactly `--parts`
   parts (the costliest part is bisected until the count is reached) or as
   many as keep every part at or under `--max-images`. Parts under 2% of the
   cameras join their best-connected neighbour; an isolated camera joins the
   part of the nearest one. Labels are dense, largest part first, and the
   CLI says when a part is not one piece of the view graph.
   Frames are identified by the shortest tail of their path that is unique
   in the dataset, never the bare leaf: a rig has `cam0/00123.jpg` and
   `cam1/00123.jpg`.
3. **Point ownership** (view-graph method; `own_points`): each seed point starts as the part of
   its nearest camera, then those labels diffuse for 40 rounds over the
   points' 12 nearest neighbours -- an edge as strong as the share of one
   point's observers that are, or are covisible with, the other's, so the
   diffusion does not leak through a wall -- and last, any piece of a part
   smaller than a quarter of its largest joins the larger piece it borders
   most. What this replaced, a vote over each point's observers, interleaved
   two parts wherever both saw a surface: on a two-part classroom 36% of
   every point's ten neighbours belonged to the other part (1.5% now), and
   the merge, a salt-and-pepper mix of two models, lost 2.6 dB against its
   own parts. Measured alternatives, parts trained fresh and scored on
   held-out views (colour-corrected PSNR / SSIM, one model over everything
   for reference):

   | scene, steps | one model | nearest observer + smooth | 1/d^2 over observers + smooth | nearest camera | **nearest camera + smooth** |
   |---|---|---|---|---|---|
   | classroom, 2 parts, 7k | 19.64 / .741 | 19.43 / .743 | 19.50 / .739 | 19.56 / .744 | 19.54 / .742 |
   | Atrium, 7 parts, 2k | 21.22 / .764 | 20.95 / .767 | 20.98 / .768 | 21.18 / .771 | 21.14 / .771 |

   Anything built on the tracks loses: a point is tracked in a handful of the
   frames that see it, so "which part observed it" is mostly noise (on
   Atrium 47% of points have no observation from their nearest camera's
   part). The smoothing costs nothing measurable over plain nearest-camera
   Voronoi and guarantees one coherent region per part. What it gives up: a
   thin wall's far face, when it is nearer to the other room's cameras than
   to its own, goes to the other room, whose model never saw it. No capture
   tried here has that layout; the observer rule would fix it at the cost in
   the table.
4. **Owned region** (`LabelField::build`): every point of space belongs to
   the nearest *seed* -- the labelled points (strided to `--max-seeds`), each
   carrying the mean direction toward the cameras that observed it; the
   cameras are seeds only when there are no points, since a camera standing
   in another part's space would cut a hole in it. The metric is not
   Euclidean: the space *behind* a seed, relative to the side it was seen
   from, counts `kBehindWeight` (8) times farther, and a query that carries a
   normal facing away from a seed's viewing direction is `kOrientPenalty` (20)
   times farther (`shaders/region.slang`). So a wall photographed from one
   room does not claim the other room's air, and a splat on the wall's back
   -- seen only from the next room -- stays with that room's model.
   Density-adaptive and unbounded by construction: no grid, no resolution,
   and a far splat goes to the nearest thing that saw anything. Queried on the
   host through a BVH over the seeds, and on the device through the same
   layout.
5. **Ring**: an outside camera joins part k when at least `--ring` (0.2) of
   the points it sees (and `--ring-min-points` of them) are owned by k. The
   ring sees the seam from outside, so both neighbouring parts learn it under
   the same supervision. It was 0.05, which let cameras that see a sliver of
   a part in and doubled the images per part.
6. **Seed points per part**: everything it owns, and a hash-stable
   `outside_seed_fraction` (0.2) of what its cameras see outside. A ring
   camera whose image shows another part's region needs some geometry there
   to explain the pixels, or it grows floaters inside; all of it would only
   grow splats the merge discards.
7. **Training** (`--partition file --partition-part k`): after parsing, the
   trainer keeps the part's frames (matched by image leaf, as `SparseEdit`
   matches them) and its seed points, for both the train and the eval split.
   Nothing else changes: the run's output is in the dataset's frame as always,
   and its `scene_transform.json` records any centering or rescale.
8. **Merge** (`merge_partition_splats`): each part's splats go back through
   its run's `world_from_train`; each one's short axis is pointed at the
   nearest camera that trained it and the field is asked which part owns that
   oriented point; the winners get their SH padded to the highest degree
   present and are concatenated. Hard ownership, no feathering.
9. **Region of interest while training**: a partitioned run hands its part's
   label region to the engine (`engine_set_region`), and `--roi-region` hands
   any region JSON. At every refine step `region_weight_tensor` evaluates the
   compiled program at every splat centre -- normal oriented by the nearest
   training camera -- and a splat outside draws for relocation and growth
   with `--roi-outside-weight` (1e-4) instead of 1, in both the revised and
   the MCMC path. `--roi-outside-opacity-decay` would also scale their
   opacity at every refine step; it is off (1), because the pixels those
   splats explained still had to be explained, and the parts grew splats in
   front of their cameras to do it (-2 dB after the merge, table above).
   What does work is not supervising those pixels at all: with
   `--roi-mask-pixels` (on) the trainer projects the partition's whole seed
   cloud into each training image, labels every quarter-resolution cell by
   the nearest point over a footprint that grows as points come closer (so a
   sparse near floor still hides what lies behind it), fills holes from
   neighbours, keeps what nothing covers, widens what is inside by a margin
   so the seam stays supervised, ANDs any existing mask, and writes the
   result under `<run>/roi_masks/` (`write_region_masks`). On Atrium a
   third of the pixels drop out.
   `region_parity` holds the device test to the host mirror. The region is
   in the dataset's frame and the splats in the training frame
   (`relative_scale * (p - center)`), so `setup_region` moves the compiled
   program by that similarity first (`RegionProgram::apply_similarity`).

## The files

`partition.json` beside `partition.bin`, both written by `write_partition`:

- JSON: `format`, `version`, `dataset` (absolute), `source`, `options`,
  `num_parts`, `frame_names` (image leaves) and `frame_parts` (core label per
  frame), `parts[k].ring` (frame indices), `cut_fraction`, `binary`.
- BIN: `SSPT` v2, then the `LabelField` (`SSLF` v1: seeds [n,4] and BVH
  nodes [m,8] as floats), the camera centres [N,3], then u8 owner per seed
  point in file order, then per part a u32 count and u32 point indices.

The trainer needs the JSON's frame lists, the BIN's point tables and the
field (its region of interest); the merge needs the field and the centres. A run's `config.json` carries `partition` and
`partition_part`, which is how `find_partition_runs` pairs runs with parts
without any naming convention.

## Regions (`data/Region.h`, `data/RegionProgram.h`)

The ownership field is one `Region` among several: `BoxRegion` (oriented),
`SphereRegion`, `HalfSpaceRegion`, `MeshRegion` (closed mesh, ray parity over
a BVH), `LabelRegion` (one label of a `LabelField`) and `CsgRegion` (union,
intersection, difference, complement). Every kind serializes through
`region_to_json` / `region_from_json`, and `contains_many` answers a whole
splat array in parallel on the host. Every kind but the mesh also compiles
(`compile_region`) to a post-order program of float4 nodes that
`shaders/region.slang` evaluates on both backends in one kernel, with the
label field's seeds and BVH as two more float4 arrays uploaded once per run.
A region built from the editor's selection tools would go through the same
seam. Constants and layouts live in the shader; `data/LabelField.cpp` and
`data/RegionProgram.cpp` are its host mirrors and `region_parity` pins them.

## The GUI

The Partition button on the dataset screen opens the panel over the parsed
reconstruction and computes nothing until Compute is pressed. "Queue parts in
Batch" saves the partition, then asks for the run's preset, splat cap, SH
degree and step count in a dialog; Queue is the confirmation, and if the
batch list still holds rows that have not finished it asks whether to clear
them first. With "merge once all have trained" ticked the list gets a final
Merge row (`BatchStage::Merge`), which finds the parts' runs under the runs
folder by their `config.json` and writes `<dataset>_merged_<stamp>.ply`
there. Rows whose tasks all finished are left unticked when the queue ends;
"Clear done rows" and "Clear list" both confirm first. While the Merge row
runs the screen follows it to the list, and when the queue ends on a merge
the merged model opens in the viewer.

In the trainer's engine view the region of interest is shown by greying
what lies outside it: each pixel's surface point, from the render's depth,
is tested against the region (every third pixel, on the host), and the
region's dashed silhouette is drawn over it. Before training, the preview
greys the seed points outside the region.

Regions are drawn as surfaces (`data/RegionMesh.h`: surface nets over the
inside test, crossings bisected onto the boundary, open where the region
leaves the box; `app/webviewer/RegionOverlay.h`): a translucent fill and a
dashed silhouette. The Partition panel shows every part's boundary in its
colour, or one part's when soloed. The trainer's viewport shows the run's
region of interest -- before training in the OpenGL preview, and during
training in the engine view, where `RenderWorker` rasterizes the mesh on the
host against the frame's depth so the fill and the outline fade behind
nearer geometry. The "region" switch beside "grid" hides it; pinhole views
only.

## Other ways to split, not taken

- Ground-plane tiles (VastGaussian, CityGS): the regions-first split with
  cells fixed to a ground grid. The principal-axis planes above reduce to it
  on a street and still work on several storeys.
- k-means on the points with Voronoi cells: compact, but the cells know
  nothing about which cameras they will need, and nothing about walls.
- A joint cut of the bipartite camera-point visibility graph, so a part's
  cameras and its owned points come out of one optimization instead of
  cameras first and ownership second.
- Soft ownership: keep splats a band past the seam from both sides with
  opacity scaled by distance to the boundary, or fine-tune the band jointly.

## Not done, on purpose

- No seam-band joint refinement and no opacity feathering. Judge the hard
  ownership cut on real captures first; either is a small addition on top of
  the merge if the seams warrant it.
- No shared appearance initialization (a short capped global pass whose
  per-image appearance state every part starts from). Colour seams from
  exposure drift between parts are the one failure mode this design does not
  address.
- Projection covisibility ignores occlusion, so a wall between two rooms does
  not separate them the way tracks would. Tracks win whenever they exist.
- The region test on the device has no mesh leaf; a mesh region is host-only
  until a triangle BVH joins the program.
