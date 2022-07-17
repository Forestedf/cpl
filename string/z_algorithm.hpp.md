---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/zalgorithm.test.cpp
    title: test/library_checker/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <typename Cont>\nstd::vector<int> z_algorithm(const Cont &s) {\n    if (s.empty())\
    \ {\n        return std::vector<int>(0);\n    }\n    std::vector<int> z(s.size());\n\
    \    z[0] = static_cast<int>(s.size());\n    int i = 1, j = 0;\n    while (i <\
    \ static_cast<int>(s.size())) {\n        while (i + j < static_cast<int>(s.size())\
    \ && s[i + j] == s[j]) {\n            ++j;\n        }\n        z[i] = j;\n   \
    \     if (j == 0) {\n            ++i;\n            continue;\n        }\n    \
    \    int k = 1;\n        while (k < j && k + z[k] < j) {\n            z[i + k]\
    \ = z[k];\n            ++k;\n        }\n        i += k;\n        j -= k;\n   \
    \ }\n    return z;\n}\n\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename Cont>\nstd::vector<int>\
    \ z_algorithm(const Cont &s) {\n    if (s.empty()) {\n        return std::vector<int>(0);\n\
    \    }\n    std::vector<int> z(s.size());\n    z[0] = static_cast<int>(s.size());\n\
    \    int i = 1, j = 0;\n    while (i < static_cast<int>(s.size())) {\n       \
    \ while (i + j < static_cast<int>(s.size()) && s[i + j] == s[j]) {\n         \
    \   ++j;\n        }\n        z[i] = j;\n        if (j == 0) {\n            ++i;\n\
    \            continue;\n        }\n        int k = 1;\n        while (k < j &&\
    \ k + z[k] < j) {\n            z[i + k] = z[k];\n            ++k;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    return z;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
