#pragma once

#include "subset_convolution_internal.hpp"

#include <cassert>

template <typename T>
std::vector<T> _subset_conv_mul(const std::vector<T> &a, const std::vector<T> &b, int to) {
    std::vector<T> c(a.size(), T(0));
    for (int i = 0; i <= to; ++i) {
        for (int j = 0; j <= std::min((int) a.size() - i - 1, to); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}

template <typename T>
std::vector<T> subset_convolution(const std::vector<T> &a, const std::vector<T> &b) {
    int n = 0;
    while ((1 << n) < (int) a.size()) {
        ++n;
    }
    assert((int) a.size() == (1 << n));
    assert((int) b.size() == (1 << n));
    
    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n, a);
    std::vector<std::vector<T>> b_ = subset_convolution_internal::setps(n, b);
    for (int d = 0; d < n; ++ d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                subset_convolution_internal::add(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i) - 1);
                subset_convolution_internal::add(b_[i], b_[i ^ (1 << d)], __builtin_popcount(i) - 1);
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        a_[i] = _subset_conv_mul(a_[i], b_[i], __builtin_popcount(i));
    }
    for (int d = 0; d < n; ++ d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                subset_convolution_internal::sub(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i));
            }
        }
    }
    return subset_convolution_internal::rev_setps(n, a_);
}