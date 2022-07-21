---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/polynomial.hpp
    title: polynomial/polynomial.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_pow.hpp
    title: polynomial/fps_pow.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/log_of_formal_power_series.test.cpp
    title: test/library_checker/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/log_of_formal_power_series_acl.test.cpp
    title: test/library_checker/log_of_formal_power_series_acl.test.cpp
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
  bundledCode: "#line 2 \"polynomial/fps_log.hpp\"\n\n#line 2 \"polynomial/fps_inv.hpp\"\
    \n\n#line 2 \"polynomial/polynomial.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n#include <algorithm>\n\ntemplate <typename T, typename Mul>\n\
    class Polynomial {\n    std::vector<T> coeff;\n    \npublic:\n    using This =\
    \ Polynomial<T, Mul>;\n    \n    Polynomial() : coeff() {}\n    Polynomial(int\
    \ n) : coeff(n, T(0)) {}\n    Polynomial(std::vector<T> c) : coeff(std::move(c))\
    \ {}\n    \n    const std::vector<T> &vec() const {\n        return coeff;\n \
    \   }\n    \n    int size() const {\n        return (int) coeff.size();\n    }\n\
    \    \n    const T &operator[](int idx) const {\n        return coeff[idx];\n\
    \    }\n    T &operator[](int idx) {\n        return coeff[idx];\n    }\n    \n\
    \    T at(int idx) const {\n        if (idx < size()) {\n            return coeff[idx];\n\
    \        } else {\n            return T(0);\n        }\n    }\n    \n    void\
    \ pre_(int n) {\n        assert(n >= 0);\n        coeff.resize(n, T(0));\n   \
    \ }\n    This pre(int n) const {\n        This tmp(*this);\n        tmp.pre_(n);\n\
    \        return tmp;\n    }\n    \n    T operator()(const T &x) const {\n    \
    \    T p(1), sum(0);\n        for (const T &ele : coeff) {\n            sum +=\
    \ p * ele;\n            p *= x;\n        }\n        return sum;\n    }\n    \n\
    \    This &operator+=(const This &rhs) {\n        if (coeff.size() < rhs.coeff.size())\
    \ {\n            coeff.resize(rhs.coeff.size(), T(0));\n        }\n        for\
    \ (int i = 0; i < (int) rhs.coeff.size(); ++i) {\n            coeff[i] += rhs.coeff[i];\n\
    \        }\n        return *this;\n    }\n    friend This operator+(This lhs,\
    \ const This &rhs) {\n        lhs += rhs;\n        return lhs;\n    }\n    This\
    \ &operator-=(const This &rhs) {\n        if (coeff.size() < rhs.coeff.size())\
    \ {\n            coeff.resize(rhs.coeff.size(), T(0));\n        }\n        for\
    \ (int i = 0; i < (int) rhs.coeff.size(); ++i) {\n            coeff[i] -= rhs.coeff[i];\n\
    \        }\n        return *this;\n    }\n    friend This operator-(This lhs,\
    \ const This &rhs) {\n        lhs -= rhs;\n        return lhs;\n    }\n    \n\
    \    This &operator*=(This rhs) {\n        coeff = Mul::mul(std::move(coeff),\
    \ std::move(rhs.coeff));\n        return *this;\n    }\n    friend This operator*(This\
    \ lhs, This rhs) {\n        return This(Mul::mul(std::move(lhs.coeff), std::move(rhs.coeff)));\n\
    \    }\n    \n    This diff() const {\n        if (coeff.empty()) {\n        \
    \    return This();\n        }\n        std::vector<T> c(coeff.size() - 1);\n\
    \        for (int i = 0; i < (int) c.size(); ++i) {\n            c[i] = T(i +\
    \ 1) * coeff[i + 1];\n        }\n        return This(c);\n    }\n    This integ()\
    \ const {\n        std::vector<T> c(coeff.size() + 1, T(0));\n        for (int\
    \ i = 0; i < (int) coeff.size(); ++i) {\n            c[i + 1] = coeff[i] / T(i\
    \ + 1);\n        }\n        return This(c);\n    }\n};\n#line 4 \"polynomial/fps_inv.hpp\"\
    \n\ntemplate <typename T, typename Mul>\nPolynomial<T, Mul> fps_inv(const Polynomial<T,\
    \ Mul> &f, int sz = -1) {\n    const std::vector<T> &coeff = f.vec();\n    assert(!coeff.empty()\
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
    \ - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();\n}\n"
  code: "#pragma once\n\n#include \"fps_inv.hpp\"\n\ntemplate <typename T, typename\
    \ Mul>\nPolynomial<T, Mul> fps_log(const Polynomial<T, Mul> &f, int sz = -1) {\n\
    \    const std::vector<T> &coeff = f.vec();\n    assert(!coeff.empty() && coeff[0]\
    \ == T(1));\n    if (sz == -1) {\n        sz = (int) coeff.size();\n    }\n  \
    \  assert(sz >= 0);\n    if (sz == 0) {\n        return Polynomial<T, Mul>();\n\
    \    }\n    return (f.diff().pre(sz - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();\n\
    }"
  dependsOn:
  - polynomial/fps_inv.hpp
  - polynomial/polynomial.hpp
  isVerificationFile: false
  path: polynomial/fps_log.hpp
  requiredBy:
  - polynomial/fps_pow.hpp
  timestamp: '2022-07-21 11:01:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/pow_of_formal_power_series.test.cpp
  - test/library_checker/pow_of_formal_power_series_acl.test.cpp
  - test/library_checker/log_of_formal_power_series_acl.test.cpp
  - test/library_checker/log_of_formal_power_series.test.cpp
documentation_of: polynomial/fps_log.hpp
layout: document
redirect_from:
- /library/polynomial/fps_log.hpp
- /library/polynomial/fps_log.hpp.html
title: polynomial/fps_log.hpp
---
