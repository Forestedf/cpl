---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: polynomial/fps_div_at.hpp
    title: polynomial/fps_div_at.hpp
  - icon: ':question:'
    path: polynomial/fps_exp.hpp
    title: polynomial/fps_exp.hpp
  - icon: ':question:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':question:'
    path: polynomial/fps_log.hpp
    title: polynomial/fps_log.hpp
  - icon: ':question:'
    path: polynomial/fps_pow.hpp
    title: polynomial/fps_pow.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: polynomial/test/exp_of_formal_power_series.test.cpp
    title: polynomial/test/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: polynomial/test/exp_of_formal_power_series_acl.test.cpp
    title: polynomial/test/exp_of_formal_power_series_acl.test.cpp
  - icon: ':x:'
    path: polynomial/test/inv_of_formal_power_series.test.cpp
    title: polynomial/test/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: polynomial/test/inv_of_formal_power_series_acl.test.cpp
    title: polynomial/test/inv_of_formal_power_series_acl.test.cpp
  - icon: ':x:'
    path: polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: polynomial/test/log_of_formal_power_series.test.cpp
    title: polynomial/test/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: polynomial/test/log_of_formal_power_series_acl.test.cpp
    title: polynomial/test/log_of_formal_power_series_acl.test.cpp
  - icon: ':x:'
    path: polynomial/test/pow_of_formal_power_series.test.cpp
    title: polynomial/test/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: polynomial/test/pow_of_formal_power_series_acl.test.cpp
    title: polynomial/test/pow_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/exp_of_formal_power_series.test.cpp
    title: test/library_checker/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/exp_of_formal_power_series_acl.test.cpp
    title: test/library_checker/exp_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/inv_of_formal_power_series.test.cpp
    title: test/library_checker/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/inv_of_formal_power_series_acl.test.cpp
    title: test/library_checker/inv_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/polynomial.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\n#include <algorithm>\n\ntemplate <typename T,\
    \ typename Mul>\nclass Polynomial {\n    std::vector<T> coeff;\n    \npublic:\n\
    \    using This = Polynomial<T, Mul>;\n    \n    Polynomial() : coeff() {}\n \
    \   Polynomial(int n) : coeff(n, T(0)) {}\n    Polynomial(std::vector<T> c) :\
    \ coeff(std::move(c)) {}\n    \n    const std::vector<T> &vec() const {\n    \
    \    return coeff;\n    }\n    \n    int size() const {\n        return (int)\
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
    \        return This(c);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    #include <algorithm>\n\ntemplate <typename T, typename Mul>\nclass Polynomial\
    \ {\n    std::vector<T> coeff;\n    \npublic:\n    using This = Polynomial<T,\
    \ Mul>;\n    \n    Polynomial() : coeff() {}\n    Polynomial(int n) : coeff(n,\
    \ T(0)) {}\n    Polynomial(std::vector<T> c) : coeff(std::move(c)) {}\n    \n\
    \    const std::vector<T> &vec() const {\n        return coeff;\n    }\n    \n\
    \    int size() const {\n        return (int) coeff.size();\n    }\n    \n   \
    \ const T &operator[](int idx) const {\n        return coeff[idx];\n    }\n  \
    \  T &operator[](int idx) {\n        return coeff[idx];\n    }\n    \n    T at(int\
    \ idx) const {\n        if (idx < size()) {\n            return coeff[idx];\n\
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
    \ + 1);\n        }\n        return This(c);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/polynomial.hpp
  requiredBy:
  - polynomial/fps_log.hpp
  - polynomial/fps_inv.hpp
  - polynomial/fps_exp.hpp
  - polynomial/fps_pow.hpp
  - polynomial/fps_div_at.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - polynomial/test/inv_of_formal_power_series_acl.test.cpp
  - polynomial/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - polynomial/test/log_of_formal_power_series.test.cpp
  - polynomial/test/log_of_formal_power_series_acl.test.cpp
  - polynomial/test/exp_of_formal_power_series.test.cpp
  - polynomial/test/pow_of_formal_power_series_acl.test.cpp
  - polynomial/test/exp_of_formal_power_series_acl.test.cpp
  - polynomial/test/pow_of_formal_power_series.test.cpp
  - polynomial/test/inv_of_formal_power_series.test.cpp
  - test/library_checker/inv_of_formal_power_series_acl.test.cpp
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/library_checker/log_of_formal_power_series.test.cpp
  - test/library_checker/log_of_formal_power_series_acl.test.cpp
  - test/library_checker/exp_of_formal_power_series.test.cpp
  - test/library_checker/pow_of_formal_power_series_acl.test.cpp
  - test/library_checker/exp_of_formal_power_series_acl.test.cpp
  - test/library_checker/pow_of_formal_power_series.test.cpp
  - test/library_checker/inv_of_formal_power_series.test.cpp
documentation_of: polynomial/polynomial.hpp
layout: document
redirect_from:
- /library/polynomial/polynomial.hpp
- /library/polynomial/polynomial.hpp.html
title: polynomial/polynomial.hpp
---
