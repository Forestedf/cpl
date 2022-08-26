---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_add_range_sum.hpp
    title: data_structure/range_add_range_sum.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/dsl_2_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n\
    #define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n)\
    \ for (i32 i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >=\
    \ 0; --i)\n#define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\n\
    using f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing\
    \ Vec = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\n\nistream &operator>>(istream\
    \ &is, i128 &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\n\
    istream &operator>>(istream &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x =\
    \ v;\n    return is;\n}\nostream &operator<<(ostream &os, u128 x) {\n    os <<\
    \ (u64) x;\n    return os;\n}\n\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n\
    [[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n\
    \    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n     \
    \   cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n  \
    \  }\n} set_up_io;\n#line 2 \"data_structure/range_add_range_sum.hpp\"\n\n#line\
    \ 2 \"data_structure/fenwick_tree.hpp\"\n\n#line 5 \"data_structure/fenwick_tree.hpp\"\
    \n\n#line 2 \"data_structure/operations.hpp\"\n\n#include <limits>\n#line 5 \"\
    data_structure/operations.hpp\"\n\ntemplate <typename T>\nstruct Add {\n    using\
    \ Value = T;\n    static Value id() {\n        return T(0);\n    }\n    static\
    \ Value op(const Value &lhs, const Value &rhs) {\n        return lhs + rhs;\n\
    \    }\n    static Value inv(const Value &x) {\n        return -x;\n    }\n};\n\
    \ntemplate <typename T>\nstruct Mul {\n    using Value = T;\n    static Value\
    \ id() {\n        return Value(1);\n    }\n    static Value op(const Value &lhs,\
    \ const Value &rhs) {\n        return lhs * rhs;\n    }\n    static Value inv(const\
    \ Value &x) {\n        return Value(1) / x;\n    }\n};\n\ntemplate <typename T>\n\
    struct Min {\n    using Value = T;\n    static Value id() {\n        return std::numeric_limits<T>::max();\n\
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
    \ {\n        assert(idx >= 0 && idx < (int) data.size());\n        for (; idx\
    \ < (int) data.size(); idx |= idx + 1) {\n            data[idx] = CommutativeGroup::op(data[idx],\
    \ x);\n        }\n    }\n\n    Value sum(int r) const {\n        assert(r >= 0\
    \ && r <= (int) data.size());\n        Value ret = CommutativeGroup::id();\n \
    \       for (; r > 0; r &= r - 1) {\n            ret = CommutativeGroup::op(ret,\
    \ data[r - 1]);\n        }\n        return ret;\n    }\n\n    Value sum(int l,\
    \ int r) const {\n        assert(l >= 0 && l <= r && r <= (int) data.size());\n\
    \        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));\n\
    \    }\n};\n\ntemplate <typename T>\nusing FenwickTreeAdd = FenwickTree<Add<T>>;\n\
    #line 4 \"data_structure/range_add_range_sum.hpp\"\n\ntemplate <typename T>\n\
    class RangeAddRangeSum {\n    int n;\n    FenwickTree<Add<T>> ft0;\n    FenwickTree<Add<T>>\
    \ ft1;\n    \npublic:\n    RangeAddRangeSum(int n) : n(n), ft0(n + 1), ft1(n +\
    \ 1) {}\n    \n    void add(int l, int r, const T &v) {\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        ft0.add(l, v);\n        ft0.add(r, -v);\n   \
    \     ft1.add(l, -T(l) * v);\n        ft1.add(r, T(r) * v);\n    }\n    \n   \
    \ T sum(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n \
    \       return T(r) * ft0.sum(r) + ft1.sum(r) - T(l) * ft0.sum(l) - ft1.sum(l);\n\
    \    }\n};\n#line 7 \"test/aoj/dsl_2_g.test.cpp\"\n\nint main() {\n    i32 n,\
    \ q;\n    cin >> n >> q;\n    RangeAddRangeSum<i64> rr(n);\n    REP(i, q) {\n\
    \        i32 type;\n        cin >> type;\n        if (type == 0) {\n         \
    \   i32 s, t;\n            i64 x;\n            cin >> s >> t >> x;\n         \
    \   --s;\n            rr.add(s, t, x);\n        } else {\n            i32 s, t;\n\
    \            cin >> s >> t;\n            --s;\n            cout << rr.sum(s, t)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/range_add_range_sum.hpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    RangeAddRangeSum<i64>\
    \ rr(n);\n    REP(i, q) {\n        i32 type;\n        cin >> type;\n        if\
    \ (type == 0) {\n            i32 s, t;\n            i64 x;\n            cin >>\
    \ s >> t >> x;\n            --s;\n            rr.add(s, t, x);\n        } else\
    \ {\n            i32 s, t;\n            cin >> s >> t;\n            --s;\n   \
    \         cout << rr.sum(s, t) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/range_add_range_sum.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  isVerificationFile: true
  path: test/aoj/dsl_2_g.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 19:28:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_g.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_g.test.cpp
- /verify/test/aoj/dsl_2_g.test.cpp.html
title: test/aoj/dsl_2_g.test.cpp
---
