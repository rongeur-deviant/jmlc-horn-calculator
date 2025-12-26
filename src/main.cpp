#include "JMLCHorn.h"
#include "DXFExporter.h"
#include "Constants.h"
#include <iostream>

int main() {
    // ===== JMLC USER PARAMETERS =====
    // optimisé pour B&C DE250 + B&C 12HPL76

    double fc = 1000.0;             // Hz
    double throatDiameter = 0.0254; // m (1")
    double T = 0.6;                 // flare
    double dl = 0.001;              // m (1 mm)
    
    // angle d'arrêt du profil (RADIANS)
    // 180° = pi
    // 225° = 1.25 * pi
    // 270° = 1.5 * pi
    // 360° = 2.0 * pi
    double phiStop = 1.5 * Constants::PI;

    // angle de sortie de la compression (DE250 = 14.8°)
    double compressionAngleDeg = 14.8;

    // ===== JMLC HORN =====
    JMLCHorn horn(
        fc,
        throatDiameter,
        T,
        dl,
        phiStop,
        compressionAngleDeg
    );

    auto profile = horn.computeProfile();

    std::cout << "profile points: " << profile.size() << std::endl;

    // ===== DXF EXPORT =====
    DXFExporter::exportProfileDXF(
        profile,
        "jmlc_profile.dxf",
        UnitSystem::MILLIMETERS
    );

    std::cout << "DXF exported: jmlc_profile.dxf" << std::endl;

    return 0;
}