#pragma once
#include <string>
#include <vector>

struct ProfilePoint;

namespace DXFExporter {
    void exportProfileDXF(
        const std::vector<ProfilePoint>& profile,
        const std::string& filename
    );
}