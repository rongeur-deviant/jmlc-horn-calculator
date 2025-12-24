#include "JMLCHorn.h"
#include "DXFExporter.h"
#include "Constants.h"
#include <iostream>

int main() {
    // ===== JMLC USER PARAMETERS =====
    // optimisé ici pour B&C DE250 (+ B&C 12HPL76)
    double fc = 1200.0;                    // Hz
    double throatDiameter = 0.0254;        // m (1", standard)
    double T = 0.80;                       // flare doux / progressif
    double dl = 0.001;                     // m (1 mm → OK impression / export)
    double phiStop = 1.25 * Constants::PI; // ~225°

    JMLCHorn horn(
        fc,
        throatDiameter,
        T,
        dl,
        phiStop
    );

    auto profile = horn.computeProfile();

    std::cout << "profile points : " << profile.size() << std::endl;

    DXFExporter::exportProfileDXF(
    profile,
    "jmlc_profile.dxf",
    UnitSystem::MILLIMETERS
    );

    std::cout << "DXF exported : jmlc_profile.dxf\n";

    return 0;
}