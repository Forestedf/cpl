---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':question:'
    path: polynomial/fps_log.hpp
    title: polynomial/fps_log.hpp
  - icon: ':question:'
    path: polynomial/polynomial.hpp
    title: polynomial/polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/with_acl.hpp
    title: polynomial/with_acl.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/library_checker/log_of_formal_power_series_acl.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n\
    #define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n)\
    \ for (i32 i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >=\
    \ 0; --i)\n#define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\n\
    using f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing\
    \ Vec = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
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
    \  }\n} set_up_io;\n#line 2 \"polynomial/with_acl.hpp\"\n\n#include <atcoder/convolution>\n\
    \ntemplate <int mod>\nclass ACLNTT {\npublic:\n    using Mint = atcoder::static_modint<mod>;\n\
    \    \n    static void dft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly(a);\n\
    \    }\n    static void idft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly_inv(a);\n\
    \        Mint inv = Mint::raw(a.size()).inv();\n        for (Mint &ele : a) {\n\
    \            ele *= inv;\n        }\n    }\n    static std::vector<Mint> mul(std::vector<Mint>\
    \ a, std::vector<Mint> b) {\n        return atcoder::convolution(a, b);\n    }\n\
    };\n#line 2 \"polynomial/fps_log.hpp\"\n\n#line 2 \"polynomial/fps_inv.hpp\"\n\
    \n#line 2 \"polynomial/polynomial.hpp\"\n\n#line 7 \"polynomial/polynomial.hpp\"\
    \n\ntemplate <typename T, typename Mul>\nclass Polynomial {\n    std::vector<T>\
    \ coeff;\n    \npublic:\n    using This = Polynomial<T, Mul>;\n    \n    Polynomial()\
    \ : coeff() {}\n    Polynomial(int n) : coeff(n, T(0)) {}\n    Polynomial(std::vector<T>\
    \ c) : coeff(std::move(c)) {}\n    \n    const std::vector<T> &vec() const {\n\
    \        return coeff;\n    }\n    \n    int size() const {\n        return (int)\
    \ coeff.size();\n    }\n    \n    const T &operator[](int idx) const {\n     \
    \   return coeff[idx];\n    }\n    T &operator[](int idx) {\n        return coeff[idx];\n\
    \    }\n    \n    T at(int idx) const {\n        if (idx < size()) {\n       \
    \     return coeff[idx];\n        } else {\n            return T(0);\n       \
    \ }\n    }\n    \n    void pre_(int n) {\n        assert(n >= 0);\n        coeff.resize(n,\
    \ T(0));\n    }\n    This pre(int n) const {\n        This tmp(*this);\n     \
    \   tmp.pre_(n);\n        return tmp;\n    }\n    \n    T operator()(const T &x)\
    \ const {\n        T p(1), sum(0);\n        for (const T &ele : coeff) {\n   \
    \         sum += p * ele;\n            p *= x;\n        }\n        return sum;\n\
    \    }\n    \n    This &operator+=(const This &rhs) {\n        if (coeff.size()\
    \ < rhs.coeff.size()) {\n            coeff.resize(rhs.coeff.size(), T(0));\n \
    \       }\n        for (int i = 0; i < (int) rhs.coeff.size(); ++i) {\n      \
    \      coeff[i] += rhs.coeff[i];\n        }\n        return *this;\n    }\n  \
    \  friend This operator+(This lhs, const This &rhs) {\n        lhs += rhs;\n \
    \       return lhs;\n    }\n    This &operator-=(const This &rhs) {\n        if\
    \ (coeff.size() < rhs.coeff.size()) {\n            coeff.resize(rhs.coeff.size(),\
    \ T(0));\n        }\n        for (int i = 0; i < (int) rhs.coeff.size(); ++i)\
    \ {\n            coeff[i] -= rhs.coeff[i];\n        }\n        return *this;\n\
    \    }\n    friend This operator-(This lhs, const This &rhs) {\n        lhs -=\
    \ rhs;\n        return lhs;\n    }\n    \n    This &operator*=(This rhs) {\n \
    \       coeff = Mul::mul(std::move(coeff), std::move(rhs.coeff));\n        return\
    \ *this;\n    }\n    friend This operator*(This lhs, This rhs) {\n        return\
    \ This(Mul::mul(std::move(lhs.coeff), std::move(rhs.coeff)));\n    }\n    \n \
    \   This diff() const {\n        if (coeff.empty()) {\n            return This();\n\
    \        }\n        std::vector<T> c(coeff.size() - 1);\n        for (int i =\
    \ 0; i < (int) c.size(); ++i) {\n            c[i] = T(i + 1) * coeff[i + 1];\n\
    \        }\n        return This(c);\n    }\n    This integ() const {\n       \
    \ std::vector<T> c(coeff.size() + 1, T(0));\n        for (int i = 0; i < (int)\
    \ coeff.size(); ++i) {\n            c[i + 1] = coeff[i] / T(i + 1);\n        }\n\
    \        return This(c);\n    }\n};\n#line 4 \"polynomial/fps_inv.hpp\"\n\ntemplate\
    \ <typename T, typename Mul>\nPolynomial<T, Mul> fps_inv(const Polynomial<T, Mul>\
    \ &f, int sz = -1) {\n    const std::vector<T> &coeff = f.vec();\n    assert(!coeff.empty()\
    \ && coeff[0] != T(0));\n    if (sz == -1) {\n        sz = (int) coeff.size();\n\
    \    }\n    assert(sz >= 0);\n    std::vector<T> g({T(1) / coeff[0]});\n    while\
    \ ((int) g.size() < sz) {\n        std::vector<T> fg;\n        if (2 * g.size()\
    \ <= (int) coeff.size()) {\n            fg = std::vector<T>(coeff.begin(), coeff.begin()\
    \ + 2 * g.size());\n        } else {\n            fg = coeff;\n            fg.resize(2\
    \ * g.size());\n        }\n        Mul::dft(fg);\n        std::vector<T> dft_g\
    \ = g;\n        dft_g.resize(2 * g.size(), T(0));\n        Mul::dft(dft_g);\n\
    \        for (int i = 0; i < (int) 2 * g.size(); ++i) {\n            fg[i] *=\
    \ dft_g[i];\n        }\n        Mul::idft(fg);\n        std::fill(fg.begin(),\
    \ fg.begin() + g.size(), T(0));\n        Mul::dft(fg);\n        for (int i = 0;\
    \ i < (int) 2 * g.size(); ++i) {\n            fg[i] *= dft_g[i];\n        }\n\
    \        Mul::idft(fg);\n        g.resize(2 * g.size());\n        for (int i =\
    \ (int) g.size() / 2; i < g.size(); ++i) {\n            g[i] = -fg[i];\n     \
    \   }\n    }\n    g.resize(sz);\n    return Polynomial<T, Mul>(g);\n}\n#line 4\
    \ \"polynomial/fps_log.hpp\"\n\ntemplate <typename T, typename Mul>\nPolynomial<T,\
    \ Mul> fps_log(const Polynomial<T, Mul> &f, int sz = -1) {\n    const std::vector<T>\
    \ &coeff = f.vec();\n    assert(!coeff.empty() && coeff[0] == T(1));\n    if (sz\
    \ == -1) {\n        sz = (int) coeff.size();\n    }\n    assert(sz >= 0);\n  \
    \  if (sz == 0) {\n        return Polynomial<T, Mul>();\n    }\n    return (f.diff().pre(sz\
    \ - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();\n}\n#line 8 \"test/library_checker/log_of_formal_power_series_acl.test.cpp\"\
    \n\nusing Mint = atcoder::modint998244353;\n\nistream &operator>>(istream &is,\
    \ Mint &x) {\n    i32 val;\n    is >> val;\n    x = Mint(val);\n    return is;\n\
    }\nostream &operator<<(ostream &os, Mint x) {\n    os << x.val();\n    return\
    \ os;\n}\n\nint main() {\n    using FPS = Polynomial<Mint, ACLNTT<998244353>>;\n\
    \    \n    i32 n;\n    cin >> n;\n    FPS f(n);\n    REP(i, n) {\n        cin\
    \ >> f[i];\n    }\n    FPS g = fps_log(f);\n    REP(i, n) {\n        cout << g[i]\
    \ << \" \\n\"[i + 1 == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../polynomial/with_acl.hpp\"\
    \n#include \"../../polynomial/fps_log.hpp\"\n\nusing Mint = atcoder::modint998244353;\n\
    \nistream &operator>>(istream &is, Mint &x) {\n    i32 val;\n    is >> val;\n\
    \    x = Mint(val);\n    return is;\n}\nostream &operator<<(ostream &os, Mint\
    \ x) {\n    os << x.val();\n    return os;\n}\n\nint main() {\n    using FPS =\
    \ Polynomial<Mint, ACLNTT<998244353>>;\n    \n    i32 n;\n    cin >> n;\n    FPS\
    \ f(n);\n    REP(i, n) {\n        cin >> f[i];\n    }\n    FPS g = fps_log(f);\n\
    \    REP(i, n) {\n        cout << g[i] << \" \\n\"[i + 1 == n];\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - polynomial/with_acl.hpp
  - polynomial/fps_log.hpp
  - polynomial/fps_inv.hpp
  - polynomial/polynomial.hpp
  isVerificationFile: true
  path: test/library_checker/log_of_formal_power_series_acl.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 16:00:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/log_of_formal_power_series_acl.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/log_of_formal_power_series_acl.test.cpp
- /verify/test/library_checker/log_of_formal_power_series_acl.test.cpp.html
title: test/library_checker/log_of_formal_power_series_acl.test.cpp
---
