#pragma once

#include <vector>
#include <cassert>

template <typename T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
    int n = 0;
    while ((1 << n) < (int) a.size()) {
        ++n;
    }
    assert((int) a.size() == (1 << n));
    assert((int) b.size() == (1 << n));
    
    for (int d = 0; d < n; ++d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                a[i ^ (1 << d)] += a[i];
                b[i ^ (1 << d)] += b[i];
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        a[i] *= b[i];
    }
    for (int d = 0; d < n; ++d) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << d)) {
                a[i ^ (1 << d)] -= a[i];
            }
        }
    }
    
    return a;
}