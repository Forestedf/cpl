---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"graph/test/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n\
    #include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n#define\
    \ REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n) for (i32\
    \ i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3,\
    \ REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)\n\
    #define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\nusing i32\
    \ = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\nusing\
    \ f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing Vec\
    \ = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n    if\
    \ (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
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
    \  }\n} set_up_io;\n#line 2 \"graph/graph.hpp\"\n\n#line 7 \"graph/graph.hpp\"\
    \n\ntemplate <typename Edge>\nclass Graph {\n    std::vector<std::vector<Edge>>\
    \ edges;\n\npublic:\n    Graph() : edges() {}\n    Graph(int v) : edges(v) {\n\
    \        assert(v >= 0);\n    }\n    \n    std::vector<int> add_vertices(int n)\
    \ {\n        int v = (int) edges.size();\n        std::vector<int> idx(n);\n \
    \       std::iota(idx.begin(), idx.end(), v);\n        edges.resize(edges.size()\
    \ + n);\n        return idx;\n    }\n\n    template <typename... T>\n    void\
    \ add_directed_edge(int from, int to, T &&...val) {\n        assert(from >= 0\
    \ && from < (int) edges.size());\n        assert(to >= 0 && to < (int) edges.size());\n\
    \        edges[from].emplace_back(Edge(to, std::forward<T>(val)...));\n    }\n\
    \n    template <typename... T>\n    void add_undirected_edge(int u, int v, const\
    \ T &...val) {\n        assert(u >= 0 && u < (int) edges.size());\n        assert(v\
    \ >= 0 && v < (int) edges.size());\n        edges[u].emplace_back(Edge(v, val...));\n\
    \        edges[v].emplace_back(Edge(u, val...));\n    }\n\n    int size() const\
    \ {\n        return (int) edges.size();\n    }\n\n    const std::vector<Edge>\
    \ &operator[](int v) const {\n        assert(v >= 0 && v < (int) edges.size());\n\
    \        return edges[v];\n    }\n\n    std::vector<Edge> &operator[](int v) {\n\
    \        assert(v >= 0 && v < (int) edges.size());\n        return edges[v];\n\
    \    }\n};\n\nstruct UnweightedEdge {\n    int to;\n\n    UnweightedEdge(int t)\
    \ : to(t) {}\n    \n    explicit operator int() const {\n        return to;\n\
    \    }\n\n    using Weight = int;\n    Weight weight() const {\n        return\
    \ 1;\n    }\n};\n\ntemplate <typename T>\nstruct WeightedEdge {\n    int to;\n\
    \    T wt;\n\n    WeightedEdge(int t, const T &w) : to(t), wt(w) {}\n\n    explicit\
    \ operator int() const {\n        return to;\n    }\n\n    using Weight = T;\n\
    \    Weight weight() const {\n        return wt;\n    }\n};\n\n#line 2 \"graph/two_edge_connected_components.hpp\"\
    \n\n#line 6 \"graph/two_edge_connected_components.hpp\"\n\nclass TwoEdgeConnectedComponents\
    \ {\n    int comp_num;\n    std::vector<int> comp;\n    \npublic:\n    template\
    \ <typename G>\n    TwoEdgeConnectedComponents(const G &g) : comp_num(0), comp(g.size(),\
    \ -1) {\n        std::vector<int> ord(g.size(), -1);\n        std::vector<int>\
    \ low(g.size(), -1);\n        std::vector<int> found(g.size(), 0);\n        const\
    \ auto dfs0 = [&](const auto &dfs0, int v, int p, int &t) -> void {\n        \
    \    ord[v] = t++;\n            low[v] = ord[v];\n            bool par = false;\n\
    \            for (const auto &e : g[v]) {\n                int u = (int) e;\n\
    \                if (!found[u]) {\n                    found[u] = 1;\n       \
    \             dfs0(dfs0, u, v, t);\n                    low[v] = std::min(low[v],\
    \ low[u]);\n                }\n                bool back = ord[u] < ord[v];\n\
    \                if (u == p) {\n                    if (!par) {\n            \
    \            back = false;\n                        par = true;\n            \
    \        }\n                }\n                if (back) {\n                 \
    \   low[v] = std::min(low[v], ord[u]);\n                }\n            }\n   \
    \     };\n        int t = 0;\n        for (int v = 0; v < (int) g.size(); ++v)\
    \ {\n            if (!found[v]) {\n                found[v] = 1;\n           \
    \     dfs0(dfs0, v, -1, t);\n            }\n        }\n        const auto dfs1\
    \ = [&](const auto &dfs1, i32 v, i32 k) -> void {\n            comp[v] = k;\n\
    \            for (const auto &e : g[v]) {\n                int u = (int) e;\n\
    \                if (comp[u] == -1) {\n                    if (low[u] > ord[v])\
    \ {\n                        dfs1(dfs1, u, comp_num++);\n                    }\
    \ else {\n                        dfs1(dfs1, u, k);\n                    }\n \
    \               }\n            }\n        };\n        for (int v = 0; v < (int)\
    \ g.size(); ++v) {\n            if (comp[v] == -1) {\n                dfs1(dfs1,\
    \ v, comp_num++);\n            }\n        }\n    }\n    \n    int operator[](int\
    \ v) const {\n        return comp[v];\n    }\n    int compc() const {\n      \
    \  return comp_num;\n    }\n    \n    std::vector<std::vector<int>> groups() const\
    \ {\n        std::vector<std::vector<int>> gs(comp_num);\n        for (int i =\
    \ 0; i < (int) comp.size(); ++i) {\n            gs[comp[i]].push_back(i);\n  \
    \      }\n        return gs;\n    }\n};\n#line 8 \"graph/test/two_edge_connected_components.test.cpp\"\
    \n\nint main() {\n    i32 n, m;\n    cin >> n >> m;\n    Graph<i32> g(n);\n  \
    \  REP(i, m) {\n        i32 u, v;\n        cin >> u >> v;\n        g.add_undirected_edge(u,\
    \ v);\n    }\n    TwoEdgeConnectedComponents cc(g);\n    Vec<Vec<i32>> groups\
    \ = cc.groups();\n    cout << groups.size() << '\\n';\n    for (const Vec<i32>\
    \ &c : groups) {\n        cout << c.size();\n        for (i32 v : c) {\n     \
    \       cout << ' ' << v;\n        }\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../graph.hpp\"\
    \n#include \"../two_edge_connected_components.hpp\"\n\nint main() {\n    i32 n,\
    \ m;\n    cin >> n >> m;\n    Graph<i32> g(n);\n    REP(i, m) {\n        i32 u,\
    \ v;\n        cin >> u >> v;\n        g.add_undirected_edge(u, v);\n    }\n  \
    \  TwoEdgeConnectedComponents cc(g);\n    Vec<Vec<i32>> groups = cc.groups();\n\
    \    cout << groups.size() << '\\n';\n    for (const Vec<i32> &c : groups) {\n\
    \        cout << c.size();\n        for (i32 v : c) {\n            cout << ' '\
    \ << v;\n        }\n        cout << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/graph.hpp
  - graph/two_edge_connected_components.hpp
  isVerificationFile: true
  path: graph/test/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-08-26 11:10:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/two_edge_connected_components.test.cpp
- /verify/graph/test/two_edge_connected_components.test.cpp.html
title: graph/test/two_edge_connected_components.test.cpp
---
