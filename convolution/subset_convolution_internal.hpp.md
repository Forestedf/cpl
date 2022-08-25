---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: convolution/subset_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution_exp.hpp
    title: convolution/subset_convolution_exp.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution_log.hpp
    title: convolution/subset_convolution_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution.test.cpp
    title: convolution/test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution_exp_log.test.cpp
    title: convolution/test/subset_convolution_exp_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/subset_convolution.test.cpp
    title: test/library_checker/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/other/subset_convolution_exp_log.test.cpp
    title: test/other/subset_convolution_exp_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/subset_convolution_internal.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n\nnamespace subset_convolution_internal {\n\n\
    template <typename T>\nvoid add(std::vector<T> &a, const std::vector<T> &b, int\
    \ to) {\n    for (int i = 0; i <= to; ++i) {\n        a[i] += b[i];\n    }\n}\n\
    \ntemplate <typename T>\nvoid sub(std::vector<T> &a, const std::vector<T> &b,\
    \ int from) {\n    for (int i = from; i < (int) a.size(); ++i) {\n        a[i]\
    \ -= b[i];\n    }\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>> setps(int\
    \ n, const std::vector<T> &a) {\n    std::vector<std::vector<T>> sps(1 << n, std::vector<T>(n\
    \ + 1, T(0)));\n    for (int i = 0; i < (1 << n); ++i) {\n        sps[i][__builtin_popcount(i)]\
    \ = a[i];\n    }\n    return sps;\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ rev_setps(int n, const std::vector<std::vector<T>> &sps) {\n    std::vector<T>\
    \ a(1 << n);\n    for (int i = 0; i < (1 << n); ++i) {\n        a[i] = sps[i][__builtin_popcount(i)];\n\
    \    }\n    return a;\n}\n\n} // namespace subset_convolution_internal\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace subset_convolution_internal\
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
    } // namespace subset_convolution_internal"
  dependsOn: []
  isVerificationFile: false
  path: convolution/subset_convolution_internal.hpp
  requiredBy:
  - convolution/subset_convolution_exp.hpp
  - convolution/subset_convolution.hpp
  - convolution/subset_convolution_log.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/subset_convolution.test.cpp
  - test/other/subset_convolution_exp_log.test.cpp
  - convolution/test/subset_convolution.test.cpp
  - convolution/test/subset_convolution_exp_log.test.cpp
documentation_of: convolution/subset_convolution_internal.hpp
layout: document
redirect_from:
- /library/convolution/subset_convolution_internal.hpp
- /library/convolution/subset_convolution_internal.hpp.html
title: convolution/subset_convolution_internal.hpp
---
