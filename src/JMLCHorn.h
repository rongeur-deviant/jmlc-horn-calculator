#pragma once
#include <vector>
#include "Geometry.h"

class JMLCHorn {
public:
    JMLCHorn(
        double cutoffFrequency,
        double throatRadius,
        double mouthAngle,
        double T,
        int axialResolution
    );

    std::vector<Point2D> computeProfile() const;

    double getLength() const;

private:
    double Fc;
    double r0;
    double theta;
    double Tparam;
    int N;

    double length;
};