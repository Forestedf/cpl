#pragma once

#include <vector>
#include <algorithm>

namespace subset_convolution_internal {

template <typename T>
void add(std::vector<T> &a, const std::vector<T> &b, int to) {
    for (int i = 0; i <= to; ++i) {
        a[i] += b[i];
    }
}

template <typename T>
void sub(std::vector<T> &a, const std::vector<T> &b, int from) {
    for (int i = from; i < (int) a.size(); ++i) {
        a[i] -= b[i];
    }
}

template <typename T>
std::vector<std::vector<T>> setps(int n, const std::vector<T> &a) {
    std::vector<std::vector<T>> sps(1 << n, std::vector<T>(n + 1, T(0)));
    for (int i = 0; i < (1 << n); ++i) {
        sps[i][__builtin_popcount(i)] = a[i];
    }
    return sps;
}

template <typename T>
std::vector<T> rev_setps(int n, const std::vector<std::vector<T>> &sps) {
    std::vector<T> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        a[i] = sps[i][__builtin_popcount(i)];
    }
    return a;
}

} // namespace subset_convolution_internal