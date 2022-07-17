---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number_theory/number_theoretic_transform.hpp
    title: number_theory/number_theoretic_transform.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution_mod.test.cpp
    title: test/library_checker/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/exp_of_formal_power_series.test.cpp
    title: test/library_checker/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/inv_of_formal_power_series.test.cpp
    title: test/library_checker/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/log_of_formal_power_series.test.cpp
    title: test/library_checker/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/pow_of_formal_power_series.test.cpp
    title: test/library_checker/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/bitop.hpp\"\n\ntemplate <typename T>\nbool ith_bit(T\
    \ n, T i) {\n    return (n & ((T) 1 << i)) != 0;\n}\n\nint popcount(int x) {\n\
    \    return __builtin_popcount(x);\n}\nlong long popcount(long long x) {\n   \
    \ return __builtin_popcountll(x);\n}\n\n// x must not be 0\nint clz(int x) {\n\
    \    return __builtin_clz(x);\n}\nlong long clz(long long x) {\n    return __builtin_clzll(x);\n\
    }\n\n// x must not be 0\nint ctz(int x) {\n    return __builtin_ctz(x);\n}\nlong\
    \ long ctz(long long x) {\n    return __builtin_ctzll(x);\n}\n\ntemplate <typename\
    \ T>\nT mask_n(T x, T n) {\n    T mask = ((T) 1 << n) - 1;\n    return x & mask;\n\
    }\n"
  code: "#pragma once\n\ntemplate <typename T>\nbool ith_bit(T n, T i) {\n    return\
    \ (n & ((T) 1 << i)) != 0;\n}\n\nint popcount(int x) {\n    return __builtin_popcount(x);\n\
    }\nlong long popcount(long long x) {\n    return __builtin_popcountll(x);\n}\n\
    \n// x must not be 0\nint clz(int x) {\n    return __builtin_clz(x);\n}\nlong\
    \ long clz(long long x) {\n    return __builtin_clzll(x);\n}\n\n// x must not\
    \ be 0\nint ctz(int x) {\n    return __builtin_ctz(x);\n}\nlong long ctz(long\
    \ long x) {\n    return __builtin_ctzll(x);\n}\n\ntemplate <typename T>\nT mask_n(T\
    \ x, T n) {\n    T mask = ((T) 1 << n) - 1;\n    return x & mask;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/bitop.hpp
  requiredBy:
  - number_theory/number_theoretic_transform.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/log_of_formal_power_series.test.cpp
  - test/library_checker/inv_of_formal_power_series.test.cpp
  - test/library_checker/exp_of_formal_power_series.test.cpp
  - test/library_checker/convolution_mod.test.cpp
  - test/library_checker/pow_of_formal_power_series.test.cpp
  - test/library_checker/polynomial_taylor_shift.test.cpp
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: template/bitop.hpp
layout: document
redirect_from:
- /library/template/bitop.hpp
- /library/template/bitop.hpp.html
title: template/bitop.hpp
---
