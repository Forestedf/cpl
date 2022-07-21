---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/staticrmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#define FAST_IO\n\n#line 1\
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
    \     cout << fixed << setprecision(15);\n    }\n} set_up_io;\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n\n#line 7 \"data_structure/sparse_table.hpp\"\n#include <functional>\n\ntemplate\
    \ <typename T, typename F = std::less<T>>\nclass SparseTable {\n    std::vector<std::vector<T>>\
    \ table;\n    int s;\n    const F f;\n\n    int log2(int n) const {\n        return\
    \ 31 - __builtin_clz(n);\n    }\n    \n    T min2(const T &x, const T &y) const\
    \ {\n        if (f(x, y)) {\n            return x;\n        } else {\n       \
    \     return y;\n        }\n    }\n\npublic:\n    SparseTable(std::vector<T> arr,\
    \ F _f = F()) : s(static_cast<int>(arr.size())), f(std::move(_f)) {\n        if\
    \ (s == 0) {\n            return;\n        }\n        int m = log2(s);\n     \
    \   table.resize(m + 1);\n        table[0] = std::move(arr);\n        for (int\
    \ i = 1; i <= m; ++i) {\n            int w = 1 << i;\n            table[i].resize(s\
    \ - w + 1);\n            for (int j = 0; j < static_cast<int>(table[i].size());\
    \ ++j) {\n                table[i][j] = min2(table[i - 1][j], table[i - 1][j +\
    \ (w >> 1)]);\n            }\n        }\n    }\n\n    int size() const {\n   \
    \     return s;\n    }\n\n    // not empty\n    T min(int l, int r) const {\n\
    \        assert(l >= 0 && l < r && r <= s);\n        int m = log2(r - l);\n  \
    \      return min2(table[m][l], table[m][r - (1 << m)]);\n    }\n};\n\n#line 7\
    \ \"test/library_checker/staticrmq.test.cpp\"\n\nint main() {\n    i32 n, q;\n\
    \    cin >> n >> q;\n    Vec<i32> a(n);\n    REP(i, n) {\n        cin >> a[i];\n\
    \    }\n    SparseTable<i32> sp(a);\n    REP(qi, q) {\n        i32 l, r;\n   \
    \     cin >> l >> r;\n        cout << sp.min(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#define\
    \ FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/sparse_table.hpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<i32> a(n);\n    REP(i,\
    \ n) {\n        cin >> a[i];\n    }\n    SparseTable<i32> sp(a);\n    REP(qi,\
    \ q) {\n        i32 l, r;\n        cin >> l >> r;\n        cout << sp.min(l, r)\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/library_checker/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-07-18 18:57:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/staticrmq.test.cpp
- /verify/test/library_checker/staticrmq.test.cpp.html
title: test/library_checker/staticrmq.test.cpp
---
