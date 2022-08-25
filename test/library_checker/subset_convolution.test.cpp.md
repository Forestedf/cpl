---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: convolution/subset_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution_internal.hpp
    title: convolution/subset_convolution_internal.hpp
  - icon: ':question:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':question:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/library_checker/subset_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#define FAST_IO\n\
    \n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n\
    #include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n#define\
    \ REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n) for (i32\
    \ i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3,\
    \ REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)\n\
    #define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\nusing i32\
    \ = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\nusing\
    \ f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing Vec\
    \ = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n    if\
    \ (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\n\nistream &operator>>(istream\
    \ &is, i128 &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\n\
    istream &operator>>(istream &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x =\
    \ v;\n    return is;\n}\nostream &operator<<(ostream &os, u128 x) {\n    os <<\
    \ (u64) x;\n    return os;\n}\n\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n\
    [[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n\
    \    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n     \
    \   cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n  \
    \  }\n} set_up_io;\n#line 2 \"convolution/subset_convolution.hpp\"\n\n#line 2\
    \ \"convolution/subset_convolution_internal.hpp\"\n\n#line 5 \"convolution/subset_convolution_internal.hpp\"\
    \n\nnamespace subset_convolution_internal {\n\ntemplate <typename T>\nvoid add(std::vector<T>\
    \ &a, const std::vector<T> &b, int to) {\n    for (int i = 0; i <= to; ++i) {\n\
    \        a[i] += b[i];\n    }\n}\n\ntemplate <typename T>\nvoid sub(std::vector<T>\
    \ &a, const std::vector<T> &b, int from) {\n    for (int i = from; i < (int) a.size();\
    \ ++i) {\n        a[i] -= b[i];\n    }\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ setps(int n, const std::vector<T> &a) {\n    std::vector<std::vector<T>> sps(1\
    \ << n, std::vector<T>(n + 1, T(0)));\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        sps[i][__builtin_popcount(i)] = a[i];\n    }\n    return sps;\n}\n\
    \ntemplate <typename T>\nstd::vector<T> rev_setps(int n, const std::vector<std::vector<T>>\
    \ &sps) {\n    std::vector<T> a(1 << n);\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        a[i] = sps[i][__builtin_popcount(i)];\n    }\n    return a;\n}\n\n\
    } // namespace subset_convolution_internal\n#line 4 \"convolution/subset_convolution.hpp\"\
    \n\n#line 6 \"convolution/subset_convolution.hpp\"\n\ntemplate <typename T>\n\
    std::vector<T> _subset_conv_mul(const std::vector<T> &a, const std::vector<T>\
    \ &b, int to) {\n    std::vector<T> c(a.size(), T(0));\n    for (int i = 0; i\
    \ <= to; ++i) {\n        for (int j = 0; j <= std::min((int) a.size() - i - 1,\
    \ to); ++j) {\n            c[i + j] += a[i] * b[j];\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nstd::vector<T> subset_convolution(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\n    int n = 0;\n    while ((1 << n) < (int)\
    \ a.size()) {\n        ++n;\n    }\n    assert((int) a.size() == (1 << n));\n\
    \    assert((int) b.size() == (1 << n));\n    \n    std::vector<std::vector<T>>\
    \ a_ = subset_convolution_internal::setps(n, a);\n    std::vector<std::vector<T>>\
    \ b_ = subset_convolution_internal::setps(n, b);\n    for (int d = 0; d < n; ++\
    \ d) {\n        for (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 <<\
    \ d)) {\n                subset_convolution_internal::add(a_[i], a_[i ^ (1 <<\
    \ d)], __builtin_popcount(i) - 1);\n                subset_convolution_internal::add(b_[i],\
    \ b_[i ^ (1 << d)], __builtin_popcount(i) - 1);\n            }\n        }\n  \
    \  }\n    for (int i = 0; i < (1 << n); ++i) {\n        a_[i] = _subset_conv_mul(a_[i],\
    \ b_[i], __builtin_popcount(i));\n    }\n    for (int d = 0; d < n; ++ d) {\n\
    \        for (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n\
    \                subset_convolution_internal::sub(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i));\n\
    \            }\n        }\n    }\n    return subset_convolution_internal::rev_setps(n,\
    \ a_);\n}\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line 5 \"number_theory/mod_int.hpp\"\
    \n#include <type_traits>\n\n#line 2 \"number_theory/utils.hpp\"\n\nconstexpr bool\
    \ is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return false;\n\
    \    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\nconstexpr\
    \ unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned ret =\
    \ 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n            ret =\
    \ (unsigned) ((unsigned long long) ret * self % mod);\n        }\n        self\
    \ = (unsigned) ((unsigned long long) self * self % mod);\n        y /= 2;\n  \
    \  }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned primitive_root()\
    \ {\n    static_assert(is_prime(mod), \"`mod` must be a prime number.\");\n  \
    \  if (mod == 2) {\n        return 1;\n    }\n\n    unsigned primes[32] = {};\n\
    \    int it = 0;\n    {\n        unsigned m = mod - 1;\n        for (unsigned\
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
    \ mod1000000007 = 1000000007;\n\n#line 8 \"test/library_checker/subset_convolution.test.cpp\"\
    \n\nint main() {\n    using Mint = ModInt<mod998244353>;\n    \n    i32 n;\n \
    \   cin >> n;\n    Vec<Mint> a(1 << n), b(1 << n);\n    REP(i, 1 << n) {\n   \
    \     cin >> a[i];\n    }\n    REP(i, 1 << n) {\n        cin >> b[i];\n    }\n\
    \    Vec<Mint> c = subset_convolution(a, b);\n    REP(i, 1 << n) {\n        cout\
    \ << c[i] << \" \\n\"[i + 1 == (1 << n)];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../convolution/subset_convolution.hpp\"\
    \n#include \"../../number_theory/mod_int.hpp\"\n\nint main() {\n    using Mint\
    \ = ModInt<mod998244353>;\n    \n    i32 n;\n    cin >> n;\n    Vec<Mint> a(1\
    \ << n), b(1 << n);\n    REP(i, 1 << n) {\n        cin >> a[i];\n    }\n    REP(i,\
    \ 1 << n) {\n        cin >> b[i];\n    }\n    Vec<Mint> c = subset_convolution(a,\
    \ b);\n    REP(i, 1 << n) {\n        cout << c[i] << \" \\n\"[i + 1 == (1 << n)];\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - convolution/subset_convolution.hpp
  - convolution/subset_convolution_internal.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: true
  path: test/library_checker/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/subset_convolution.test.cpp
- /verify/test/library_checker/subset_convolution.test.cpp.html
title: test/library_checker/subset_convolution.test.cpp
---