#pragma once

struct ExpansionLaw {
    double S0;   // throat area
    double m;    // 4*pi*fc/c
    double T;    // Le Cléac'h parameter

    double surface(double l) const;
};