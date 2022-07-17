---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/linear_sieve.hpp\"\n\n#include <vector>\n\
    #include <numeric>\n\nclass LinearSieve {\n    std::vector<int> mpf;\n    std::vector<int>\
    \ ps;\n    \npublic:\n    LinearSieve(int n) : mpf(n + 1) {\n        std::iota(mpf.begin(),\
    \ mpf.end(), 0);\n        for (int i = 2; i <= n; ++i) {\n            if (mpf[i]\
    \ == i) {\n                ps.push_back(i);\n            }\n            for (int\
    \ p : ps) {\n                if (p > mpf[i] || i * p > n) {\n                \
    \    break;\n                }\n                mpf[p * i] = p;\n            }\n\
    \        }\n    }\n    \n    int min_prime_factor(int n) const {\n        assert(n\
    \ >= 2 && n < static_cast<int>(mpf.size()));\n        return mpf[n];\n    }\n\
    \    \n    std::vector<int> primes() const {\n        return ps;\n    }\n    \n\
    \    bool is_prime(int n) const {\n        assert(n < static_cast<int>(mpf.size()));\n\
    \        return n >= 2 && mpf[n] == n;\n    }\n    \n    std::vector<std::pair<int,\
    \ int>> factorize(int n) const {\n        assert(n > 0 && n < mpf.size());\n \
    \       std::vector<std::pair<int, int>> ret;\n        while (n > 1) {\n     \
    \       int p = mpf[n];\n            int ex = 0;\n            while (n % p ==\
    \ 0) {\n                n /= p;\n                ++ex;\n            }\n      \
    \      ret.emplace_back(p, ex);\n        }\n        return ret;\n    }\n};\n\n"
  code: "#pragma once\n\n#include <vector>\n#include <numeric>\n\nclass LinearSieve\
    \ {\n    std::vector<int> mpf;\n    std::vector<int> ps;\n    \npublic:\n    LinearSieve(int\
    \ n) : mpf(n + 1) {\n        std::iota(mpf.begin(), mpf.end(), 0);\n        for\
    \ (int i = 2; i <= n; ++i) {\n            if (mpf[i] == i) {\n               \
    \ ps.push_back(i);\n            }\n            for (int p : ps) {\n          \
    \      if (p > mpf[i] || i * p > n) {\n                    break;\n          \
    \      }\n                mpf[p * i] = p;\n            }\n        }\n    }\n \
    \   \n    int min_prime_factor(int n) const {\n        assert(n >= 2 && n < static_cast<int>(mpf.size()));\n\
    \        return mpf[n];\n    }\n    \n    std::vector<int> primes() const {\n\
    \        return ps;\n    }\n    \n    bool is_prime(int n) const {\n        assert(n\
    \ < static_cast<int>(mpf.size()));\n        return n >= 2 && mpf[n] == n;\n  \
    \  }\n    \n    std::vector<std::pair<int, int>> factorize(int n) const {\n  \
    \      assert(n > 0 && n < mpf.size());\n        std::vector<std::pair<int, int>>\
    \ ret;\n        while (n > 1) {\n            int p = mpf[n];\n            int\
    \ ex = 0;\n            while (n % p == 0) {\n                n /= p;\n       \
    \         ++ex;\n            }\n            ret.emplace_back(p, ex);\n       \
    \ }\n        return ret;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/linear_sieve.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/linear_sieve.hpp
layout: document
redirect_from:
- /library/number_theory/linear_sieve.hpp
- /library/number_theory/linear_sieve.hpp.html
title: number_theory/linear_sieve.hpp
---
