---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/taylor_shift.hpp\"\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T, typename Binom,\
    \ typename Mul>\nstd::vector<T> taylor_shift(std::vector<T> f, const T &c, const\
    \ Binom &binom) {\n    int n = (int) f.size();\n    for (int i = 0; i < n; ++i)\
    \ {\n        f[i] *= binom.fact(i);\n    }\n    std::reverse(f.begin(), f.end());\n\
    \    std::vector<T> g(n);\n    T pw(1);\n    for (int i = 0; i < n; ++i) {\n \
    \       g[i] = pw * binom.inv_fact(i);\n        pw *= c;\n    }\n    std::vector<T>\
    \ h = Mul::mul(std::move(f), std::move(g));\n    h.resize(n);\n    std::reverse(h.begin(),\
    \ h.end());\n    for (int i = 0; i < n; ++i) {\n        h[i] *= binom.inv_fact(i);\n\
    \    }\n    return h;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T, typename Binom, typename Mul>\nstd::vector<T> taylor_shift(std::vector<T>\
    \ f, const T &c, const Binom &binom) {\n    int n = (int) f.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        f[i] *= binom.fact(i);\n    }\n    std::reverse(f.begin(),\
    \ f.end());\n    std::vector<T> g(n);\n    T pw(1);\n    for (int i = 0; i < n;\
    \ ++i) {\n        g[i] = pw * binom.inv_fact(i);\n        pw *= c;\n    }\n  \
    \  std::vector<T> h = Mul::mul(std::move(f), std::move(g));\n    h.resize(n);\n\
    \    std::reverse(h.begin(), h.end());\n    for (int i = 0; i < n; ++i) {\n  \
    \      h[i] *= binom.inv_fact(i);\n    }\n    return h;\n}"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/taylor_shift.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial_taylor_shift.test.cpp
documentation_of: polynomial/taylor_shift.hpp
layout: document
redirect_from:
- /library/polynomial/taylor_shift.hpp
- /library/polynomial/taylor_shift.hpp.html
title: polynomial/taylor_shift.hpp
---
