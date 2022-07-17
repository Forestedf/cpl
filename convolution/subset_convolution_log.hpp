#pragma once

#include "subset_convolution_internal.hpp"

#include <cassert>

template <typename T>
std::vector<T> _subset_conv_log(const std::vector<T> &a, int to) {
    std::vector<T> b(a.size());
    for (int i = 1; i < (int) a.size(); ++i) {
        b[i] = a[i] * T(i);
        for (int j = 1; j <= std::min(to, i); ++j) {
            b[i] -= a[j] * b[i - j];
        }
    }
    for (int i = 1; i < (int) a.size(); ++i) {
        b[i] /= T(i);
    }
    return b;
}

template <typename T>
std::vector<T> subset_convolution_log(const std::vector<T> &a) {
    int n = 0;
    while ((1 << n) < (int) a.size()) {
        ++n;
    }
    assert((int) a.size() == (1 << n));
    assert(a[0] == T(1));
    
    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n, a);
    for (int d = 0; d < n; ++ d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                subset_convolution_internal::add(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i) - 1);
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        a_[i] = _subset_conv_log(a_[i], __builtin_popcount(i));
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
