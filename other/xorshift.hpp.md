---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/subset_convolution_exp_log.test.cpp
    title: convolution/test/subset_convolution_exp_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/xorshift.hpp\"\n\nclass XorShift64 {\n    unsigned\
    \ long long x;\n    \npublic:\n    XorShift64(unsigned long long seed) : x((seed\
    \ + 14213124131ull) ^ 103920984124ull) {}\n    \n    unsigned long long operator()()\
    \ {\n        x = x ^ (x << 13);\n        x = x ^ (x >> 7);\n        x = x ^ (x\
    \ << 17);\n        return x;\n    }\n    \n    template <typename T>\n    T uniform(T\
    \ mn, T mx) {\n        return mn + (T) ((*this)() % (mx - mn + 1));\n    }\n \
    \   \n    double as_f64() {\n        return (double) (*this)() / ~0ull;\n    }\n\
    };\n"
  code: "#pragma once\n\nclass XorShift64 {\n    unsigned long long x;\n    \npublic:\n\
    \    XorShift64(unsigned long long seed) : x((seed + 14213124131ull) ^ 103920984124ull)\
    \ {}\n    \n    unsigned long long operator()() {\n        x = x ^ (x << 13);\n\
    \        x = x ^ (x >> 7);\n        x = x ^ (x << 17);\n        return x;\n  \
    \  }\n    \n    template <typename T>\n    T uniform(T mn, T mx) {\n        return\
    \ mn + (T) ((*this)() % (mx - mn + 1));\n    }\n    \n    double as_f64() {\n\
    \        return (double) (*this)() / ~0ull;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/xorshift.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/wavelet_matrix.test.cpp
  - convolution/test/subset_convolution_exp_log.test.cpp
documentation_of: other/xorshift.hpp
layout: document
redirect_from:
- /library/other/xorshift.hpp
- /library/other/xorshift.hpp.html
title: other/xorshift.hpp
---
