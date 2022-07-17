#pragma once

#include "polynomial.hpp"

template <typename T, typename Mul>
Polynomial<T, Mul> fps_inv(const Polynomial<T, Mul> &f, int sz = -1) {
    const std::vector<T> &coeff = f.vec();
    assert(!coeff.empty() && coeff[0] != T(0));
    if (sz == -1) {
        sz = (int) coeff.size();
    }
    assert(sz >= 0);
    std::vector<T> g({T(1) / coeff[0]});
    while ((int) g.size() < sz) {
        std::vector<T> fg;
        if (2 * g.size() <= (int) coeff.size()) {
            fg = std::vector<T>(coeff.begin(), coeff.begin() + 2 * g.size());
        } else {
            fg = coeff;
            fg.resize(2 * g.size());
        }
        Mul::dft(fg);
        std::vector<T> dft_g = g;
        dft_g.resize(2 * g.size(), T(0));
        Mul::dft(dft_g);
        for (int i = 0; i < (int) 2 * g.size(); ++i) {
            fg[i] *= dft_g[i];
        }
        Mul::idft(fg);
        std::fill(fg.begin(), fg.begin() + g.size(), T(0));
        Mul::dft(fg);
        for (int i = 0; i < (int) 2 * g.size(); ++i) {
            fg[i] *= dft_g[i];
        }
        Mul::idft(fg);
        g.resize(2 * g.size());
        for (int i = (int) g.size() / 2; i < g.size(); ++i) {
            g[i] = -fg[i];
        }
    }
    g.resize(sz);
    return Polynomial<T, Mul>(g);
}