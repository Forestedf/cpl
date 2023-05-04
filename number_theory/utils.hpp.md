---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/number_theoretic_transform.hpp
    title: number_theory/number_theoretic_transform.hpp
  - icon: ':warning:'
    path: template/debug.hpp
    title: template/debug.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_det.test.cpp
    title: algebra/test/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_product.test.cpp
    title: algebra/test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/bitwise_and_convolution.test.cpp
    title: convolution/test/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/bitwise_or_convolution.test.cpp
    title: convolution/test/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/exp_of_set_power_series.test.cpp
    title: convolution/test/exp_of_set_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution.test.cpp
    title: convolution/test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution_exp_log.test.cpp
    title: convolution/test/subset_convolution_exp_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/1891.test.cpp
    title: data_structure/test/1891.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_set_range_composite.test.cpp
    title: data_structure/test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/queue_operate_all_composite.test.cpp
    title: data_structure/test/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_range_sum.test.cpp
    title: data_structure/test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/sparse_segment_tree.test.cpp
    title: data_structure/test/sparse_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/vertex_set_path_composite.test.cpp
    title: graph/test/vertex_set_path_composite.test.cpp
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
  bundledCode: "#line 2 \"number_theory/utils.hpp\"\n\nconstexpr bool is_prime(unsigned\
    \ n) {\n    if (n == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned\
    \ i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned\
    \ x, unsigned y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y\
    \ != 0) {\n        if (y & 1) {\n            ret = (unsigned) ((unsigned long\
    \ long) ret * self % mod);\n        }\n        self = (unsigned) ((unsigned long\
    \ long) self * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate\
    \ <unsigned mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n\
    \    }\n\n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned\
    \ m = mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if\
    \ (m % i == 0) {\n                primes[it++] = i;\n                while (m\
    \ % i == 0) {\n                    m /= i;\n                }\n            }\n\
    \        }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n\
    \    }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n  \
    \      for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) /\
    \ primes[j], mod) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if (ok)\n            return i;\n    }\n   \
    \ return 0;\n}\n\n// y >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x,\
    \ T y) {\n    x %= y;\n    if (x < 0) {\n        x += y;\n    }\n    return x;\n\
    }\n\n// y != 0\ntemplate <typename T>\nconstexpr T floor_div(T x, T y) {\n   \
    \ if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n\
    \        return x / y;\n    } else {\n        return -((-x + y - 1) / y);\n  \
    \  }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T ceil_div(T x, T y) {\n\
    \    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0)\
    \ {\n        return (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n\
    \    }\n}\n"
  code: "#pragma once\n\nconstexpr bool is_prime(unsigned n) {\n    if (n == 0 ||\
    \ n == 1) {\n        return false;\n    }\n    for (unsigned i = 2; i * i <= n;\
    \ ++i) {\n        if (n % i == 0) {\n            return false;\n        }\n  \
    \  }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned x, unsigned y,\
    \ unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y != 0) {\n   \
    \     if (y & 1) {\n            ret = (unsigned) ((unsigned long long) ret * self\
    \ % mod);\n        }\n        self = (unsigned) ((unsigned long long) self * self\
    \ % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned mod>\n\
    constexpr unsigned primitive_root() {\n    static_assert(is_prime(mod), \"`mod`\
    \ must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n    }\n\
    \n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned m =\
    \ mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if (m\
    \ % i == 0) {\n                primes[it++] = i;\n                while (m % i\
    \ == 0) {\n                    m /= i;\n                }\n            }\n   \
    \     }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n   \
    \ }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n     \
    \   for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) / primes[j],\
    \ mod) == 1) {\n                ok = false;\n                break;\n        \
    \    }\n        }\n        if (ok)\n            return i;\n    }\n    return 0;\n\
    }\n\n// y >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x, T y) {\n    x\
    \ %= y;\n    if (x < 0) {\n        x += y;\n    }\n    return x;\n}\n\n// y !=\
    \ 0\ntemplate <typename T>\nconstexpr T floor_div(T x, T y) {\n    if (y < 0)\
    \ {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return\
    \ x / y;\n    } else {\n        return -((-x + y - 1) / y);\n    }\n}\n\n// y\
    \ != 0\ntemplate <typename T>\nconstexpr T ceil_div(T x, T y) {\n    if (y < 0)\
    \ {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return\
    \ (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/utils.hpp
  requiredBy:
  - number_theory/mod_int.hpp
  - number_theory/number_theoretic_transform.hpp
  - template/debug.hpp
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/matrix_det.test.cpp
  - algebra/test/matrix_product.test.cpp
  - number_theory/test/convolution_mod.test.cpp
  - graph/test/vertex_set_path_composite.test.cpp
  - polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - polynomial/test/polynomial_taylor_shift.test.cpp
  - polynomial/test/inv_of_formal_power_series.test.cpp
  - polynomial/test/exp_of_formal_power_series.test.cpp
  - polynomial/test/pow_of_formal_power_series.test.cpp
  - polynomial/test/log_of_formal_power_series.test.cpp
  - data_structure/test/point_set_range_composite.test.cpp
  - data_structure/test/sparse_segment_tree.test.cpp
  - data_structure/test/1891.test.cpp
  - data_structure/test/range_affine_range_sum.test.cpp
  - data_structure/test/queue_operate_all_composite.test.cpp
  - convolution/test/subset_convolution_exp_log.test.cpp
  - convolution/test/subset_convolution.test.cpp
  - convolution/test/bitwise_and_convolution.test.cpp
  - convolution/test/bitwise_or_convolution.test.cpp
  - convolution/test/exp_of_set_power_series.test.cpp
documentation_of: number_theory/utils.hpp
layout: document
redirect_from:
- /library/number_theory/utils.hpp
- /library/number_theory/utils.hpp.html
title: number_theory/utils.hpp
---