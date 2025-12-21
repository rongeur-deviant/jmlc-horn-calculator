#pragma once
#include <vector>

struct Point2D {
    double x;
    double r;
};

struct Point3D {
    double x;
    double y;
    double z;
};

std::vector<Point3D> revolveProfile(
    const std::vector<Point2D>& profile,
    int radialResolution
);