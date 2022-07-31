---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_tree.hpp
    title: data_structure/range_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <iomanip>\n#include <iostream>\n#include <list>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define OVERRIDE(a,\
    \ b, c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define\
    \ REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...)\
    \ OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i\
    \ = (i32) (n) - 1; i >= 0; --i)\n#define ALL(x) begin(x), end(x)\n\nusing namespace\
    \ std;\n\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128\
    \ = __uint128_t;\nusing i32 = signed int;\nusing i64 = signed long long;\nusing\
    \ i128 = __int128_t;\nusing f64 = double;\nusing f80 = long double;\n\ntemplate\
    \ <typename T>\nusing Vec = vector<T>;\n\ntemplate <typename T>\nbool chmin(T\
    \ &x, const T &y) {\n    if (x > y) {\n        x = y;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <typename T>\nbool chmax(T &x, const T\
    \ &y) {\n    if (x < y) {\n        x = y;\n        return true;\n    }\n    return\
    \ false;\n}\n\nistream &operator>>(istream &is, i128 &x) {\n    i64 v;\n    is\
    \ >> v;\n    x = v;\n    return is;\n}\nostream &operator<<(ostream &os, i128\
    \ x) {\n    os << (i64) x;\n    return os;\n}\nistream &operator>>(istream &is,\
    \ u128 &x) {\n    u64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, u128 x) {\n    os << (u64) x;\n    return os;\n}\n\n\
    [[maybe_unused]] constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr i64\
    \ INF64 = 3000000000000000100;\nstruct SetUpIO {\n    SetUpIO() {\n#ifdef FAST_IO\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n#endif\n   \
    \     cout << fixed << setprecision(15);\n    }\n} set_up_io;\n#line 2 \"data_structure/range_tree.hpp\"\
    \n\n#line 5 \"data_structure/range_tree.hpp\"\n\ntemplate <typename Coordinate,\
    \ typename CommutativeGroup>\nclass RangeTree {\npublic:\n    using Value = typename\
    \ CommutativeGroup::Value;\n    \nprivate:\n    struct Node {\n        std::vector<Coordinate>\
    \ ys;\n        std::vector<Value> cum;\n        \n        Value sum(Coordinate\
    \ yl, Coordinate yr) const {\n            int yli = (int) (std::lower_bound(ys.begin(),\
    \ ys.end(), yl) - ys.begin());\n            int yri = (int) (std::lower_bound(ys.begin(),\
    \ ys.end(), yr) - ys.begin());\n            return CommutativeGroup::op(CommutativeGroup::inv(cum[yli]),\
    \ cum[yri]);\n        }\n    };\n    \n    static void dedup(std::vector<Coordinate>\
    \ &xs) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n    static int index(const std::vector<Coordinate>\
    \ &xs, int x) {\n        return (int) (std::lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin());\n    }\n    \n    std::vector<Node> nodes;\n    std::vector<Coordinate>\
    \ xs;\n    \npublic:\n    RangeTree(const std::vector<std::tuple<Coordinate, Coordinate,\
    \ Value>> &pts) : nodes(), xs() {\n        xs.reserve(pts.size());\n        for\
    \ (const auto &[x, _y, _w] : pts) {\n            xs.push_back(x);\n        }\n\
    \        dedup(xs);\n        nodes.resize(xs.size());\n        for (const auto\
    \ &[x, y, _w] : pts) {\n            int xi = index(xs, x);\n            for (;\
    \ xi < (int) xs.size(); xi |= xi + 1) {\n                nodes[xi].ys.push_back(y);\n\
    \            }\n        }\n        for (Node &node : nodes) {\n            dedup(node.ys);\n\
    \            node.cum.resize(node.ys.size() + 1, CommutativeGroup::id());\n  \
    \      }\n        for (const auto &[x, y, w] : pts) {\n            int xi = index(xs,\
    \ x);\n            for (; xi < (int) xs.size(); xi |= xi + 1) {\n            \
    \    int yi = index(nodes[xi].ys, y);\n                nodes[xi].cum[yi + 1] =\
    \ CommutativeGroup::op(nodes[xi].cum[yi + 1], w);\n            }\n        }\n\
    \        for (Node &node : nodes) {\n            for (int i = 1; i < (int) node.cum.size();\
    \ ++i) {\n                node.cum[i] = CommutativeGroup::op(node.cum[i - 1],\
    \ node.cum[i]);\n            }\n        }\n    }\n    \n    Value sum(Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        int xri = index(xs, xr);\n\
    \        Value s = CommutativeGroup::id();\n        for (; xri > 0; xri &= xri\
    \ - 1) {\n            s = CommutativeGroup::op(s, nodes[xri - 1].sum(yl, yr));\n\
    \        }\n        return s;\n    }\n    \n    Value sum(Coordinate xl, Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        Value l = sum(xl, yl, yr),\
    \ r = sum(xr, yl, yr);\n        return CommutativeGroup::op(r, CommutativeGroup::inv(l));\n\
    \    }\n};\n#line 2 \"data_structure/operations.hpp\"\n\n#include <limits>\n#line\
    \ 5 \"data_structure/operations.hpp\"\n\ntemplate <typename T>\nstruct Add {\n\
    \    using Value = T;\n    static Value id() {\n        return T(0);\n    }\n\
    \    static Value op(const Value &lhs, const Value &rhs) {\n        return lhs\
    \ + rhs;\n    }\n    static Value inv(const Value &x) {\n        return -x;\n\
    \    }\n};\n\ntemplate <typename T>\nstruct Mul {\n    using Value = T;\n    static\
    \ Value id() {\n        return Value(1);\n    }\n    static Value op(const Value\
    \ &lhs, const Value &rhs) {\n        return lhs * rhs;\n    }\n    static Value\
    \ inv(const Value &x) {\n        return Value(1) / x;\n    }\n};\n\ntemplate <typename\
    \ T>\nstruct Min {\n    using Value = T;\n    static Value id() {\n        return\
    \ std::numeric_limits<T>::max();\n    }\n    static Value op(const Value &lhs,\
    \ const Value &rhs) {\n        return std::min(lhs, rhs);\n    }\n};\n\ntemplate\
    \ <typename T>\nstruct Max {\n    using Value = T;\n    static Value id() {\n\
    \        return std::numeric_limits<Value>::min();\n    }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) {\n        return std::max(lhs, rhs);\n    }\n\
    };\n\ntemplate <typename T>\nstruct Xor {\n    using Value = T;\n    static Value\
    \ id() {\n        return T(0);\n    }\n    static Value op(const Value &lhs, const\
    \ Value &rhs) {\n        return lhs ^ rhs;\n    }\n    static Value inv(const\
    \ Value &x) {\n        return x;\n    }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ Reversible {\n    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;\n\
    \    static Value id() {\n        return Value(Monoid::id(), Monoid::id());\n\
    \    }\n    static Value op(const Value &v1, const Value &v2) {\n        return\
    \ Value(\n            Monoid::op(v1.first, v2.first),\n            Monoid::op(v2.second,\
    \ v1.second));\n    }\n};\n\n#line 6 \"test/library_checker/rectangle_sum.test.cpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<tuple<i32, i32, i64>>\
    \ pts(n);\n    for (auto &[x, y, w] : pts) {\n        cin >> x >> y >> w;\n  \
    \  }\n    RangeTree<i32, Add<i64>> range_tree(pts);\n    REP(qi, q) {\n      \
    \  i32 l, d, r, u;\n        cin >> l >> d >> r >> u;\n        cout << range_tree.sum(l,\
    \ r, d, u) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../data_structure/range_tree.hpp\"\
    \n#include \"../../data_structure/operations.hpp\"\n\nint main() {\n    i32 n,\
    \ q;\n    cin >> n >> q;\n    Vec<tuple<i32, i32, i64>> pts(n);\n    for (auto\
    \ &[x, y, w] : pts) {\n        cin >> x >> y >> w;\n    }\n    RangeTree<i32,\
    \ Add<i64>> range_tree(pts);\n    REP(qi, q) {\n        i32 l, d, r, u;\n    \
    \    cin >> l >> d >> r >> u;\n        cout << range_tree.sum(l, r, d, u) << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/range_tree.hpp
  - data_structure/operations.hpp
  isVerificationFile: true
  path: test/library_checker/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 17:23:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/rectangle_sum.test.cpp
- /verify/test/library_checker/rectangle_sum.test.cpp.html
title: test/library_checker/rectangle_sum.test.cpp
---
