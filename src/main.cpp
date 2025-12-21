#include <iostream>
#include "Constants.h"
#include "JMLCHorn.h"
#include "Geometry.h"
#include "Exporter.h"

int main() {
    // ===== paramètres utilisateur =====
    double Fc = 500.0;              // Hz
    double throatDiameter = 0.025;  // m
    double mouthAngleDeg = 90.0;    // degrés
    double T = 0.85;
    int axialResolution = 300;
    int radialResolution = 120;

    // ===== conversions =====
    double throatRadius = throatDiameter / 2.0;
    double mouthAngleRad = mouthAngleDeg * Constants::PI / 180.0;

    // ===== calcul pavillon =====
    JMLCHorn horn(
        Fc,
        throatRadius,
        mouthAngleRad,
        T,
        axialResolution
    );

    auto profile = horn.computeProfile();
    auto cloud = revolveProfile(profile, radialResolution);

    // ===== export =====
    Exporter::exportProfileCSV(profile, "jmlc_profile.csv");
    Exporter::exportCSV(cloud, "jmlc_point_cloud.csv");

    std::cout << "JMLC horn generated.\n";
    std::cout << "Length: " << horn.getLength() << " m\n";

    return 0;
}