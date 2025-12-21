#include "ExpansionLaw.h"
#include <cmath>

double ExpansionLaw::surface(double l) const {
    double u = m * l / 2.0;
    double v = std::cosh(u) + T * std::sinh(u);
    return S0 * v * v;
}