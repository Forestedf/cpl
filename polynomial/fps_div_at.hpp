#pragma once

#include "polynomial.hpp"

// Bostan-Mori algorithm
template <typename T, typename Mul>
T fps_div_at(Polynomial<T, Mul> f, Polynomial<T, Mul> g, unsigned long long n) {
    const auto even = [](const Polynomial<T, Mul> &f) -> Polynomial<T, Mul> {
        Polynomial<T, Mul> g((f.size() + 1) / 2);
        for (int i = 0; i < g.size(); ++i) {
            g[i] = f[2 * i];
        }
        return g;
    };
    const auto odd = [](const Polynomial<T, Mul> &f) -> Polynomial<T, Mul> {
        Polynomial<T, Mul> g(f.size() / 2);
        for (int i = 0; i < g.size(); ++i) {
            g[i] = f[2 * i + 1];
        }
        return g;
    };
    assert(g.size() > 0 && g[0] != T(0));
    while (n > 0) {
        Polynomial<T, Mul> g_ = g;
        for (int i = 1; i < g_.size(); i += 2) {
            g_[i] = -g_[i];
        }
        g = even(g * g_);
        Polynomial<T, Mul> tmp_f = f * g_;
        if (n % 2 == 1) {
            f = odd(tmp_f);
        } else {
            f = even(tmp_f);
        }
        n /= 2;
    }
    if (f.size() == 0) {
        return T(0);
    } else {
        return f[0] / g[0];
    }
}