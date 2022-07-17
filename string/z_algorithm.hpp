#pragma once

#include <vector>

template <typename Cont>
std::vector<int> z_algorithm(const Cont &s) {
    if (s.empty()) {
        return std::vector<int>(0);
    }
    std::vector<int> z(s.size());
    z[0] = static_cast<int>(s.size());
    int i = 1, j = 0;
    while (i < static_cast<int>(s.size())) {
        while (i + j < static_cast<int>(s.size()) && s[i + j] == s[j]) {
            ++j;
        }
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (k < j && k + z[k] < j) {
            z[i + k] = z[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return z;
}

