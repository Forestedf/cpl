---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: polynomial/polynomial.hpp
    title: polynomial/polynomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/fps_div_at.hpp\"\n\n#line 2 \"polynomial/polynomial.hpp\"\
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
    \        return This(c);\n    }\n};\n#line 4 \"polynomial/fps_div_at.hpp\"\n\n\
    // Bostan-Mori algorithm\ntemplate <typename T, typename Mul>\nT fps_div_at(Polynomial<T,\
    \ Mul> f, Polynomial<T, Mul> g, unsigned long long n) {\n    const auto even =\
    \ [](const Polynomial<T, Mul> &f) -> Polynomial<T, Mul> {\n        Polynomial<T,\
    \ Mul> g((f.size() + 1) / 2);\n        for (int i = 0; i < g.size(); ++i) {\n\
    \            g[i] = f[2 * i];\n        }\n        return g;\n    };\n    const\
    \ auto odd = [](const Polynomial<T, Mul> &f) -> Polynomial<T, Mul> {\n       \
    \ Polynomial<T, Mul> g(f.size() / 2);\n        for (int i = 0; i < g.size(); ++i)\
    \ {\n            g[i] = f[2 * i + 1];\n        }\n        return g;\n    };\n\
    \    assert(g.size() > 0 && g[0] != T(0));\n    while (n > 0) {\n        Polynomial<T,\
    \ Mul> g_ = g;\n        for (int i = 1; i < g_.size(); i += 2) {\n           \
    \ g_[i] = -g_[i];\n        }\n        g = even(g * g_);\n        Polynomial<T,\
    \ Mul> tmp_f = f * g_;\n        if (n % 2 == 1) {\n            f = odd(tmp_f);\n\
    \        } else {\n            f = even(tmp_f);\n        }\n        n /= 2;\n\
    \    }\n    if (f.size() == 0) {\n        return T(0);\n    } else {\n       \
    \ return f[0] / g[0];\n    }\n}\n"
  code: "#pragma once\n\n#include \"polynomial.hpp\"\n\n// Bostan-Mori algorithm\n\
    template <typename T, typename Mul>\nT fps_div_at(Polynomial<T, Mul> f, Polynomial<T,\
    \ Mul> g, unsigned long long n) {\n    const auto even = [](const Polynomial<T,\
    \ Mul> &f) -> Polynomial<T, Mul> {\n        Polynomial<T, Mul> g((f.size() + 1)\
    \ / 2);\n        for (int i = 0; i < g.size(); ++i) {\n            g[i] = f[2\
    \ * i];\n        }\n        return g;\n    };\n    const auto odd = [](const Polynomial<T,\
    \ Mul> &f) -> Polynomial<T, Mul> {\n        Polynomial<T, Mul> g(f.size() / 2);\n\
    \        for (int i = 0; i < g.size(); ++i) {\n            g[i] = f[2 * i + 1];\n\
    \        }\n        return g;\n    };\n    assert(g.size() > 0 && g[0] != T(0));\n\
    \    while (n > 0) {\n        Polynomial<T, Mul> g_ = g;\n        for (int i =\
    \ 1; i < g_.size(); i += 2) {\n            g_[i] = -g_[i];\n        }\n      \
    \  g = even(g * g_);\n        Polynomial<T, Mul> tmp_f = f * g_;\n        if (n\
    \ % 2 == 1) {\n            f = odd(tmp_f);\n        } else {\n            f =\
    \ even(tmp_f);\n        }\n        n /= 2;\n    }\n    if (f.size() == 0) {\n\
    \        return T(0);\n    } else {\n        return f[0] / g[0];\n    }\n}"
  dependsOn:
  - polynomial/polynomial.hpp
  isVerificationFile: false
  path: polynomial/fps_div_at.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: polynomial/fps_div_at.hpp
layout: document
redirect_from:
- /library/polynomial/fps_div_at.hpp
- /library/polynomial/fps_div_at.hpp.html
title: polynomial/fps_div_at.hpp
---
