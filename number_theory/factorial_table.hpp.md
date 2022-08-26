---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: polynomial/test/polynomial_taylor_shift.test.cpp
    title: polynomial/test/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/factorial_table.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <typename T>\nclass FactorialTable {\n    std::vector<T>\
    \ fac;\n    std::vector<T> ifac;\n    \npublic:\n    FactorialTable() : fac(1,\
    \ T(1)), ifac(1, T(1)) {}\n    \n    FactorialTable(int n) : fac(n + 1), ifac(n\
    \ + 1) {\n        assert(n >= 0);\n        fac[0] = T(1);\n        for (int i\
    \ = 1; i <= n; ++i) {\n            fac[i] = fac[i - 1] * T(i);\n        }\n  \
    \      ifac[n] = T(1) / T(fac[n]);\n        for (int i = n; i > 0; --i) {\n  \
    \          ifac[i - 1] = ifac[i] * T(i);\n        }\n    }\n    \n    void resize(int\
    \ n) {\n        int old = n_max();\n        if (n <= old) {\n            return;\n\
    \        }\n        fac.resize(n + 1);\n        for (int i = old + 1; i <= n;\
    \ ++i) {\n            fac[i] = fac[i - 1] * T(i);\n        }\n        ifac.resize(n\
    \ + 1);\n        ifac[n] = T(1) / T(fac[n]);\n        for (int i = n; i > old;\
    \ --i) {\n            ifac[i - 1] = ifac[i] * T(i);\n        }\n    }\n    \n\
    \    inline int n_max() const {\n        return (int) fac.size() - 1;\n    }\n\
    \    \n    inline T fact(int n) const {\n        assert(n >= 0 && n <= n_max());\n\
    \        return fac[n];\n    }\n    \n    inline T inv_fact(int n) const {\n \
    \       assert(n >= 0 && n <= n_max());\n        return ifac[n];\n    }\n    \n\
    \    inline T choose(int n, int k) const {\n        assert(k <= n_max() && n <=\
    \ n_max());\n        if (k > n || k < 0) {\n            return T(0);\n       \
    \ }\n        return fac[n] * ifac[k] * ifac[n - k];\n    }\n    \n    inline T\
    \ multi_choose(int n, int k) const {\n        assert(n >= 1 && k >= 0 && k + n\
    \ - 1 <= n_max());\n        return choose(k + n - 1, k);\n    }\n    \n    inline\
    \ T n_terms_sum_k(int n, int k) const {\n        assert(n >= 0);\n        if (k\
    \ < 0) {\n            return T(0);\n        }\n        if (n == 0) {\n       \
    \     return k == 0 ? T(1) : T(0);\n        }\n        return choose(n + k - 1,\
    \ n - 1);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nclass FactorialTable {\n    std::vector<T> fac;\n    std::vector<T> ifac;\n\
    \    \npublic:\n    FactorialTable() : fac(1, T(1)), ifac(1, T(1)) {}\n    \n\
    \    FactorialTable(int n) : fac(n + 1), ifac(n + 1) {\n        assert(n >= 0);\n\
    \        fac[0] = T(1);\n        for (int i = 1; i <= n; ++i) {\n            fac[i]\
    \ = fac[i - 1] * T(i);\n        }\n        ifac[n] = T(1) / T(fac[n]);\n     \
    \   for (int i = n; i > 0; --i) {\n            ifac[i - 1] = ifac[i] * T(i);\n\
    \        }\n    }\n    \n    void resize(int n) {\n        int old = n_max();\n\
    \        if (n <= old) {\n            return;\n        }\n        fac.resize(n\
    \ + 1);\n        for (int i = old + 1; i <= n; ++i) {\n            fac[i] = fac[i\
    \ - 1] * T(i);\n        }\n        ifac.resize(n + 1);\n        ifac[n] = T(1)\
    \ / T(fac[n]);\n        for (int i = n; i > old; --i) {\n            ifac[i -\
    \ 1] = ifac[i] * T(i);\n        }\n    }\n    \n    inline int n_max() const {\n\
    \        return (int) fac.size() - 1;\n    }\n    \n    inline T fact(int n) const\
    \ {\n        assert(n >= 0 && n <= n_max());\n        return fac[n];\n    }\n\
    \    \n    inline T inv_fact(int n) const {\n        assert(n >= 0 && n <= n_max());\n\
    \        return ifac[n];\n    }\n    \n    inline T choose(int n, int k) const\
    \ {\n        assert(k <= n_max() && n <= n_max());\n        if (k > n || k < 0)\
    \ {\n            return T(0);\n        }\n        return fac[n] * ifac[k] * ifac[n\
    \ - k];\n    }\n    \n    inline T multi_choose(int n, int k) const {\n      \
    \  assert(n >= 1 && k >= 0 && k + n - 1 <= n_max());\n        return choose(k\
    \ + n - 1, k);\n    }\n    \n    inline T n_terms_sum_k(int n, int k) const {\n\
    \        assert(n >= 0);\n        if (k < 0) {\n            return T(0);\n   \
    \     }\n        if (n == 0) {\n            return k == 0 ? T(1) : T(0);\n   \
    \     }\n        return choose(n + k - 1, n - 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/factorial_table.hpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - polynomial/test/polynomial_taylor_shift.test.cpp
documentation_of: number_theory/factorial_table.hpp
layout: document
redirect_from:
- /library/number_theory/factorial_table.hpp
- /library/number_theory/factorial_table.hpp.html
title: number_theory/factorial_table.hpp
---
