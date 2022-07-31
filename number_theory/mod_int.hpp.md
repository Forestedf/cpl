---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"number_theory/mod_int.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n\n#line 2 \"number_theory/utils.hpp\"\n\n\
    constexpr bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return\
    \ false;\n    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n %\
    \ i == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    \nconstexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned\
    \ ret = 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n           \
    \ ret = (unsigned) ((unsigned long long) ret * self % mod);\n        }\n     \
    \   self = (unsigned) ((unsigned long long) self * self % mod);\n        y /=\
    \ 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned\
    \ primitive_root() {\n    static_assert(is_prime(mod), \"`mod` must be a prime\
    \ number.\");\n    if (mod == 2) {\n        return 1;\n    }\n\n    unsigned primes[32]\
    \ = {};\n    int it = 0;\n    {\n        unsigned m = mod - 1;\n        for (unsigned\
    \ i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n                primes[it++]\
    \ = i;\n                while (m % i == 0) {\n                    m /= i;\n  \
    \              }\n            }\n        }\n        if (m != 1) {\n          \
    \  primes[it++] = m;\n        }\n    }\n    for (unsigned i = 2; i < mod; ++i)\
    \ {\n        bool ok = true;\n        for (int j = 0; j < it; ++j) {\n       \
    \     if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n                ok =\
    \ false;\n                break;\n            }\n        }\n        if (ok)\n\
    \            return i;\n    }\n    return 0;\n}\n\n// y >= 1\ntemplate <typename\
    \ T>\nconstexpr T safe_mod(T x, T y) {\n    x %= y;\n    if (x < 0) {\n      \
    \  x += y;\n    }\n    return x;\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T floor_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return x / y;\n    } else {\n        return\
    \ -((-x + y - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T ceil_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return (x + y - 1) / y;\n    } else {\n   \
    \     return -(-x / y);\n    }\n}\n#line 8 \"number_theory/mod_int.hpp\"\n\ntemplate\
    \ <unsigned mod>\nclass ModInt {\n    static_assert(mod != 0, \"`mod` must not\
    \ be equal to 0.\");\n    static_assert(\n        mod < (1u << 31),\n        \"\
    `mod` must be less than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\n\
    public:\n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned) ((long long) x % (long\
    \ long) mod + (x < 0 ? mod : 0))) {}\n    template <typename T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned) (x % mod)) {}\n\n \
    \   static constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n    \
    \    ret.val = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val()\
    \ const {\n        return val;\n    }\n\n    constexpr ModInt operator+() const\
    \ {\n        return *this;\n    }\n    constexpr ModInt operator-() const {\n\
    \        return ModInt<mod>(0u) - *this;\n    }\n\n    constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n        val += rhs.val;\n        if (val >= mod)\n         \
    \   val -= mod;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n        if (val < rhs.val)\n            val += mod;\n      \
    \  val -= rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n        val = (unsigned long long)val * rhs.val % mod;\n   \
    \     return *this;\n    }\n    constexpr ModInt &operator/=(const ModInt &rhs)\
    \ {\n        val = (unsigned long long)val * rhs.inv().val % mod;\n        return\
    \ *this;\n    }\n\n    friend constexpr ModInt operator+(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) += rhs;\n    }\n    friend constexpr\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ -= rhs;\n    }\n    friend constexpr ModInt operator*(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) *= rhs;\n    }\n    friend constexpr\
    \ ModInt operator/(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ /= rhs;\n    }\n\n    constexpr ModInt pow(unsigned long long x) const {\n \
    \       ModInt<mod> ret = ModInt<mod>::raw(1);\n        ModInt<mod> self = *this;\n\
    \        while (x != 0) {\n            if (x & 1)\n                ret *= self;\n\
    \            self *= self;\n            x >>= 1;\n        }\n        return ret;\n\
    \    }\n    constexpr ModInt inv() const {\n        static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n        assert(val != 0);\n        return\
    \ this->pow(mod - 2);\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, ModInt<mod> &x) {\n        is >> x.val;\n        x.val %= mod;\n      \
    \  return is;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const ModInt<mod> &x) {\n        os << x.val;\n        return os;\n    }\n\n\
    \    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {\n        return\
    \ lhs.val == rhs.val;\n    }\n    \n    friend bool operator!=(const ModInt &lhs,\
    \ const ModInt &rhs) {\n        return lhs.val != rhs.val;\n    }\n};\n\n[[maybe_unused]]\
    \ constexpr unsigned mod998244353 = 998244353;\n[[maybe_unused]] constexpr unsigned\
    \ mod1000000007 = 1000000007;\n\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <type_traits>\n\
    \n#include \"utils.hpp\"\n\ntemplate <unsigned mod>\nclass ModInt {\n    static_assert(mod\
    \ != 0, \"`mod` must not be equal to 0.\");\n    static_assert(\n        mod <\
    \ (1u << 31),\n        \"`mod` must be less than (1u << 31) = 2147483648.\");\n\
    \n    unsigned val;\n\npublic:\n    constexpr ModInt() : val(0) {}\n    template\
    \ <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>\n    constexpr\
    \ ModInt(T x) : val((unsigned) ((long long) x % (long long) mod + (x < 0 ? mod\
    \ : 0))) {}\n    template <typename T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned) (x % mod)) {}\n\n \
    \   static constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n    \
    \    ret.val = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val()\
    \ const {\n        return val;\n    }\n\n    constexpr ModInt operator+() const\
    \ {\n        return *this;\n    }\n    constexpr ModInt operator-() const {\n\
    \        return ModInt<mod>(0u) - *this;\n    }\n\n    constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n        val += rhs.val;\n        if (val >= mod)\n         \
    \   val -= mod;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n        if (val < rhs.val)\n            val += mod;\n      \
    \  val -= rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n        val = (unsigned long long)val * rhs.val % mod;\n   \
    \     return *this;\n    }\n    constexpr ModInt &operator/=(const ModInt &rhs)\
    \ {\n        val = (unsigned long long)val * rhs.inv().val % mod;\n        return\
    \ *this;\n    }\n\n    friend constexpr ModInt operator+(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) += rhs;\n    }\n    friend constexpr\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ -= rhs;\n    }\n    friend constexpr ModInt operator*(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) *= rhs;\n    }\n    friend constexpr\
    \ ModInt operator/(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ /= rhs;\n    }\n\n    constexpr ModInt pow(unsigned long long x) const {\n \
    \       ModInt<mod> ret = ModInt<mod>::raw(1);\n        ModInt<mod> self = *this;\n\
    \        while (x != 0) {\n            if (x & 1)\n                ret *= self;\n\
    \            self *= self;\n            x >>= 1;\n        }\n        return ret;\n\
    \    }\n    constexpr ModInt inv() const {\n        static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n        assert(val != 0);\n        return\
    \ this->pow(mod - 2);\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, ModInt<mod> &x) {\n        is >> x.val;\n        x.val %= mod;\n      \
    \  return is;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const ModInt<mod> &x) {\n        os << x.val;\n        return os;\n    }\n\n\
    \    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {\n        return\
    \ lhs.val == rhs.val;\n    }\n    \n    friend bool operator!=(const ModInt &lhs,\
    \ const ModInt &rhs) {\n        return lhs.val != rhs.val;\n    }\n};\n\n[[maybe_unused]]\
    \ constexpr unsigned mod998244353 = 998244353;\n[[maybe_unused]] constexpr unsigned\
    \ mod1000000007 = 1000000007;\n\n"
  dependsOn:
  - number_theory/utils.hpp
  isVerificationFile: false
  path: number_theory/mod_int.hpp
  requiredBy:
  - number_theory/number_theoretic_transform.hpp
  - template/debug.hpp
  timestamp: '2022-07-30 11:55:56+09:00'
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
documentation_of: number_theory/mod_int.hpp
layout: document
redirect_from:
- /library/number_theory/mod_int.hpp
- /library/number_theory/mod_int.hpp.html
title: number_theory/mod_int.hpp
---