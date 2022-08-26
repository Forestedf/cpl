---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"string/test/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \  }\n} set_up_io;\n#line 2 \"string/z_algorithm.hpp\"\n\n#line 4 \"string/z_algorithm.hpp\"\
    \n\ntemplate <typename Cont>\nstd::vector<int> z_algorithm(const Cont &s) {\n\
    \    if (s.empty()) {\n        return std::vector<int>(0);\n    }\n    std::vector<int>\
    \ z(s.size());\n    z[0] = (int) s.size();\n    int i = 1, j = 0;\n    while (i\
    \ < (int) s.size()) {\n        while (i + j < (int) s.size() && s[i + j] == s[j])\
    \ {\n            ++j;\n        }\n        z[i] = j;\n        if (j == 0) {\n \
    \           ++i;\n            continue;\n        }\n        int k = 1;\n     \
    \   while (k < j && k + z[k] < j) {\n            z[i + k] = z[k];\n          \
    \  ++k;\n        }\n        i += k;\n        j -= k;\n    }\n    return z;\n}\n\
    \n#line 7 \"string/test/zalgorithm.test.cpp\"\n\nint main() {\n    string s;\n\
    \    cin >> s;\n    Vec<i32> z = z_algorithm(s);\n    REP(i, s.size()) {\n   \
    \     cout << z[i] << \" \\n\"[i + 1 == s.size()];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#define\
    \ FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../string/z_algorithm.hpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    Vec<i32> z = z_algorithm(s);\n\
    \    REP(i, s.size()) {\n        cout << z[i] << \" \\n\"[i + 1 == s.size()];\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: string/test/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 20:04:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: string/test/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/string/test/zalgorithm.test.cpp
- /verify/string/test/zalgorithm.test.cpp.html
title: string/test/zalgorithm.test.cpp
---
