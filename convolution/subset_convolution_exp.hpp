#pragma once

#include "subset_convolution.hpp"

template <typename T>
std::vector<T> subset_convolution_exp(const std::vector<T> &a) {
    int n = 0;
    while ((1 << n) < (int)a.size()) {
        ++n;
    }
    assert((int)a.size() == (1 << n));
    assert(a[0] == T(0));
    
    std::vector<T> b;
    b.reserve(1 << n);
    b.push_back(T(1));
    for (int i = 0; i < n; ++i) {
        std::vector<T> c(a.begin() + (1 << i), a.begin() + (2 << i));
        std::vector<T> sc = subset_convolution(b, c);
        for (int j = 0; j < (1 << i); ++j) {
            b.push_back(sc[j]);
        }
    }
    return b;
}