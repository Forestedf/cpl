#pragma once

template <typename T>
bool ith_bit(T n, T i) {
    return (n & ((T) 1 << i)) != 0;
}

int popcount(int x) {
    return __builtin_popcount(x);
}
long long popcount(long long x) {
    return __builtin_popcountll(x);
}

// x must not be 0
int clz(int x) {
    return __builtin_clz(x);
}
long long clz(long long x) {
    return __builtin_clzll(x);
}

// x must not be 0
int ctz(int x) {
    return __builtin_ctz(x);
}
long long ctz(long long x) {
    return __builtin_ctzll(x);
}

template <typename T>
T mask_n(T x, T n) {
    T mask = ((T) 1 << n) - 1;
    return x & mask;
}