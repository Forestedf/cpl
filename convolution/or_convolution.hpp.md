---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/or_convolution.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <typename T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = 0;\n    while ((1 << n) < (int) a.size())\
    \ {\n        ++n;\n    }\n    assert((int) a.size() == (1 << n));\n    assert((int)\
    \ b.size() == (1 << n));\n    \n    for (int d = 0; d < n; ++d) {\n        for\
    \ (int i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n        \
    \        a[i] += a[i ^ (1 << d)];\n                b[i] += b[i ^ (1 << d)];\n\
    \            }\n        }\n    }\n    for (int i = 0; i < (1 << n); ++i) {\n \
    \       a[i] *= b[i];\n    }\n    for (int d = 0; d < n; ++d) {\n        for (int\
    \ i = 0; i < (1 << n); ++i) {\n            if (i & (1 << d)) {\n             \
    \   a[i] -= a[i ^ (1 << d)];\n            }\n        }\n    }\n    \n    return\
    \ a;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nstd::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {\n  \
    \  int n = 0;\n    while ((1 << n) < (int) a.size()) {\n        ++n;\n    }\n\
    \    assert((int) a.size() == (1 << n));\n    assert((int) b.size() == (1 << n));\n\
    \    \n    for (int d = 0; d < n; ++d) {\n        for (int i = 0; i < (1 << n);\
    \ ++i) {\n            if (i & (1 << d)) {\n                a[i] += a[i ^ (1 <<\
    \ d)];\n                b[i] += b[i ^ (1 << d)];\n            }\n        }\n \
    \   }\n    for (int i = 0; i < (1 << n); ++i) {\n        a[i] *= b[i];\n    }\n\
    \    for (int d = 0; d < n; ++d) {\n        for (int i = 0; i < (1 << n); ++i)\
    \ {\n            if (i & (1 << d)) {\n                a[i] -= a[i ^ (1 << d)];\n\
    \            }\n        }\n    }\n    \n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/or_convolution.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/or_convolution.hpp
layout: document
redirect_from:
- /library/convolution/or_convolution.hpp
- /library/convolution/or_convolution.hpp.html
title: convolution/or_convolution.hpp
---
