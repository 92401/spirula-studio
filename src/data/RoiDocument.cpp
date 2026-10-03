// RoiDocument.cpp -- see RoiDocument.h.

#include "data/RoiDocument.h"

#include "data/JsonWrite.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

namespace spirula {

namespace {

const char* kKindNames[] = {"box", "ellipsoid", "cylinder", "prism"};
const char* kOpNames[] = {"add", "subtract", "intersect"};

template <size_t N>
int index_of(const char* const (&names)[N], const std::string& s) {
    for (size_t i = 0; i < N; i++)
        if (s == names[i]) return (int)i;
    return -1;
}

void write_vec(JsonWriter& w, const char* key, const double* v, size_t n) {
    w.key(key).array();
    for (size_t i = 0; i < n; i++) w.raw(json_number_exact(v[i]));
    w.end();
}

bool read_vec(const JsonValue& obj, const char* key, double* out, size_t n) {
    const JsonValue* a = obj.find(key);
    if (!a || !a->is_array() || a->arr.size() != n) return false;
    for (size_t i = 0; i < n; i++) out[i] = a->arr[i].as_double();
    return true;
}

void write_shape(JsonWriter& w, const RoiShape& s) {
    w.object();
    w.field("name", s.name);
    w.field("kind", kKindNames[(int)s.kind]);
    w.field("op", kOpNames[(int)s.op]);
    w.field("enabled", s.enabled);
    write_vec(w, "center", s.center, 3);
    write_vec(w, "rotation", s.R, 9);
    write_vec(w, "half", s.half, 3);
    if (s.kind == RoiShapeKind::Prism) write_vec(w, "polygon", s.polygon.data(), s.polygon.size());
    w.end();
}

bool read_shape(const JsonValue& v, RoiShape& s, std::string& error) {
    const JsonValue* kind = v.find("kind");
    const int k = kind ? index_of(kKindNames, kind->as_string()) : -1;
    if (k < 0) {
        error = "editor shape has no kind this build knows";
        return false;
    }
    s.kind = (RoiShapeKind)k;
    const JsonValue* op = v.find("op");
    s.op = (RoiOp)std::max(0, op ? index_of(kOpNames, op->as_string()) : 0);
    if (const JsonValue* n = v.find("name")) s.name = n->as_string();
    if (const JsonValue* e = v.find("enabled")) s.enabled = e->as_bool(true);
    if (!read_vec(v, "center", s.center, 3) || !read_vec(v, "half", s.half, 3)) {
        error = "editor shape needs center[3] and half[3]";
        return false;
    }
    read_vec(v, "rotation", s.R, 9);
    if (s.kind == RoiShapeKind::Prism) {
        const JsonValue* p = v.find("polygon");
        if (!p || !p->is_array() || p->arr.size() % 2 || p->arr.size() < 6) {
            error = "editor prism needs at least three x,y pairs";
            return false;
        }
        for (const JsonValue& x : p->arr) s.polygon.push_back(x.as_double());
    }
    return true;
}

// A region leaf as a shape; false for a kind the list has no shape for.
bool shape_of_leaf(const JsonValue& v, RoiOp op, RoiShape& s) {
    std::string err;
    std::unique_ptr<Region> r = region_from_json(v, "", err);
    if (!r) return false;
    s = RoiShape{};
    s.op = op;
    if (auto* b = dynamic_cast<const BoxRegion*>(r.get())) {
        s.kind = RoiShapeKind::Box;
        std::copy(b->center, b->center + 3, s.center);
        std::copy(b->half, b->half + 3, s.half);
        std::copy(b->R, b->R + 9, s.R);
    } else if (auto* e = dynamic_cast<const EllipsoidRegion*>(r.get())) {
        s.kind = RoiShapeKind::Ellipsoid;
        std::copy(e->center, e->center + 3, s.center);
        std::copy(e->half, e->half + 3, s.half);
        std::copy(e->R, e->R + 9, s.R);
    } else if (auto* sp = dynamic_cast<const SphereRegion*>(r.get())) {
        s.kind = RoiShapeKind::Ellipsoid;
        std::copy(sp->center, sp->center + 3, s.center);
        for (double& h : s.half) h = sp->radius;
    } else if (auto* c = dynamic_cast<const CylinderRegion*>(r.get())) {
        s.kind = RoiShapeKind::Cylinder;
        std::copy(c->center, c->center + 3, s.center);
        std::copy(c->half, c->half + 3, s.half);
        std::copy(c->R, c->R + 9, s.R);
    } else if (auto* p = dynamic_cast<const PrismRegion*>(r.get())) {
        s.kind = RoiShapeKind::Prism;
        std::copy(p->center, p->center + 3, s.center);
        std::copy(p->R, p->R + 9, s.R);
        s.half[0] = s.half[1] = 0;
        s.half[2] = p->half_height;
        s.polygon = p->polygon;
    } else {
        return false;
    }
    return true;
}

bool unfold(const JsonValue& v, RoiDocument& doc) {
    const std::string type = v.find("type") ? v.find("type")->as_string() : "";
    RoiShape s;
    if (type == "complement") {
        const JsonValue* kids = v.find("children");
        if (!doc.shapes.empty() || !kids || !kids->is_array() || kids->arr.size() != 1 ||
            !shape_of_leaf(kids->arr[0], RoiOp::Subtract, s))
            return false;
        doc.shapes.push_back(s);
        return true;
    }
    RoiOp op;
    if (type == "union") op = RoiOp::Add;
    else if (type == "difference") op = RoiOp::Subtract;
    else if (type == "intersection") op = RoiOp::Intersect;
    else {
        if (!shape_of_leaf(v, RoiOp::Add, s)) return false;
        doc.shapes.push_back(s);
        return true;
    }
    const JsonValue* kids = v.find("children");
    if (!kids || !kids->is_array() || kids->arr.empty() || !unfold(kids->arr[0], doc)) return false;
    for (size_t i = 1; i < kids->arr.size(); i++) {
        if (!shape_of_leaf(kids->arr[i], op, s)) return false;
        doc.shapes.push_back(s);
    }
    return true;
}

bool less_ignoring_case(const std::string& a, const std::string& b) {
    const size_t n = std::min(a.size(), b.size());
    for (size_t i = 0; i < n; i++) {
        const int x = std::tolower((unsigned char)a[i]), y = std::tolower((unsigned char)b[i]);
        if (x != y) return x < y;
    }
    return a.size() != b.size() ? a.size() < b.size() : a < b;
}

}  // namespace

std::shared_ptr<Region> RoiShape::region() const {
    switch (kind) {
        case RoiShapeKind::Box: {
            auto r = std::make_shared<BoxRegion>();
            std::copy(center, center + 3, r->center);
            std::copy(half, half + 3, r->half);
            std::copy(R, R + 9, r->R);
            return r;
        }
        case RoiShapeKind::Ellipsoid: {
            auto r = std::make_shared<EllipsoidRegion>();
            std::copy(center, center + 3, r->center);
            std::copy(half, half + 3, r->half);
            std::copy(R, R + 9, r->R);
            return r;
        }
        case RoiShapeKind::Cylinder: {
            auto r = std::make_shared<CylinderRegion>();
            std::copy(center, center + 3, r->center);
            std::copy(half, half + 3, r->half);
            std::copy(R, R + 9, r->R);
            return r;
        }
        case RoiShapeKind::Prism: {
            auto r = std::make_shared<PrismRegion>();
            std::copy(center, center + 3, r->center);
            std::copy(R, R + 9, r->R);
            r->half_height = half[2];
            r->polygon = polygon;
            return r;
        }
    }
    return nullptr;
}

bool operator==(const RoiShape& a, const RoiShape& b) {
    return a.name == b.name && a.kind == b.kind && a.op == b.op && a.enabled == b.enabled &&
           std::equal(a.center, a.center + 3, b.center) && std::equal(a.R, a.R + 9, b.R) &&
           std::equal(a.half, a.half + 3, b.half) && a.polygon == b.polygon;
}

std::shared_ptr<const Region> roi_region(const RoiDocument& doc) {
    std::shared_ptr<const Region> acc;
    std::shared_ptr<CsgRegion> open;   // acc itself, while more of its op can join it
    for (const RoiShape& s : doc.shapes) {
        if (!s.enabled || (s.kind == RoiShapeKind::Prism && s.polygon.size() < 6)) continue;
        std::shared_ptr<const Region> leaf = s.region();
        if (!acc) {
            if (s.op == RoiOp::Subtract) {
                auto c = std::make_shared<CsgRegion>();
                c->op = CsgOp::Complement;
                c->children = {leaf};
                acc = c;
            } else {
                acc = leaf;
            }
            continue;
        }
        const CsgOp op = s.op == RoiOp::Add ? CsgOp::Union
                         : s.op == RoiOp::Subtract ? CsgOp::Difference : CsgOp::Intersection;
        if (open && open->op == op) {
            open->children.push_back(leaf);
        } else {
            open = std::make_shared<CsgRegion>();
            open->op = op;
            open->children = {acc, leaf};
            acc = open;
        }
    }
    return acc;
}

void write_roi_file(const RoiDocument& doc, const std::string& path) {
    const std::shared_ptr<const Region> r = roi_region(doc);
    if (!r) throw std::runtime_error("the region of interest has no enabled shape");
    JsonWriter w;
    w.object();
    w.field("type", r->kind());
    r->write_json(w);
    w.key("editor").object();
    w.field("version", 1);
    w.key("shapes").array();
    for (const RoiShape& s : doc.shapes) write_shape(w, s);
    w.end();
    w.end();
    w.end();
    std::error_code ec;
    const fs::path target(path);
    if (target.has_parent_path()) fs::create_directories(target.parent_path(), ec);
    const std::string tmp = path + ".tmp";
    FILE* f = std::fopen(tmp.c_str(), "wb");
    if (!f) throw std::runtime_error("cannot write " + path);
    const std::string text = w.str() + "\n";
    const bool ok = std::fwrite(text.data(), 1, text.size(), f) == text.size();
    if (std::fclose(f) != 0 || !ok) {
        fs::remove(tmp, ec);
        throw std::runtime_error("cannot write " + path);
    }
    fs::rename(tmp, target, ec);
    if (ec) {
        fs::remove(tmp, ec);
        throw std::runtime_error("cannot write " + path + ": " + ec.message());
    }
}

bool roi_from_region(const JsonValue& region, RoiDocument& doc, std::string& error) {
    doc = RoiDocument{};
    if (!unfold(region, doc)) {
        doc = RoiDocument{};
        error = "the region is not a list of boxes, ellipsoids, cylinders and outlines";
        return false;
    }
    return true;
}

bool read_roi_file(const std::string& path, RoiDocument& doc, std::string& error) {
    doc = RoiDocument{};
    JsonValue v;
    try {
        v = json_parse_file(path);
    } catch (const std::exception& e) {
        error = e.what();
        return false;
    }
    const JsonValue* ed = v.find("editor");
    const JsonValue* shapes = ed ? ed->find("shapes") : nullptr;
    if (!shapes || !shapes->is_array()) return roi_from_region(v, doc, error);
    for (const JsonValue& sv : shapes->arr) {
        RoiShape s;
        if (!read_shape(sv, s, error)) {
            doc = RoiDocument{};
            return false;
        }
        doc.shapes.push_back(std::move(s));
    }
    return true;
}

std::string roi_folder(const std::string& dataset_dir) {
    return (fs::path(dataset_dir) / "roi").string();
}

std::vector<std::string> list_roi_files(const std::string& dataset_dir) {
    std::vector<std::string> out;
    std::error_code ec;
    for (const fs::directory_entry& e : fs::directory_iterator(roi_folder(dataset_dir), ec)) {
        if (!e.is_regular_file(ec)) continue;
        std::string ext = e.path().extension().string();
        for (char& c : ext) c = (char)std::tolower((unsigned char)c);
        if (ext == ".json") out.push_back(e.path().lexically_normal().string());
    }
    std::sort(out.begin(), out.end(), [](const std::string& a, const std::string& b) {
        return less_ignoring_case(fs::path(a).filename().string(), fs::path(b).filename().string());
    });
    return out;
}

RoiChoice resolve_roi_setting(const std::string& setting, const std::string& dataset_dir) {
    RoiChoice c;
    std::string low = setting;
    for (char& ch : low) ch = (char)std::tolower((unsigned char)ch);
    // Not "none": the command line reads that as unset.
    if (low == "off") {
        c.off = true;
        return c;
    }
    if (setting.empty()) {
        const std::vector<std::string> files = list_roi_files(dataset_dir);
        if (!files.empty()) {
            c.path = files.front();
            c.automatic = true;
        }
        return c;
    }
    std::error_code ec;
    const fs::path p(setting);
    if (p.is_relative() && !dataset_dir.empty()) {
        const fs::path in_data = fs::path(dataset_dir) / p;
        if (fs::is_regular_file(in_data, ec)) {
            c.path = in_data.string();
            return c;
        }
        if (!p.has_parent_path()) {
            fs::path named = fs::path(roi_folder(dataset_dir)) / p;
            if (!named.has_extension()) named += ".json";
            if (fs::is_regular_file(named, ec)) {
                c.path = named.string();
                return c;
            }
        }
    }
    c.path = setting;
    return c;
}

}  // namespace spirula
