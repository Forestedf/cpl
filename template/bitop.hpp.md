---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/number_theoretic_transform.hpp
    title: number_theory/number_theoretic_transform.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/static_range_frequency.test.cpp
    title: data_structure/test/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/convolution_mod.test.cpp
    title: number_theory/test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/exp_of_formal_power_series.test.cpp
    title: polynomial/test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/inv_of_formal_power_series.test.cpp
    title: polynomial/test/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/log_of_formal_power_series.test.cpp
    title: polynomial/test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/polynomial_taylor_shift.test.cpp
    title: polynomial/test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/pow_of_formal_power_series.test.cpp
    title: polynomial/test/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/bitop.hpp\"\n\ntemplate <typename T, typename U>\n\
    bool ith_bit(T n, U i) {\n    return (n & ((T) 1 << i)) != 0;\n}\n\nint popcount(int\
    \ x) {\n    return __builtin_popcount(x);\n}\nunsigned popcount(unsigned x) {\n\
    \    return __builtin_popcount(x);\n}\nlong long popcount(long long x) {\n   \
    \ return __builtin_popcountll(x);\n}\nunsigned long long popcount(unsigned long\
    \ long x) {\n    return __builtin_popcountll(x);\n}\n\n// x must not be 0\nint\
    \ clz(int x) {\n    return __builtin_clz(x);\n}\nunsigned clz(unsigned x) {\n\
    \    return __builtin_clz(x);\n}\nlong long clz(long long x) {\n    return __builtin_clzll(x);\n\
    }\nunsigned long long clz(unsigned long long x) {\n    return __builtin_clzll(x);\n\
    }\n\n// x must not be 0\nint ctz(int x) {\n    return __builtin_ctz(x);\n}\nunsigned\
    \ ctz(unsigned int x) {\n    return __builtin_ctz(x);\n}\nlong long ctz(long long\
    \ x) {\n    return __builtin_ctzll(x);\n}\nunsigned long long ctz(unsigned long\
    \ long x) {\n    return __builtin_ctzll(x);\n}\n\nint floor_log2(int x) {\n  \
    \  return 31 - clz(x);\n}\nunsigned floor_log2(unsigned x) {\n    return 31 -\
    \ clz(x);\n}\nlong long floor_log2(long long x) {\n    return 63 - clz(x);\n}\n\
    unsigned long long floor_log2(unsigned long long x) {\n    return 63 - clz(x);\n\
    }\n\ntemplate <typename T>\nT mask_n(T x, T n) {\n    T mask = ((T) 1 << n) -\
    \ 1;\n    return x & mask;\n}\n"
  code: "#pragma once\n\ntemplate <typename T, typename U>\nbool ith_bit(T n, U i)\
    \ {\n    return (n & ((T) 1 << i)) != 0;\n}\n\nint popcount(int x) {\n    return\
    \ __builtin_popcount(x);\n}\nunsigned popcount(unsigned x) {\n    return __builtin_popcount(x);\n\
    }\nlong long popcount(long long x) {\n    return __builtin_popcountll(x);\n}\n\
    unsigned long long popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n\
    }\n\n// x must not be 0\nint clz(int x) {\n    return __builtin_clz(x);\n}\nunsigned\
    \ clz(unsigned x) {\n    return __builtin_clz(x);\n}\nlong long clz(long long\
    \ x) {\n    return __builtin_clzll(x);\n}\nunsigned long long clz(unsigned long\
    \ long x) {\n    return __builtin_clzll(x);\n}\n\n// x must not be 0\nint ctz(int\
    \ x) {\n    return __builtin_ctz(x);\n}\nunsigned ctz(unsigned int x) {\n    return\
    \ __builtin_ctz(x);\n}\nlong long ctz(long long x) {\n    return __builtin_ctzll(x);\n\
    }\nunsigned long long ctz(unsigned long long x) {\n    return __builtin_ctzll(x);\n\
    }\n\nint floor_log2(int x) {\n    return 31 - clz(x);\n}\nunsigned floor_log2(unsigned\
    \ x) {\n    return 31 - clz(x);\n}\nlong long floor_log2(long long x) {\n    return\
    \ 63 - clz(x);\n}\nunsigned long long floor_log2(unsigned long long x) {\n   \
    \ return 63 - clz(x);\n}\n\ntemplate <typename T>\nT mask_n(T x, T n) {\n    T\
    \ mask = ((T) 1 << n) - 1;\n    return x & mask;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/bitop.hpp
  requiredBy:
  - number_theory/number_theoretic_transform.hpp
  - data_structure/wavelet_matrix.hpp
  - data_structure/bit_vector.hpp
  timestamp: '2022-07-22 12:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/convolution_mod.test.cpp
  - polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - polynomial/test/polynomial_taylor_shift.test.cpp
  - polynomial/test/log_of_formal_power_series.test.cpp
  - polynomial/test/exp_of_formal_power_series.test.cpp
  - polynomial/test/pow_of_formal_power_series.test.cpp
  - polynomial/test/inv_of_formal_power_series.test.cpp
  - data_structure/test/range_kth_smallest.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
  - data_structure/test/static_range_frequency.test.cpp
documentation_of: template/bitop.hpp
layout: document
redirect_from:
- /library/template/bitop.hpp
- /library/template/bitop.hpp.html
title: template/bitop.hpp
---
