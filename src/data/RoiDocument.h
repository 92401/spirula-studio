#pragma once

// A region of interest as the ROI editor holds it: shapes in order, each one
// added to, cut from or intersected with what the shapes above it made, in
// the dataset's own frame. Saved as <dataset>/roi/<name>.json -- a region JSON
// the trainer reads as it is, the list beside it under "editor" so the editor
// can open the file again. docs/notes/roi-editor.md.

#include "data/Json.h"
#include "data/Region.h"

#include <memory>
#include <string>
#include <vector>

namespace spirula {

enum class RoiShapeKind { Box = 0, Ellipsoid, Cylinder, Prism };
enum class RoiOp { Add = 0, Subtract, Intersect };

struct RoiShape {
    std::string name;
    RoiShapeKind kind = RoiShapeKind::Box;
    RoiOp op = RoiOp::Add;
    bool enabled = true;
    double center[3] = {0, 0, 0};
    double R[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};   // rows: the shape's axes
    // Box and ellipsoid: half extents; cylinder: the two radii and half its
    // height; prism: half its height in [2].
    double half[3] = {1, 1, 1};
    std::vector<double> polygon;   // prism: x,y pairs in its frame
    std::shared_ptr<Region> region() const;
};

struct RoiDocument {
    std::vector<RoiShape> shapes;
};

bool operator==(const RoiShape& a, const RoiShape& b);
inline bool operator!=(const RoiShape& a, const RoiShape& b) { return !(a == b); }
inline bool operator==(const RoiDocument& a, const RoiDocument& b) { return a.shapes == b.shapes; }
inline bool operator!=(const RoiDocument& a, const RoiDocument& b) { return !(a == b); }

// The enabled shapes folded top to bottom; a list that opens with a cut cuts
// it from all of space. Null when no shape is enabled.
std::shared_ptr<const Region> roi_region(const RoiDocument& doc);

// Throws std::runtime_error when there is nothing to save or no file to write.
void write_roi_file(const RoiDocument& doc, const std::string& path);
// The "editor" list when the file has one; otherwise the region itself, when
// it is a fold of shapes the list can hold.
bool read_roi_file(const std::string& path, RoiDocument& doc, std::string& error);
bool roi_from_region(const JsonValue& region, RoiDocument& doc, std::string& error);

std::string roi_folder(const std::string& dataset_dir);
// Every .json in roi_folder, in the order the trainer picks from: by name,
// ignoring case.
std::vector<std::string> list_roi_files(const std::string& dataset_dir);

// What --roi-region names: "" the first of list_roi_files, "off" nothing, a
// bare name that file in roi_folder, else a path, tried under the dataset
// first. Neither `path` nor `off`: the dataset has no region.
struct RoiChoice {
    std::string path;
    bool automatic = false;
    bool off = false;
};
RoiChoice resolve_roi_setting(const std::string& setting, const std::string& dataset_dir);

}  // namespace spirula
