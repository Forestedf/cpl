#pragma once

#include <vector>
#include <numeric>

class LinearSieve {
    std::vector<int> mpf;
    std::vector<int> ps;
    
public:
    LinearSieve(int n) : mpf(n + 1) {
        std::iota(mpf.begin(), mpf.end(), 0);
        for (int i = 2; i <= n; ++i) {
            if (mpf[i] == i) {
                ps.push_back(i);
            }
            for (int p : ps) {
                if (p > mpf[i] || i * p > n) {
                    break;
                }
                mpf[p * i] = p;
            }
        }
    }
    
    int min_prime_factor(int n) const {
        assert(n >= 2 && n < static_cast<int>(mpf.size()));
        return mpf[n];
    }
    
    std::vector<int> primes() const {
        return ps;
    }
    
    bool is_prime(int n) const {
        assert(n < static_cast<int>(mpf.size()));
        return n >= 2 && mpf[n] == n;
    }
    
    std::vector<std::pair<int, int>> factorize(int n) const {
        assert(n > 0 && n < mpf.size());
        std::vector<std::pair<int, int>> ret;
        while (n > 1) {
            int p = mpf[n];
            int ex = 0;
            while (n % p == 0) {
                n /= p;
                ++ex;
            }
            ret.emplace_back(p, ex);
        }
        return ret;
    }
};

