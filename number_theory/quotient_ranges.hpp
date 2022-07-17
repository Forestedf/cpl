#pragma once

#include <vector>
#include <tuple>
#include <cassert>

// l, r, v: i \in (l, r] \implies n // i = v
template <typename T>
std::vector<std::tuple<T, T, T>> quotient_ranges(T n) {
    assert(n >= 1);
    std::vector<std::tuple<T, T, T>> ranges;
    for (T q = n; q > 0; q = n / (n / q + 1)) {
        ranges.emplace_back(n / (q + 1), n / q, q);
    }
    return ranges;
}

