---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: data_structure/union_find.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#define FAST_IO\n\n#line 1\
    \ \"template/template.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for\
    \ (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32) (m);\
    \ i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n\
    #define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)\n#define ALL(x) begin(x),\
    \ end(x)\n\nusing namespace std;\n\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing u128 = __uint128_t;\nusing i32 = signed int;\nusing i64 =\
    \ signed long long;\nusing i128 = __int128_t;\nusing f64 = double;\nusing f80\
    \ = long double;\n\ntemplate <typename T>\nusing Vec = vector<T>;\n\ntemplate\
    \ <typename T>\nbool chmin(T &x, const T &y) {\n    if (x > y) {\n        x =\
    \ y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename T>\n\
    bool chmax(T &x, const T &y) {\n    if (x < y) {\n        x = y;\n        return\
    \ true;\n    }\n    return false;\n}\n\nistream &operator>>(istream &is, i128\
    \ &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream &operator<<(ostream\
    \ &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\nistream &operator>>(istream\
    \ &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, u128 x) {\n    os << (u64) x;\n    return os;\n}\n\n\
    [[maybe_unused]] constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr i64\
    \ INF64 = 3000000000000000100;\nstruct SetUpIO {\n    SetUpIO() {\n#ifdef FAST_IO\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n#endif\n   \
    \     cout << fixed << setprecision(15);\n    }\n} set_up_io;\n#line 2 \"data_structure/union_find.hpp\"\
    \n\n#line 6 \"data_structure/union_find.hpp\"\n\nclass UnionFind {\n    std::vector<int>\
    \ par;\n\n    int _root(int v) {\n        if (par[v] < 0) {\n            return\
    \ v;\n        } else {\n            return par[v] = _root(par[v]);\n        }\n\
    \    }\n\npublic:\n    UnionFind(int n) : par(n, -1) {}\n\n    int root(int v)\
    \ {\n        assert(v >= 0 && v < (int) par.size());\n        return _root(v);\n\
    \    }\n\n    int size(int v) {\n        assert(v >= 0 && v < (int) par.size());\n\
    \        return -par[_root(v)];\n    }\n\n    bool unite(int u, int v) {\n   \
    \     assert(u >= 0 && u < (int) par.size() && v >= 0 && v < (int) par.size());\n\
    \        u = _root(u);\n        v = _root(v);\n        if (u == v) {\n       \
    \     return false;\n        }\n        if (par[u] < par[v]) {\n            std::swap(u,\
    \ v);\n        }\n        par[v] += par[u];\n        par[u] = v;\n        return\
    \ true;\n    }\n\n    bool same(int u, int v) {\n        assert(u >= 0 && u <\
    \ (int) par.size() && v >= 0 && v < (int) par.size());\n        return _root(u)\
    \ == _root(v);\n    }\n};\n\n#line 7 \"test/library_checker/unionfind.test.cpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n  \
    \  REP(qi, q) {\n        i32 t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          i32 u, v;\n            cin >> u >> v;\n            uf.unite(u, v);\n\
    \        } else {\n            i32 u, v;\n            cin >> u >> v;\n       \
    \     cout << uf.same(u, v) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#define\
    \ FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n  \
    \  REP(qi, q) {\n        i32 t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          i32 u, v;\n            cin >> u >> v;\n            uf.unite(u, v);\n\
    \        } else {\n            i32 u, v;\n            cin >> u >> v;\n       \
    \     cout << uf.same(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 16:00:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/unionfind.test.cpp
- /verify/test/library_checker/unionfind.test.cpp.html
title: test/library_checker/unionfind.test.cpp
---
