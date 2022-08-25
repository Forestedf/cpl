---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_exp.hpp
    title: polynomial/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_log.hpp
    title: polynomial/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/polynomial.hpp
    title: polynomial/polynomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/pow_of_formal_power_series.test.cpp
    title: test/library_checker/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/pow_of_formal_power_series_acl.test.cpp
    title: test/library_checker/pow_of_formal_power_series_acl.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/fps_pow.hpp\"\n\n#line 2 \"polynomial/fps_log.hpp\"\
    \n\n#line 2 \"polynomial/fps_inv.hpp\"\n\n#line 2 \"polynomial/polynomial.hpp\"\
    \n\n#include <vector>\n#include <utility>\n#include <cassert>\n#include <algorithm>\n\
    \ntemplate <typename T, typename Mul>\nclass Polynomial {\n    std::vector<T>\
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
    \ <= coeff.size()) {\n            fg = std::vector<T>(coeff.begin(), coeff.begin()\
    \ + 2 * g.size());\n        } else {\n            fg = coeff;\n            fg.resize(2\
    \ * g.size());\n        }\n        Mul::dft(fg);\n        std::vector<T> dft_g\
    \ = g;\n        dft_g.resize(2 * g.size(), T(0));\n        Mul::dft(dft_g);\n\
    \        for (int i = 0; i < 2 * (int) g.size(); ++i) {\n            fg[i] *=\
    \ dft_g[i];\n        }\n        Mul::idft(fg);\n        std::fill(fg.begin(),\
    \ fg.begin() + g.size(), T(0));\n        Mul::dft(fg);\n        for (int i = 0;\
    \ i < 2 * (int) g.size(); ++i) {\n            fg[i] *= dft_g[i];\n        }\n\
    \        Mul::idft(fg);\n        g.resize(2 * g.size());\n        for (int i =\
    \ (int) g.size() / 2; i < (int) g.size(); ++i) {\n            g[i] = -fg[i];\n\
    \        }\n    }\n    g.resize(sz);\n    return Polynomial<T, Mul>(g);\n}\n#line\
    \ 4 \"polynomial/fps_log.hpp\"\n\ntemplate <typename T, typename Mul>\nPolynomial<T,\
    \ Mul> fps_log(const Polynomial<T, Mul> &f, int sz = -1) {\n    const std::vector<T>\
    \ &coeff = f.vec();\n    assert(!coeff.empty() && coeff[0] == T(1));\n    if (sz\
    \ == -1) {\n        sz = (int) coeff.size();\n    }\n    assert(sz >= 0);\n  \
    \  if (sz == 0) {\n        return Polynomial<T, Mul>();\n    }\n    return (f.diff().pre(sz\
    \ - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();\n}\n#line 2 \"polynomial/fps_exp.hpp\"\
    \n\n#line 4 \"polynomial/fps_exp.hpp\"\n\ntemplate <typename T, typename Mul>\n\
    Polynomial<T, Mul> fps_exp(const Polynomial<T, Mul> &h, int sz = -1) {\n    const\
    \ std::vector<T> &coeff = h.vec();\n    assert(!coeff.empty() && coeff[0] == T(0));\n\
    \    if (sz == -1) {\n        sz = (int) coeff.size();\n    }\n    assert(sz >=\
    \ 0);\n    std::vector<T> f({T(1)});\n    std::vector<T> g({T(1)});\n    std::vector<T>\
    \ dft_f_({T(1), T(1)});\n    \n    while ((int) f.size() < sz) {\n        int\
    \ n = (int) f.size();\n        \n        // F_{2n}(g_0)\n        std::vector<T>\
    \ dft_g_2 = g;\n        dft_g_2.resize(2 * n, T(0));\n        Mul::dft(dft_g_2);\n\
    \        \n        // \\delta\n        std::vector<T> delta(n, T(0));\n      \
    \  for (int i = 0; i < n; ++i) {\n            delta[i] = dft_f_[i] * dft_g_2[i];\n\
    \        }\n        Mul::idft(delta);\n        delta.resize(2 * n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            std::swap(delta[i], delta[n + i]);\n\
    \        }\n        delta[n] -= T(1);\n        \n        // F_n(D(f_0))\n    \
    \    std::vector<T> dft_d_f(n, T(0));\n        for (int i = 0; i < n - 1; ++i)\
    \ {\n            dft_d_f[i] = T(i + 1) * f[i + 1];\n        }\n        Mul::dft(dft_d_f);\n\
    \        \n        // D(f_0) g_0\n        std::vector<T> d_f_g(n, T(0));\n   \
    \     for (int i = 0; i < n; ++i) {\n            d_f_g[i] = dft_d_f[i] * dft_g_2[i];\n\
    \        }\n        Mul::idft(d_f_g);\n        d_f_g.resize(2 * n, T(0));\n  \
    \      for (int i = 0; i < n - 1; ++i) {\n            T tmp = T(i + 1) * h.at(i\
    \ + 1);\n            d_f_g[n + i] = d_f_g[i] - tmp;\n            d_f_g[i] = tmp;\n\
    \        }\n        \n        // \\delta D(h_0)\n        std::vector<T> dft_delta\
    \ = delta;\n        Mul::dft(dft_delta);\n        std::vector<T> delta_d_h(2 *\
    \ n);\n        for (int i = 0; i < n - 1; ++i) {\n            delta_d_h[i] = T(i\
    \ + 1) * h.at(i + 1);\n        }\n        Mul::dft(delta_d_h);\n        for (int\
    \ i = 0; i < 2 * n; ++i) {\n            delta_d_h[i] *= dft_delta[i];\n      \
    \  }\n        Mul::idft(delta_d_h);\n        std::fill(delta_d_h.begin(), delta_d_h.begin()\
    \ + n, T(0));\n        \n        // \\epsilon\n        std::vector<T> eps = std::move(d_f_g);\n\
    \        for (int i = 0; i < 2 * n; ++i) {\n            eps[i] -= T(i + 1) * h.at(i\
    \ + 1) + delta_d_h[i];\n        }\n        for (int i = 2 * n - 1; i > 0; --i)\
    \ {\n            eps[i] = eps[i - 1] / T(i);\n        }\n        eps[0] = T(0);\n\
    \        \n        // \\epsilon f_0\n        std::vector<T> dft_eps = eps;\n \
    \       Mul::dft(dft_eps);\n        std::vector<T> eps_f(2 * n);\n        for\
    \ (int i = 0; i < 2 * n; ++i) {\n            eps_f[i] = dft_eps[i] * dft_f_[i];\n\
    \        }\n        Mul::idft(eps_f);\n        std::fill(eps_f.begin(), eps_f.begin()\
    \ + n - 1, T(0));\n        \n        // update f\n        f.resize(2 * n, T(0));\n\
    \        for (int i = 0; i < 2 * n; ++i) {\n            f[i] -= eps_f[i];\n  \
    \      }\n        \n        if ((int) f.size() >= sz) {\n            break;\n\
    \        }\n        \n        // update F_{2n}(f)\n        dft_f_ = f;\n     \
    \   dft_f_.resize(4 * n);\n        Mul::dft(dft_f_);\n        \n        // update\
    \ g\n        std::vector<T> fg(dft_f_.begin(), dft_f_.begin() + 2 * n);\n    \
    \    for (int i = 0; i < 2 * n; ++i) {\n            fg[i] *= dft_g_2[i];\n   \
    \     }\n        Mul::idft(fg);\n        std::fill(fg.begin(), fg.begin() + n,\
    \ T(0));\n        Mul::dft(fg);\n        for (int i = 0; i < 2 * n; ++i) {\n \
    \           fg[i] *= dft_g_2[i];\n        }\n        Mul::idft(fg);\n        g.resize(2\
    \ * n);\n        for (int i = n; i < 2 * n; ++i) {\n            g[i] = -fg[i];\n\
    \        }\n    }\n    \n    f.resize(sz);\n    return Polynomial<T, Mul>(f);\n\
    }\n#line 5 \"polynomial/fps_pow.hpp\"\n\ntemplate <typename T, typename Mul>\n\
    Polynomial<T, Mul> fps_pow(const Polynomial<T, Mul> &h, unsigned long long m,\
    \ int sz = -1) {\n    const std::vector<T> &coeff = h.vec();\n    if (sz == -1)\
    \ {\n        sz = (int) coeff.size();\n    }\n    assert(sz >= 0);\n    \n   \
    \ if (m == 0) {\n        std::vector<T> a(sz, T(0));\n        if (sz >= 1) {\n\
    \            a[0] = T(1);\n        }\n        return Polynomial<T, Mul>(a);\n\
    \    }\n    \n    int ord = (int) coeff.size();\n    for (int i = 0; i < (int)\
    \ coeff.size(); ++i) {\n        if (coeff[i] != T(0)) {\n            ord = i;\n\
    \            break;\n        }\n    }\n    if (ord == (int) coeff.size() || (unsigned\
    \ long long) ord >= ((unsigned long long) sz + m - 1) / m) {\n        return Polynomial<T,\
    \ Mul>(sz);\n    }\n    int zero = (int) (ord * m);\n    int nonzero = sz - zero;\n\
    \    \n    Polynomial<T, Mul> f(std::vector<T>(coeff.begin() + ord, coeff.end()));\n\
    \    T cf = f[0];\n    T cf_inv = cf.inv();\n    for (int i = 0; i < f.size();\
    \ ++i) {\n        f[i] *= cf_inv;\n    }\n    f = fps_log(f, nonzero); //f.log(nonzero);\n\
    \    T tm = T(m);\n    for (int i = 0; i < f.size(); ++i) {\n        f[i] *= tm;\n\
    \    }\n    f = fps_exp(f);\n    T cf_m = cf.pow(m);\n    for (int i = 0; i <\
    \ f.size(); ++i) {\n        f[i] *= cf_m;\n    }\n    std::vector<T> ans = f.vec();\n\
    \    ans.insert(ans.begin(), zero, T(0));\n    return Polynomial<T, Mul>(ans);\n\
    }\n"
  code: "#pragma once\n\n#include \"fps_log.hpp\"\n#include \"fps_exp.hpp\"\n\ntemplate\
    \ <typename T, typename Mul>\nPolynomial<T, Mul> fps_pow(const Polynomial<T, Mul>\
    \ &h, unsigned long long m, int sz = -1) {\n    const std::vector<T> &coeff =\
    \ h.vec();\n    if (sz == -1) {\n        sz = (int) coeff.size();\n    }\n   \
    \ assert(sz >= 0);\n    \n    if (m == 0) {\n        std::vector<T> a(sz, T(0));\n\
    \        if (sz >= 1) {\n            a[0] = T(1);\n        }\n        return Polynomial<T,\
    \ Mul>(a);\n    }\n    \n    int ord = (int) coeff.size();\n    for (int i = 0;\
    \ i < (int) coeff.size(); ++i) {\n        if (coeff[i] != T(0)) {\n          \
    \  ord = i;\n            break;\n        }\n    }\n    if (ord == (int) coeff.size()\
    \ || (unsigned long long) ord >= ((unsigned long long) sz + m - 1) / m) {\n  \
    \      return Polynomial<T, Mul>(sz);\n    }\n    int zero = (int) (ord * m);\n\
    \    int nonzero = sz - zero;\n    \n    Polynomial<T, Mul> f(std::vector<T>(coeff.begin()\
    \ + ord, coeff.end()));\n    T cf = f[0];\n    T cf_inv = cf.inv();\n    for (int\
    \ i = 0; i < f.size(); ++i) {\n        f[i] *= cf_inv;\n    }\n    f = fps_log(f,\
    \ nonzero); //f.log(nonzero);\n    T tm = T(m);\n    for (int i = 0; i < f.size();\
    \ ++i) {\n        f[i] *= tm;\n    }\n    f = fps_exp(f);\n    T cf_m = cf.pow(m);\n\
    \    for (int i = 0; i < f.size(); ++i) {\n        f[i] *= cf_m;\n    }\n    std::vector<T>\
    \ ans = f.vec();\n    ans.insert(ans.begin(), zero, T(0));\n    return Polynomial<T,\
    \ Mul>(ans);\n}"
  dependsOn:
  - polynomial/fps_log.hpp
  - polynomial/fps_inv.hpp
  - polynomial/polynomial.hpp
  - polynomial/fps_exp.hpp
  isVerificationFile: false
  path: polynomial/fps_pow.hpp
  requiredBy: []
  timestamp: '2022-07-22 12:48:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/pow_of_formal_power_series_acl.test.cpp
  - test/library_checker/pow_of_formal_power_series.test.cpp
documentation_of: polynomial/fps_pow.hpp
layout: document
redirect_from:
- /library/polynomial/fps_pow.hpp
- /library/polynomial/fps_pow.hpp.html
title: polynomial/fps_pow.hpp
---
