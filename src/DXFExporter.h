#pragma once
#include <string>
#include <vector>
#include "Units.h"

struct ProfilePoint;

namespace DXFExporter {

void exportProfileDXF(
    const std::vector<ProfilePoint>& profile,
    const std::string& filename,
    UnitSystem units
);

}