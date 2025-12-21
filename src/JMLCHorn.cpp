#include "JMLCHorn.h"
#include "ExpansionLaw.h"
#include "Constants.h"
#include <cmath>

JMLCHorn::JMLCHorn(
    double fc,
    double throatDiameter,
    double T,
    double dl_,
    double phiStopRad
)
    : dl(dl_),
      phiStop(phiStopRad)
{
    throatRadius = throatDiameter / 2.0;

    law.S0 = Constants::PI * throatRadius * throatRadius;
    law.m  = 4.0 * Constants::PI * fc / Constants::SPEED_OF_SOUND;
    law.T  = T;
}

std::vector<ProfilePoint> JMLCHorn::computeProfile() const {
    std::vector<ProfilePoint> profile;

    // initial state at throat
    State p0{};
    p0.x   = 0.0;
    p0.y   = throatRadius;
    p0.phi = 0.0;
    p0.S   = law.surface(0.0);

    State p1 = p0;
    p1.x += dl;
    p1.S  = law.surface(dl);

    std::vector<State> states;
    states.push_back(p0);
    states.push_back(p1);

    profile.push_back({p0.x, p0.y});
    profile.push_back({p1.x, p1.y});

    int i = 2;

    while (states.back().phi < phiStop) {
        const State& p_im1 = states[i - 1];
        const State& p_im2 = states[i - 2];

        double l = i * dl;

        State pi{};
        pi.S = law.surface(l);

        // surface compensatrice (eq. 22 JMLC PDF)
        double Si_star =
            std::pow(
                2.0 * std::sqrt(p_im1.S) - std::sqrt(p_im2.S),
                2.0
            );

        double Sii = pi.S - Si_star;

        double ri = p_im1.y;

        double dphi = Sii / (2.0 * Constants::PI * ri * dl);

        pi.phi = p_im1.phi + dphi;
        pi.x   = p_im1.x + dl * std::cos(pi.phi);
        pi.y   = p_im1.y + dl * std::sin(pi.phi);

        states.push_back(pi);
        profile.push_back({pi.x, pi.y});

        ++i;
    }

    return profile;
}