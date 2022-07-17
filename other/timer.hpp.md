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
  bundledCode: "#line 2 \"other/timer.hpp\"\n\n#include <chrono>\n\nclass Timer {\n\
    \    std::chrono::high_resolution_clock::time_point st;\n    \npublic:\n    Timer()\
    \ : st(std::chrono::high_resolution_clock::now()) {}\n    \n    void reset() {\n\
    \        st = std::chrono::high_resolution_clock::now();\n    }\n    \n    int\
    \ elapsed() {\n        auto ed = std::chrono::high_resolution_clock::now();\n\
    \        return (int) std::chrono::duration_cast<std::chrono::milliseconds>(ed\
    \ - st).count();\n    }\n};\n"
  code: "#pragma once\n\n#include <chrono>\n\nclass Timer {\n    std::chrono::high_resolution_clock::time_point\
    \ st;\n    \npublic:\n    Timer() : st(std::chrono::high_resolution_clock::now())\
    \ {}\n    \n    void reset() {\n        st = std::chrono::high_resolution_clock::now();\n\
    \    }\n    \n    int elapsed() {\n        auto ed = std::chrono::high_resolution_clock::now();\n\
    \        return (int) std::chrono::duration_cast<std::chrono::milliseconds>(ed\
    \ - st).count();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/timer.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/timer.hpp
layout: document
redirect_from:
- /library/other/timer.hpp
- /library/other/timer.hpp.html
title: other/timer.hpp
---
