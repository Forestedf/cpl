---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/bitwise_and_convolution.test.cpp
    title: convolution/test/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/and_convolution.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = 0;\n    while ((1 << n) < (int) a.size())\
    \ {\n        ++n;\n    }\n    assert((int) a.size() == (1 << n));\n    assert((int)\
    \ b.size() == (1 << n));\n    \n    for (int d = 0; d < n; ++d) {\n        for\
    \ (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n        \
    \        a[i ^ (1 << d)] += a[i];\n                b[i ^ (1 << d)] += b[i];\n\
    \            }\n        }\n    }\n    for (int i = 0; i < (1 << n); ++i) {\n \
    \       a[i] *= b[i];\n    }\n    for (int d = 0; d < n; ++d) {\n        for (int\
    \ i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n             \
    \   a[i ^ (1 << d)] -= a[i];\n            }\n        }\n    }\n    \n    return\
    \ a;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nstd::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {\n \
    \   int n = 0;\n    while ((1 << n) < (int) a.size()) {\n        ++n;\n    }\n\
    \    assert((int) a.size() == (1 << n));\n    assert((int) b.size() == (1 << n));\n\
    \    \n    for (int d = 0; d < n; ++d) {\n        for (int i = 0; i < (1 << n);\
    \ ++i) {\n            if (i & (1 << d)) {\n                a[i ^ (1 << d)] +=\
    \ a[i];\n                b[i ^ (1 << d)] += b[i];\n            }\n        }\n\
    \    }\n    for (int i = 0; i < (1 << n); ++i) {\n        a[i] *= b[i];\n    }\n\
    \    for (int d = 0; d < n; ++d) {\n        for (int i = 0; i < (1 << n); ++i)\
    \ {\n            if (i & (1 << d)) {\n                a[i ^ (1 << d)] -= a[i];\n\
    \            }\n        }\n    }\n    \n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/and_convolution.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/bitwise_and_convolution.test.cpp
documentation_of: convolution/and_convolution.hpp
layout: document
redirect_from:
- /library/convolution/and_convolution.hpp
- /library/convolution/and_convolution.hpp.html
title: convolution/and_convolution.hpp
---
