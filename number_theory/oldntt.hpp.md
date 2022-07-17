---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/oldntt.hpp\"\n\n#include <array>\n#include\
    \ <vector>\n\n#line 2 \"number_theory/mod_int.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n\n#line 2 \"number_theory/utils.hpp\"\n\n\
    constexpr bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return\
    \ false;\n    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n %\
    \ i == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    \nconstexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned\
    \ ret = 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n           \
    \ ret = static_cast<unsigned>(static_cast<unsigned long long>(ret) * self % mod);\n\
    \        }\n        self = static_cast<unsigned>(static_cast<unsigned long long>(self)\
    \ * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned\
    \ mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
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
    \    }\n}\n#line 8 \"number_theory/mod_int.hpp\"\n\ntemplate <unsigned mod>\n\
    class ModInt {\n    static_assert(mod != 0, \"`mod` must not be equal to 0.\"\
    );\n    static_assert(\n        mod < (1u << 31),\n        \"`mod` must be less\
    \ than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\npublic:\n    constexpr\
    \ ModInt() : val(0) {}\n    template <typename T>\n    constexpr ModInt(T x) :\
    \ val(static_cast<unsigned>(safe_mod(x, static_cast<T>(mod)))) {}\n\n    static\
    \ constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n        ret.val\
    \ = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val() const {\n\
    \        return val;\n    }\n\n    constexpr ModInt operator+() const {\n    \
    \    return *this;\n    }\n    constexpr ModInt operator-() const {\n        return\
    \ ModInt<mod>(0u) - *this;\n    }\n\n    constexpr ModInt &operator+=(const ModInt\
    \ &rhs) {\n        val += rhs.val;\n        if (val >= mod)\n            val -=\
    \ mod;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const ModInt\
    \ &rhs) {\n        if (val < rhs.val)\n            val += mod;\n        val -=\
    \ rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
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
    \ mod1000000007 = 1000000007;\n\n#line 7 \"number_theory/oldntt.hpp\"\n\ntemplate\
    \ <unsigned mod>\nclass NumberTheoreticTransform {\n    static constexpr int calc_ex()\
    \ {\n        unsigned m = mod - 1;\n        int ret = 0;\n        while (!(m &\
    \ 1)) {\n            m >>= 1;\n            ++ret;\n        }\n        return ret;\n\
    \    }\n\n    static constexpr int max_ex = calc_ex();\n\n    std::array<ModInt<mod>,\
    \ max_ex + 1> root;\n    std::array<ModInt<mod>, max_ex + 1> inv_root;\n\n   \
    \ inline int ctz(int n) const {\n        return __builtin_ctz(n);\n    }\n\npublic:\n\
    \    void dft(std::vector<ModInt<mod>> &a) const {\n        int n = (int) a.size();\n\
    \        int ex = ctz(n);\n        int m = n;\n        while (m > 1) {\n     \
    \       for (int s = 0; s < n; s += m) {\n                auto z = ModInt<mod>::raw(1);\n\
    \                for (int i = 0; i < m >> 1; ++i) {\n                    auto\
    \ x = a[s + i];\n                    auto y = a[s + i + m / 2];\n            \
    \        a[s + i] = x + y;\n                    a[s + i + m / 2] = (x - y) * z;\n\
    \                    z *= root[ex];\n                }\n            }\n      \
    \      m >>= 1;\n            --ex;\n        }\n    }\n\n    void idft(std::vector<ModInt<mod>>\
    \ &a) const {\n        int n = (int) a.size();\n        int m = 2;\n        int\
    \ ex = 1;\n        while (m <= n) {\n            for (int s = 0; s < n; s += m)\
    \ {\n                auto z = ModInt<mod>::raw(1);\n                for (int i\
    \ = 0; i < m / 2; ++i) {\n                    auto x = a[s + i];\n           \
    \         auto y = a[s + i + m / 2] * z;\n                    a[s + i] = x + y;\n\
    \                    a[s + i + m / 2] = x - y;\n                    z *= inv_root[ex];\n\
    \                }\n            }\n            m <<= 1;\n            ++ex;\n \
    \       }\n        ModInt<mod> inv = ModInt<mod>::raw((unsigned) a.size()).inv();\n\
    \        for (ModInt<mod> &ele : a)\n            ele *= inv;\n    }\n\n    constexpr\
    \ NumberTheoreticTransform() : root(), inv_root() {\n        ModInt<mod> g =\n\
    \            ModInt<mod>::raw(primitive_root<mod>()).pow((mod - 1) >> max_ex);\n\
    \        root[max_ex] = g;\n        inv_root[max_ex] = g.inv();\n        for (int\
    \ i = max_ex; i > 0; --i) {\n            root[i - 1] = root[i] * root[i];\n  \
    \          inv_root[i - 1] = inv_root[i] * inv_root[i];\n        }\n    }\n\n\
    \    std::vector<ModInt<mod>> multiply(\n        std::vector<ModInt<mod>> a,\n\
    \        std::vector<ModInt<mod>> b) const {\n        if (a.empty() || b.empty())\n\
    \            return std::vector<ModInt<mod>>();\n        int siz = 1;\n      \
    \  int ex = 0;\n        int s = (int) (a.size() + b.size());\n        while (siz\
    \ < s) {\n            siz <<= 1;\n            ++ex;\n        }\n        a.resize(siz,\
    \ ModInt<mod>());\n        b.resize(siz, ModInt<mod>());\n        dft(a);\n  \
    \      dft(b);\n        for (int i = 0; i < siz; ++i) {\n            a[i] *= b[i];\n\
    \        }\n        idft(a);\n        a.resize(s - 1);\n        return a;\n  \
    \  }\n};\n\ntemplate <unsigned mod>\nclass NTTMul {\n    static constexpr NumberTheoreticTransform<mod>\
    \ ntt = NumberTheoreticTransform<mod>();\n\npublic:\n    static void dft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.dft(a);\n    }\n\n    static void idft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.idft(a);\n    }\n\n    static std::vector<ModInt<mod>> mul(\n\
    \        std::vector<ModInt<mod>> lhs,\n        std::vector<ModInt<mod>> rhs)\
    \ {\n        return ntt.multiply(std::move(lhs), std::move(rhs));\n    }\n};\n\
    \n"
  code: "#pragma once\n\n#include <array>\n#include <vector>\n\n#include \"mod_int.hpp\"\
    \n\ntemplate <unsigned mod>\nclass NumberTheoreticTransform {\n    static constexpr\
    \ int calc_ex() {\n        unsigned m = mod - 1;\n        int ret = 0;\n     \
    \   while (!(m & 1)) {\n            m >>= 1;\n            ++ret;\n        }\n\
    \        return ret;\n    }\n\n    static constexpr int max_ex = calc_ex();\n\n\
    \    std::array<ModInt<mod>, max_ex + 1> root;\n    std::array<ModInt<mod>, max_ex\
    \ + 1> inv_root;\n\n    inline int ctz(int n) const {\n        return __builtin_ctz(n);\n\
    \    }\n\npublic:\n    void dft(std::vector<ModInt<mod>> &a) const {\n       \
    \ int n = (int) a.size();\n        int ex = ctz(n);\n        int m = n;\n    \
    \    while (m > 1) {\n            for (int s = 0; s < n; s += m) {\n         \
    \       auto z = ModInt<mod>::raw(1);\n                for (int i = 0; i < m >>\
    \ 1; ++i) {\n                    auto x = a[s + i];\n                    auto\
    \ y = a[s + i + m / 2];\n                    a[s + i] = x + y;\n             \
    \       a[s + i + m / 2] = (x - y) * z;\n                    z *= root[ex];\n\
    \                }\n            }\n            m >>= 1;\n            --ex;\n \
    \       }\n    }\n\n    void idft(std::vector<ModInt<mod>> &a) const {\n     \
    \   int n = (int) a.size();\n        int m = 2;\n        int ex = 1;\n       \
    \ while (m <= n) {\n            for (int s = 0; s < n; s += m) {\n           \
    \     auto z = ModInt<mod>::raw(1);\n                for (int i = 0; i < m / 2;\
    \ ++i) {\n                    auto x = a[s + i];\n                    auto y =\
    \ a[s + i + m / 2] * z;\n                    a[s + i] = x + y;\n             \
    \       a[s + i + m / 2] = x - y;\n                    z *= inv_root[ex];\n  \
    \              }\n            }\n            m <<= 1;\n            ++ex;\n   \
    \     }\n        ModInt<mod> inv = ModInt<mod>::raw((unsigned) a.size()).inv();\n\
    \        for (ModInt<mod> &ele : a)\n            ele *= inv;\n    }\n\n    constexpr\
    \ NumberTheoreticTransform() : root(), inv_root() {\n        ModInt<mod> g =\n\
    \            ModInt<mod>::raw(primitive_root<mod>()).pow((mod - 1) >> max_ex);\n\
    \        root[max_ex] = g;\n        inv_root[max_ex] = g.inv();\n        for (int\
    \ i = max_ex; i > 0; --i) {\n            root[i - 1] = root[i] * root[i];\n  \
    \          inv_root[i - 1] = inv_root[i] * inv_root[i];\n        }\n    }\n\n\
    \    std::vector<ModInt<mod>> multiply(\n        std::vector<ModInt<mod>> a,\n\
    \        std::vector<ModInt<mod>> b) const {\n        if (a.empty() || b.empty())\n\
    \            return std::vector<ModInt<mod>>();\n        int siz = 1;\n      \
    \  int ex = 0;\n        int s = (int) (a.size() + b.size());\n        while (siz\
    \ < s) {\n            siz <<= 1;\n            ++ex;\n        }\n        a.resize(siz,\
    \ ModInt<mod>());\n        b.resize(siz, ModInt<mod>());\n        dft(a);\n  \
    \      dft(b);\n        for (int i = 0; i < siz; ++i) {\n            a[i] *= b[i];\n\
    \        }\n        idft(a);\n        a.resize(s - 1);\n        return a;\n  \
    \  }\n};\n\ntemplate <unsigned mod>\nclass NTTMul {\n    static constexpr NumberTheoreticTransform<mod>\
    \ ntt = NumberTheoreticTransform<mod>();\n\npublic:\n    static void dft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.dft(a);\n    }\n\n    static void idft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.idft(a);\n    }\n\n    static std::vector<ModInt<mod>> mul(\n\
    \        std::vector<ModInt<mod>> lhs,\n        std::vector<ModInt<mod>> rhs)\
    \ {\n        return ntt.multiply(std::move(lhs), std::move(rhs));\n    }\n};\n\
    \n"
  dependsOn:
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: false
  path: number_theory/oldntt.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/oldntt.hpp
layout: document
redirect_from:
- /library/number_theory/oldntt.hpp
- /library/number_theory/oldntt.hpp.html
title: number_theory/oldntt.hpp
---
