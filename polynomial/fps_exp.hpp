#pragma once

#include "polynomial.hpp"

template <typename T, typename Mul>
Polynomial<T, Mul> fps_exp(const Polynomial<T, Mul> &h, int sz = -1) {
    const std::vector<T> &coeff = h.vec();
    assert(!coeff.empty() && coeff[0] == T(0));
    if (sz == -1) {
        sz = (int) coeff.size();
    }
    assert(sz >= 0);
    std::vector<T> f({T(1)});
    std::vector<T> g({T(1)});
    std::vector<T> dft_f_({T(1), T(1)});
    
    while (f.size() < sz) {
        int n = f.size();
        
        // F_{2n}(g_0)
        std::vector<T> dft_g_2 = g;
        dft_g_2.resize(2 * n, T(0));
        Mul::dft(dft_g_2);
        
        // \delta
        std::vector<T> delta(n, T(0));
        for (int i = 0; i < n; ++i) {
            delta[i] = dft_f_[i] * dft_g_2[i];
        }
        Mul::idft(delta);
        delta.resize(2 * n);
        for (int i = 0; i < n; ++i) {
            std::swap(delta[i], delta[n + i]);
        }
        delta[n] -= T(1);
        
        // F_n(D(f_0))
        std::vector<T> dft_d_f(n, T(0));
        for (int i = 0; i < n - 1; ++i) {
            dft_d_f[i] = T(i + 1) * f[i + 1];
        }
        Mul::dft(dft_d_f);
        
        // D(f_0) g_0
        std::vector<T> d_f_g(n, T(0));
        for (int i = 0; i < n; ++i) {
            d_f_g[i] = dft_d_f[i] * dft_g_2[i];
        }
        Mul::idft(d_f_g);
        d_f_g.resize(2 * n, T(0));
        for (int i = 0; i < n - 1; ++i) {
            T tmp = T(i + 1) * h.at(i + 1);
            d_f_g[n + i] = d_f_g[i] - tmp;
            d_f_g[i] = tmp;
        }
        
        // \delta D(h_0)
        std::vector<T> dft_delta = delta;
        Mul::dft(dft_delta);
        std::vector<T> delta_d_h(2 * n);
        for (int i = 0; i < n - 1; ++i) {
            delta_d_h[i] = T(i + 1) * h.at(i + 1);
        }
        Mul::dft(delta_d_h);
        for (int i = 0; i < 2 * n; ++i) {
            delta_d_h[i] *= dft_delta[i];
        }
        Mul::idft(delta_d_h);
        std::fill(delta_d_h.begin(), delta_d_h.begin() + n, T(0));
        
        // \epsilon
        std::vector<T> eps = std::move(d_f_g);
        for (int i = 0; i < 2 * n; ++i) {
            eps[i] -= T(i + 1) * h.at(i + 1) + delta_d_h[i];
        }
        for (int i = 2 * n - 1; i > 0; --i) {
            eps[i] = eps[i - 1] / T(i);
        }
        eps[0] = T(0);
        
        // \epsilon f_0
        std::vector<T> dft_eps = eps;
        Mul::dft(dft_eps);
        std::vector<T> eps_f(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            eps_f[i] = dft_eps[i] * dft_f_[i];
        }
        Mul::idft(eps_f);
        std::fill(eps_f.begin(), eps_f.begin() + n - 1, T(0));
        
        // update f
        f.resize(2 * n, T(0));
        for (int i = 0; i < 2 * n; ++i) {
            f[i] -= eps_f[i];
        }
        
        if (f.size() >= sz) {
            break;
        }
        
        // update F_{2n}(f)
        dft_f_ = f;
        dft_f_.resize(4 * n);
        Mul::dft(dft_f_);
        
        // update g
        std::vector<T> fg(dft_f_.begin(), dft_f_.begin() + 2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            fg[i] *= dft_g_2[i];
        }
        Mul::idft(fg);
        std::fill(fg.begin(), fg.begin() + n, T(0));
        Mul::dft(fg);
        for (int i = 0; i < 2 * n; ++i) {
            fg[i] *= dft_g_2[i];
        }
        Mul::idft(fg);
        g.resize(2 * n);
        for (int i = n; i < 2 * n; ++i) {
            g[i] = -fg[i];
        }
    }
    
    f.resize(sz);
    return Polynomial<T, Mul>(f);
}