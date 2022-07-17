#pragma once

#include "fps_log.hpp"
#include "fps_exp.hpp"

template <typename T, typename Mul>
Polynomial<T, Mul> fps_pow(const Polynomial<T, Mul> &h, unsigned long long m, int sz = -1) {
    const std::vector<T> &coeff = h.vec();
    if (sz == -1) {
        sz = (int) coeff.size();
    }
    assert(sz >= 0);
    
    if (m == 0) {
        std::vector<T> a(sz, T(0));
        if (sz >= 1) {
            a[0] = T(1);
        }
        return Polynomial<T, Mul>(a);
    }
    
    int ord = (int) coeff.size();
    for (int i = 0; i < (int) coeff.size(); ++i) {
        if (coeff[i] != T(0)) {
            ord = i;
            break;
        }
    }
    if (ord == (int) coeff.size() || (unsigned long long) ord >= ((unsigned long long) sz + m - 1) / m) {
        return Polynomial<T, Mul>(sz);
    }
    int zero = (int) (ord * m);
    int nonzero = sz - zero;
    
    Polynomial<T, Mul> f(std::vector<T>(coeff.begin() + ord, coeff.end()));
    T cf = f[0];
    T cf_inv = cf.inv();
    for (int i = 0; i < f.size(); ++i) {
        f[i] *= cf_inv;
    }
    f = fps_log(f, nonzero); //f.log(nonzero);
    T tm = T(m);
    for (int i = 0; i < f.size(); ++i) {
        f[i] *= tm;
    }
    f = fps_exp(f);
    T cf_m = cf.pow(m);
    for (int i = 0; i < f.size(); ++i) {
        f[i] *= cf_m;
    }
    std::vector<T> ans = f.vec();
    ans.insert(ans.begin(), zero, T(0));
    return Polynomial<T, Mul>(ans);
}