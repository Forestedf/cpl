#pragma once

#include <algorithm>
#include <utility>
#include <vector>

template <typename T, typename Binom, typename Mul>
std::vector<T> taylor_shift(std::vector<T> f, const T &c, const Binom &binom) {
    int n = (int) f.size();
    for (int i = 0; i < n; ++i) {
        f[i] *= binom.fact(i);
    }
    std::reverse(f.begin(), f.end());
    std::vector<T> g(n);
    T pw(1);
    for (int i = 0; i < n; ++i) {
        g[i] = pw * binom.inv_fact(i);
        pw *= c;
    }
    std::vector<T> h = Mul::mul(std::move(f), std::move(g));
    h.resize(n);
    std::reverse(h.begin(), h.end());
    for (int i = 0; i < n; ++i) {
        h[i] *= binom.inv_fact(i);
    }
    return h;
}