---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/subset_convolution_internal.hpp
    title: convolution/subset_convolution_internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/other/subset_convolution_exp_log.test.cpp
    title: test/other/subset_convolution_exp_log.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/subset_convolution_log.hpp\"\n\n#line 2 \"convolution/subset_convolution_internal.hpp\"\
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
    } // namespace subset_convolution_internal\n#line 4 \"convolution/subset_convolution_log.hpp\"\
    \n\n#include <cassert>\n\ntemplate <typename T>\nstd::vector<T> _subset_conv_log(const\
    \ std::vector<T> &a, int to) {\n    std::vector<T> b(a.size());\n    for (int\
    \ i = 1; i < (int) a.size(); ++i) {\n        b[i] = a[i] * T(i);\n        for\
    \ (int j = 1; j <= std::min(to, i); ++j) {\n            b[i] -= a[j] * b[i - j];\n\
    \        }\n    }\n    for (int i = 1; i < (int) a.size(); ++i) {\n        b[i]\
    \ /= T(i);\n    }\n    return b;\n}\n\ntemplate <typename T>\nstd::vector<T> subset_convolution_log(const\
    \ std::vector<T> &a) {\n    int n = 0;\n    while ((1 << n) < (int) a.size())\
    \ {\n        ++n;\n    }\n    assert((int) a.size() == (1 << n));\n    assert(a[0]\
    \ == T(1));\n    \n    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n,\
    \ a);\n    for (int d = 0; d < n; ++ d) {\n        for (int i = 0; i < (1 << n);\
    \ ++i) {\n            if (i & (1 << d)) {\n                subset_convolution_internal::add(a_[i],\
    \ a_[i ^ (1 << d)], __builtin_popcount(i) - 1);\n            }\n        }\n  \
    \  }\n    for (int i = 0; i < (1 << n); ++i) {\n        a_[i] = _subset_conv_log(a_[i],\
    \ __builtin_popcount(i));\n    }\n    for (int d = 0; d < n; ++ d) {\n       \
    \ for (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n    \
    \            subset_convolution_internal::sub(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i));\n\
    \            }\n        }\n    }\n    return subset_convolution_internal::rev_setps(n,\
    \ a_);\n}\n"
  code: "#pragma once\n\n#include \"subset_convolution_internal.hpp\"\n\n#include\
    \ <cassert>\n\ntemplate <typename T>\nstd::vector<T> _subset_conv_log(const std::vector<T>\
    \ &a, int to) {\n    std::vector<T> b(a.size());\n    for (int i = 1; i < (int)\
    \ a.size(); ++i) {\n        b[i] = a[i] * T(i);\n        for (int j = 1; j <=\
    \ std::min(to, i); ++j) {\n            b[i] -= a[j] * b[i - j];\n        }\n \
    \   }\n    for (int i = 1; i < (int) a.size(); ++i) {\n        b[i] /= T(i);\n\
    \    }\n    return b;\n}\n\ntemplate <typename T>\nstd::vector<T> subset_convolution_log(const\
    \ std::vector<T> &a) {\n    int n = 0;\n    while ((1 << n) < (int) a.size())\
    \ {\n        ++n;\n    }\n    assert((int) a.size() == (1 << n));\n    assert(a[0]\
    \ == T(1));\n    \n    std::vector<std::vector<T>> a_ = subset_convolution_internal::setps(n,\
    \ a);\n    for (int d = 0; d < n; ++ d) {\n        for (int i = 0; i < (1 << n);\
    \ ++i) {\n            if (i & (1 << d)) {\n                subset_convolution_internal::add(a_[i],\
    \ a_[i ^ (1 << d)], __builtin_popcount(i) - 1);\n            }\n        }\n  \
    \  }\n    for (int i = 0; i < (1 << n); ++i) {\n        a_[i] = _subset_conv_log(a_[i],\
    \ __builtin_popcount(i));\n    }\n    for (int d = 0; d < n; ++ d) {\n       \
    \ for (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n    \
    \            subset_convolution_internal::sub(a_[i], a_[i ^ (1 << d)], __builtin_popcount(i));\n\
    \            }\n        }\n    }\n    return subset_convolution_internal::rev_setps(n,\
    \ a_);\n}\n"
  dependsOn:
  - convolution/subset_convolution_internal.hpp
  isVerificationFile: false
  path: convolution/subset_convolution_log.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/other/subset_convolution_exp_log.test.cpp
documentation_of: convolution/subset_convolution_log.hpp
layout: document
redirect_from:
- /library/convolution/subset_convolution_log.hpp
- /library/convolution/subset_convolution_log.hpp.html
title: convolution/subset_convolution_log.hpp
---
