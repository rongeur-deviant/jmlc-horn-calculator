#include "JMLCHorn.h"
#include "Constants.h"
#include <iostream>
#include <cmath>

JMLCHorn::JMLCHorn(
    double fc,
    double throatDiameter,
    double T,
    double dl_,
    double phiStopRad,
    double compressionAngleDeg
)
    : dl(dl_),
      phiStop(phiStopRad)
{
    throatRadius = throatDiameter / 2.0;

    // angle de sortie de la compression (phi0)
    phi0 = compressionAngleDeg * Constants::PI / 180.0;

    law.S0 = Constants::PI * throatRadius * throatRadius;
    law.m  = 4.0 * Constants::PI * fc / Constants::SPEED_OF_SOUND;
    law.T  = T;
}

std::vector<ProfilePoint> JMLCHorn::computeProfile() const {
    std::vector<ProfilePoint> profile;
    std::vector<State> states;

    // ----- état initial à la gorge -----
    State p0{};
    p0.x   = 0.0;
    p0.y   = throatRadius;
    p0.phi = phi0;
    p0.S   = law.surface(0.0);

    // ----- premier pas (géométriquement cohérent) -----
    State p1{};
    p1.phi = p0.phi;
    p1.x   = p0.x + dl * std::cos(p0.phi);
    p1.y   = p0.y + dl * std::sin(p0.phi);
    p1.S   = law.surface(dl);

    states.push_back(p0);
    states.push_back(p1);

    profile.push_back({p0.x, p0.y});
    profile.push_back({p1.x, p1.y});

    int i = 2;

    // ----- boucle JMLC -----
    while (states.back().phi < phiStop) {
        const State& p_im1 = states[i - 1];
        const State& p_im2 = states[i - 2];

        double l = i * dl;

        State pi{};
        pi.S = law.surface(l);

        // surface compensatrice (eq. 47 PDF JMLC)
        double Si_star =
            std::pow(
                2.0 * std::sqrt(p_im1.S) - std::sqrt(p_im2.S),
                2.0
            );

        double Sii = pi.S - Si_star;

        // rayon effectif (eq. 23 PDF)
        double ri = p_im1.y + dl * std::sin(p_im1.phi);

        // incrément angulaire (eq. 24 PDF)
        double dphi = Sii / (2.0 * Constants::PI * ri * dl);

        pi.phi = p_im1.phi + dphi;
        pi.x   = p_im1.x + dl * std::cos(pi.phi);
        pi.y   = p_im1.y + dl * std::sin(pi.phi);

        states.push_back(pi);
        profile.push_back({pi.x, pi.y});

        ++i;

        // sécurité anti-bug
        if (i > 200000) break;
    }

    if (!profile.empty() && profile.back().x < 0.1) {
        std::cerr << "WARNING: horn length < 100 mm (check parameters)\n";  
    }

    return profile;
}