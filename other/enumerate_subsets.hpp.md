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
  bundledCode: "#line 2 \"other/enumerate_subsets.hpp\"\n\nstruct EnumerateSubset\
    \ {\n    struct Iterator {\n        unsigned st;\n        unsigned cur;\n    \
    \    Iterator &operator++() {\n            if (cur == 0) {\n                cur\
    \ = ~(0u);\n            } else {\n                cur = (cur - 1) & st;\n    \
    \        }\n            return *this;\n        }\n        unsigned operator*()\
    \ const {\n            return cur;\n            //return st ^ cur;\n        }\n\
    \        friend bool operator!=(const EnumerateSubset::Iterator &lhs, const EnumerateSubset::Iterator\
    \ &rhs) {\n            return lhs.cur != rhs.cur;\n        }\n    };\n    \n \
    \   unsigned st;\n    EnumerateSubset(unsigned s) : st(s) {}\n    \n    Iterator\
    \ begin() const {\n        return Iterator{st, st};\n    }\n    Iterator end()\
    \ const {\n        return Iterator{st, ~(0u)};\n    }\n};\n"
  code: "#pragma once\n\nstruct EnumerateSubset {\n    struct Iterator {\n       \
    \ unsigned st;\n        unsigned cur;\n        Iterator &operator++() {\n    \
    \        if (cur == 0) {\n                cur = ~(0u);\n            } else {\n\
    \                cur = (cur - 1) & st;\n            }\n            return *this;\n\
    \        }\n        unsigned operator*() const {\n            return cur;\n  \
    \          //return st ^ cur;\n        }\n        friend bool operator!=(const\
    \ EnumerateSubset::Iterator &lhs, const EnumerateSubset::Iterator &rhs) {\n  \
    \          return lhs.cur != rhs.cur;\n        }\n    };\n    \n    unsigned st;\n\
    \    EnumerateSubset(unsigned s) : st(s) {}\n    \n    Iterator begin() const\
    \ {\n        return Iterator{st, st};\n    }\n    Iterator end() const {\n   \
    \     return Iterator{st, ~(0u)};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/enumerate_subsets.hpp
  requiredBy: []
  timestamp: '2022-07-31 15:37:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/enumerate_subsets.hpp
layout: document
redirect_from:
- /library/other/enumerate_subsets.hpp
- /library/other/enumerate_subsets.hpp.html
title: other/enumerate_subsets.hpp
---
