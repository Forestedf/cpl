---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"data_structure/operations.hpp\"\n\n#include <limits>\n\
    #include <utility>\n\ntemplate <typename T>\nstruct Add {\n    using Value = T;\n\
    \    static Value id() {\n        return T(0);\n    }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) {\n        return lhs + rhs;\n    }\n    static\
    \ Value inv(const Value &x) {\n        return -x;\n    }\n};\n\ntemplate <typename\
    \ T>\nstruct Mul {\n    using Value = T;\n    static Value id() {\n        return\
    \ Value(1);\n    }\n    static Value op(const Value &lhs, const Value &rhs) {\n\
    \        return lhs * rhs;\n    }\n    static Value inv(const Value &x) {\n  \
    \      return Value(1) / x;\n    }\n};\n\ntemplate <typename T>\nstruct Min {\n\
    \    using Value = T;\n    static Value id() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::min(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Max {\n    using\
    \ Value = T;\n    static Value id() {\n        return std::numeric_limits<Value>::min();\n\
    \    }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::max(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Xor {\n    using\
    \ Value = T;\n    static Value id() {\n        return T(0);\n    }\n    static\
    \ Value op(const Value &lhs, const Value &rhs) {\n        return lhs ^ rhs;\n\
    \    }\n    static Value inv(const Value &x) {\n        return x;\n    }\n};\n\
    \ntemplate <typename Monoid>\nstruct Reversible {\n    using Value = std::pair<typename\
    \ Monoid::Value, typename Monoid::Value>;\n    static Value id() {\n        return\
    \ Value(Monoid::id(), Monoid::id());\n    }\n    static Value op(const Value &v1,\
    \ const Value &v2) {\n        return Value(\n            Monoid::op(v1.first,\
    \ v2.first),\n            Monoid::op(v2.second, v1.second));\n    }\n};\n\n#line\
    \ 7 \"data_structure/fenwick_tree.hpp\"\n\ntemplate <typename CommutativeGroup>\n\
    class FenwickTree {\npublic:\n    using Value = typename CommutativeGroup::Value;\n\
    \nprivate:\n    std::vector<Value> data;\n\npublic:\n    FenwickTree(int n) :\
    \ data(n, CommutativeGroup::id()) {}\n\n    void add(int idx, const Value &x)\
    \ {\n        assert(idx >= 0 && idx < static_cast<int>(data.size()));\n      \
    \  for (; idx < static_cast<int>(data.size()); idx |= idx + 1) {\n           \
    \ data[idx] = CommutativeGroup::op(data[idx], x);\n        }\n    }\n\n    Value\
    \ sum(int r) const {\n        assert(r >= 0 && r <= static_cast<int>(data.size()));\n\
    \        Value ret = CommutativeGroup::id();\n        for (; r > 0; r &= r - 1)\
    \ {\n            ret = CommutativeGroup::op(ret, data[r - 1]);\n        }\n  \
    \      return ret;\n    }\n\n    Value sum(int l, int r) const {\n        assert(l\
    \ >= 0 && l <= r && r <= static_cast<int>(data.size()));\n        return CommutativeGroup::op(sum(r),\
    \ CommutativeGroup::inv(sum(l)));\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"operations.hpp\"\
    \n\ntemplate <typename CommutativeGroup>\nclass FenwickTree {\npublic:\n    using\
    \ Value = typename CommutativeGroup::Value;\n\nprivate:\n    std::vector<Value>\
    \ data;\n\npublic:\n    FenwickTree(int n) : data(n, CommutativeGroup::id()) {}\n\
    \n    void add(int idx, const Value &x) {\n        assert(idx >= 0 && idx < static_cast<int>(data.size()));\n\
    \        for (; idx < static_cast<int>(data.size()); idx |= idx + 1) {\n     \
    \       data[idx] = CommutativeGroup::op(data[idx], x);\n        }\n    }\n\n\
    \    Value sum(int r) const {\n        assert(r >= 0 && r <= static_cast<int>(data.size()));\n\
    \        Value ret = CommutativeGroup::id();\n        for (; r > 0; r &= r - 1)\
    \ {\n            ret = CommutativeGroup::op(ret, data[r - 1]);\n        }\n  \
    \      return ret;\n    }\n\n    Value sum(int l, int r) const {\n        assert(l\
    \ >= 0 && l <= r && r <= static_cast<int>(data.size()));\n        return CommutativeGroup::op(sum(r),\
    \ CommutativeGroup::inv(sum(l)));\n    }\n};\n"
  dependsOn:
  - data_structure/operations.hpp
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/data_structure/fenwick_tree.hpp
- /library/data_structure/fenwick_tree.hpp.html
title: data_structure/fenwick_tree.hpp
---
