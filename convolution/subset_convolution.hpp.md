---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution_internal.hpp
    title: convolution/subset_convolution_internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution.test.cpp
    title: convolution/test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/subset_convolution.hpp\"\n\n#line 2 \"convolution/subset_convolution_internal.hpp\"\
    \n\n#include <vector>\n#include <algorithm>\n\nnamespace subset_convolution_internal\
    \ {\n\ntemplate <typename T>\nvoid add(std::vector<T> &a, const std::vector<T>\
    \ &b, int to) {\n    for (int i = 0; i <= to; ++i) {\n        a[i] += b[i];\n\
    \    }\n}\n\ntemplate <typename T>\nvoid sub(std::vector<T> &a, const std::vector<T>\
    \ &b, int from) {\n    for (int i = from; i < (int) a.size(); ++i) {\n       \
    \ a[i] -= b[i];\n    }\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ setps(int n, const std::vector<T> &a) {\n    std::vector<std::vector<T>> sps(1\
    \ << n, std::vector<T>(n + 1, T(0)));\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        sps[i][__builtin_popcount(i)] = a[i];\n    }\n    return sps;\n}\n\
    \ntemplate <typename T>\nstd::vector<T> rev_setps(int n, const std::vector<std::vector<T>>\
    \ &sps) {\n    std::vector<T> a(1 << n);\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        a[i] = sps[i][__builtin_popcount(i)];\n    }\n    return a;\n}\n\n\
    } // namespace subset_convolution_internal\n#line 4 \"convolution/subset_convolution.hpp\"\
    \n\n#include <cassert>\n\ntemplate <typename T>\nstd::vector<T> _subset_conv_mul(const\
    \ std::vector<T> &a, const std::vector<T> &b, int to) {\n    std::vector<T> c(a.size(),\
    \ T(0));\n    for (int i = 0; i <= to; ++i) {\n        for (int j = 0; j <= std::min((int)\
    \ a.size() - i - 1, to); ++j) {\n            c[i + j] += a[i] * b[j];\n      \
    \  }\n    }\n    return c;\n}\n\ntemplate <typename T>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n    int n = 0;\n    while ((1\
    \ << n) < (int) a.size()) {\n        ++n;\n    }\n    assert((int) a.size() ==\
    \ (1 << n));\n    assert((int) b.size() == (1 << n));\n    \n    std::vector<std::vector<T>>\
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
    \ a_);\n}\n"
  code: "#pragma once\n\n#include \"subset_convolution_internal.hpp\"\n\n#include\
    \ <cassert>\n\ntemplate <typename T>\nstd::vector<T> _subset_conv_mul(const std::vector<T>\
    \ &a, const std::vector<T> &b, int to) {\n    std::vector<T> c(a.size(), T(0));\n\
    \    for (int i = 0; i <= to; ++i) {\n        for (int j = 0; j <= std::min((int)\
    \ a.size() - i - 1, to); ++j) {\n            c[i + j] += a[i] * b[j];\n      \
    \  }\n    }\n    return c;\n}\n\ntemplate <typename T>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n    int n = 0;\n    while ((1\
    \ << n) < (int) a.size()) {\n        ++n;\n    }\n    assert((int) a.size() ==\
    \ (1 << n));\n    assert((int) b.size() == (1 << n));\n    \n    std::vector<std::vector<T>>\
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
    \ a_);\n}"
  dependsOn:
  - convolution/subset_convolution_internal.hpp
  isVerificationFile: false
  path: convolution/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/subset_convolution.test.cpp
documentation_of: convolution/subset_convolution.hpp
layout: document
redirect_from:
- /library/convolution/subset_convolution.hpp
- /library/convolution/subset_convolution.hpp.html
title: convolution/subset_convolution.hpp
---
