#pragma once

#include <vector>
#include "ExpansionLaw.h"
#include "Constants.h"

struct ProfilePoint {
    double x;
    double y;
};

class JMLCHorn {
public:
    JMLCHorn(
        double fc,
        double throatDiameter,
        double T,
        double dl,
        double phiStopRad,
        double compressionAngleDeg
    );

    std::vector<ProfilePoint> computeProfile() const;

private:
    double dl;

    // angle d'arrêt du profil (radians)
    // 180° = PI
    // 270° = 1.5 * PI
    // 360° = 2.0 * PI
    double phiStop;

    double throatRadius;
    double phi0; // angle de sortie de la compression (radians)

    struct State {
        double x;
        double y;
        double phi;
        double S;
    };

    ExpansionLaw law;
};