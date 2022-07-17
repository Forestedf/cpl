#pragma once

#include "subset_convolution_internal.hpp"

#include <cassert>

template <typename T>
std::vector<T> _subset_conv_exp(const std::vector<T> &a, int to) {
    std::vector<T> b(a.size());
    b[0] = T(1);
    for (int i = 0; i < (int) a.size() - 1; ++i) {
        for (int j = 0; j <= std::min(i, to - 1); ++j) {
            b[i + 1] += T(j + 1) * a[j + 1] * b[i - j];
        }
        b[i + 1] /= T(i + 1);
    }
    return b;
}

template <typename T>
std::vector<T> subset_convolution_exp(const std::vector<T> &a) {
    int n = 0;
    while ((1 << n) < (int) a.size()) {
        ++n;
    }
    assert((int) a.size() == (1 << n));
    assert(a[0] == T(0));
    
    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n, a);
    for (int d = 0; d < n; ++ d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                subset_convolution_internal::add(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i) - 1);
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        a_[i] = _subset_conv_exp(a_[i], __builtin_popcount(i));
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

template <typename T>
T subset_convolution_exp_1point(const std::vector<T> &a) {
    int n = 0;
    while ((1 << n) < (int) a.size()) {
        ++n;
    }
    assert((int) a.size() == (1 << n));
    assert(a[0] == T(0));
    
    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n, a);
    for (int d = 0; d < n; ++ d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                subset_convolution_internal::add(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i) - 1);
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        a_[i] = _subset_conv_exp(a_[i], __builtin_popcount(i));
    }
    T ans(0);
    for (int i = 0; i < (1 << n); ++i) {
        ans += a_[i][n] * ((n - __builtin_popcount(i)) % 2 ? T(-1) : T(1));
    }
    return ans;
}