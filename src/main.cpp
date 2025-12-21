#include "JMLCHorn.h"
#include "DXFExporter.h"
#include "Constants.h"
#include <iostream>

int main() {
    // ===== USER PARAMETERS =====
    double fc = 500.0;            // Hz
    double throatDiameter = 0.025; // m
    double T = 0.8;
    double dl = 0.001;            // axial step (m)
    double phiStop = 1.1 * Constants::PI; // ~198°

    JMLCHorn horn(
        fc,
        throatDiameter,
        T,
        dl,
        phiStop
    );

    auto profile = horn.computeProfile();

    std::cout << "profile points : " << profile.size() << std::endl;

    DXFExporter::exportProfileDXF(profile, "jmlc_profile.dxf");

    std::cout << "DXF exported : jmlc_profile.dxf\n";

    return 0;
}