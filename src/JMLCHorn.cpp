#include "JMLCHorn.h"
#include "Constants.h"
#include <cmath>

JMLCHorn::JMLCHorn(
    double cutoffFrequency,
    double throatRadius,
    double mouthAngle,
    double T,
    int axialResolution
)
    : Fc(cutoffFrequency),
      r0(throatRadius),
      theta(mouthAngle),
      Tparam(T),
      N(axialResolution)
{
    length = Constants::SPEED_OF_SOUND / (2.0 * Constants::PI * Fc);
}

double JMLCHorn::getLength() const {
    return length;
}

std::vector<Point2D> JMLCHorn::computeProfile() const {
    std::vector<Point2D> profile;

    for (int i = 0; i <= N; ++i) {
        double phi = theta * i / N;
        if (phi < 1e-6) phi = 1e-6;

        double r = r0 * (std::sin(Tparam * phi) /
                        (Tparam * std::sin(phi)));

        double x = length *
                   (1.0 - std::tan(phi / 2.0) /
                   std::tan(theta / 2.0));

        profile.push_back({x, r});
    }
    return profile;
}