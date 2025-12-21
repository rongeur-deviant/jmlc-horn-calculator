#pragma once
#include <string>
#include <vector>
#include "Geometry.h"

namespace Exporter {
    void exportCSV(
        const std::vector<Point3D>& cloud,
        const std::string& filename
    );

    void exportProfileCSV(
        const std::vector<Point2D>& profile,
        const std::string& filename
    );
}