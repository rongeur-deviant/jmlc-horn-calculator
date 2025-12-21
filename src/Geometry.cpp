#include "Geometry.h"
#include "Constants.h"
#include <cmath>

std::vector<Point3D> revolveProfile(
    const std::vector<Point2D>& profile,
    int radialResolution
) {
    std::vector<Point3D> cloud;

    for (const auto& p : profile) {
        for (int i = 0; i < radialResolution; ++i) {
            double alpha = 2.0 * Constants::PI * i / radialResolution;

            cloud.push_back({
                p.x,
                p.r * std::cos(alpha),
                p.r * std::sin(alpha)
            });
        }
    }
    return cloud;
}