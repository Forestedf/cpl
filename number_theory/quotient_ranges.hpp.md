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
  bundledCode: "#line 2 \"number_theory/quotient_ranges.hpp\"\n\n#include <vector>\n\
    #include <tuple>\n#include <cassert>\n\n// l, r, v: i \\in (l, r] \\implies n\
    \ // i = v\ntemplate <typename T>\nstd::vector<std::tuple<T, T, T>> quotient_ranges(T\
    \ n) {\n    assert(n >= 1);\n    std::vector<std::tuple<T, T, T>> ranges;\n  \
    \  for (T q = n; q > 0; q = n / (n / q + 1)) {\n        ranges.emplace_back(n\
    \ / (q + 1), n / q, q);\n    }\n    return ranges;\n}\n\n"
  code: "#pragma once\n\n#include <vector>\n#include <tuple>\n#include <cassert>\n\
    \n// l, r, v: i \\in (l, r] \\implies n // i = v\ntemplate <typename T>\nstd::vector<std::tuple<T,\
    \ T, T>> quotient_ranges(T n) {\n    assert(n >= 1);\n    std::vector<std::tuple<T,\
    \ T, T>> ranges;\n    for (T q = n; q > 0; q = n / (n / q + 1)) {\n        ranges.emplace_back(n\
    \ / (q + 1), n / q, q);\n    }\n    return ranges;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/quotient_ranges.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/quotient_ranges.hpp
layout: document
redirect_from:
- /library/number_theory/quotient_ranges.hpp
- /library/number_theory/quotient_ranges.hpp.html
title: number_theory/quotient_ranges.hpp
---
