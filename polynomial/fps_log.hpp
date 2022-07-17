#pragma once

#include "fps_inv.hpp"

template <typename T, typename Mul>
Polynomial<T, Mul> fps_log(const Polynomial<T, Mul> &f, int sz = -1) {
    const std::vector<T> &coeff = f.vec();
    assert(!coeff.empty() && coeff[0] == T(1));
    if (sz == -1) {
        sz = (int) coeff.size();
    }
    assert(sz >= 0);
    if (sz == 0) {
        return Polynomial<T, Mul>();
    }
    return (f.diff().pre(sz - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();
}