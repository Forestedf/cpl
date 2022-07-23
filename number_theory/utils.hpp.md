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
    path: test/library_checker/bitwise_and_convolution.test.cpp
    title: test/library_checker/bitwise_and_convolution.test.cpp
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
    path: test/library_checker/matrix_det.test.cpp
    title: test/library_checker/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix_product.test.cpp
    title: test/library_checker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_set_range_composite.test.cpp
    title: test/library_checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/pow_of_formal_power_series.test.cpp
    title: test/library_checker/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/queue_operate_all_composite.test.cpp
    title: test/library_checker/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_affine_range_sum.test.cpp
    title: test/library_checker/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/subset_convolution.test.cpp
    title: test/library_checker/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/vertex_set_path_composite.test.cpp
    title: test/library_checker/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/other/sparse_segment_tree.test.cpp
    title: test/other/sparse_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/other/subset_convolution_exp_log.test.cpp
    title: test/other/subset_convolution_exp_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1891.test.cpp
    title: test/yukicoder/1891.test.cpp
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
    \ != 0) {\n        if (y & 1) {\n            ret = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(ret) * self % mod);\n        }\n        self = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(self) * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\
    \ntemplate <unsigned mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
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
    \     if (y & 1) {\n            ret = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(ret) * self % mod);\n        }\n        self = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(self) * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\
    \ntemplate <unsigned mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
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
    \    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/utils.hpp
  requiredBy:
  - number_theory/number_theoretic_transform.hpp
  - number_theory/mod_int.hpp
  - template/debug.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/library_checker/matrix_product.test.cpp
  - test/library_checker/pow_of_formal_power_series.test.cpp
  - test/library_checker/vertex_set_path_composite.test.cpp
  - test/library_checker/subset_convolution.test.cpp
  - test/library_checker/inv_of_formal_power_series.test.cpp
  - test/library_checker/polynomial_taylor_shift.test.cpp
  - test/library_checker/matrix_det.test.cpp
  - test/library_checker/convolution_mod.test.cpp
  - test/library_checker/queue_operate_all_composite.test.cpp
  - test/library_checker/exp_of_formal_power_series.test.cpp
  - test/library_checker/bitwise_and_convolution.test.cpp
  - test/library_checker/log_of_formal_power_series.test.cpp
  - test/library_checker/range_affine_range_sum.test.cpp
  - test/library_checker/point_set_range_composite.test.cpp
  - test/yukicoder/1891.test.cpp
  - test/other/sparse_segment_tree.test.cpp
  - test/other/subset_convolution_exp_log.test.cpp
documentation_of: number_theory/utils.hpp
layout: document
redirect_from:
- /library/number_theory/utils.hpp
- /library/number_theory/utils.hpp.html
title: number_theory/utils.hpp
---
