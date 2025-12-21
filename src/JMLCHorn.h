#pragma once
#include <vector>
#include "ExpansionLaw.h"

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
        double phiStopRad
    );

    std::vector<ProfilePoint> computeProfile() const;

private:
    double dl;
    double phiStop;
    double throatRadius;

    struct State {
        double x;
        double y;
        double phi;
        double S;
    };

    ExpansionLaw law;
};