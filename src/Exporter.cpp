#include "Exporter.h"
#include <fstream>

namespace Exporter {

void exportCSV(
    const std::vector<Point3D>& cloud,
    const std::string& filename
) {
    std::ofstream file(filename);
    file << "x,y,z\n";

    for (const auto& p : cloud) {
        file << p.x << "," << p.y << "," << p.z << "\n";
    }
}

void exportProfileCSV(
    const std::vector<Point2D>& profile,
    const std::string& filename
) {
    std::ofstream file(filename);
    file << "x,r\n";

    for (const auto& p : profile) {
        file << p.x << "," << p.r << "\n";
    }
}

}