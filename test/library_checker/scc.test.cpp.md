---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':question:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library_checker/scc.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\
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
    \     cout << fixed << setprecision(15);\n    }\n} set_up_io;\n#line 2 \"graph/graph.hpp\"\
    \n\n#line 7 \"graph/graph.hpp\"\n\ntemplate <typename Edge>\nclass Graph {\n \
    \   std::vector<std::vector<Edge>> edges;\n\npublic:\n    Graph() : edges() {}\n\
    \    Graph(int v) : edges(v) {\n        assert(v >= 0);\n    }\n    \n    std::vector<int>\
    \ add_vertices(int n) {\n        int v = (int) edges.size();\n        std::vector<int>\
    \ idx(n);\n        std::iota(idx.begin(), idx.end(), v);\n        edges.resize(edges.size()\
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
    \    }\n\n    using Weight = std::size_t;\n    Weight weight() const {\n     \
    \   return 1;\n    }\n};\n\ntemplate <typename T>\nstruct WeightedEdge {\n   \
    \ int to;\n    T wt;\n\n    WeightedEdge(int t, const T &w) : to(t), wt(w) {}\n\
    \n    explicit operator int() const {\n        return to;\n    }\n\n    using\
    \ Weight = T;\n    Weight weight() const {\n        return wt;\n    }\n};\n\n\
    #line 2 \"graph/strongly_connected_components.hpp\"\n\n#line 4 \"graph/strongly_connected_components.hpp\"\
    \n\ntemplate <typename G>\nclass StronglyConnectedComponents {    \n    std::vector<int>\
    \ comp_id;\n    int comp_num;\n    \npublic:\n    StronglyConnectedComponents(const\
    \ G &g) : comp_id(g.size(), -1), comp_num(0) {\n        int now = 0;\n       \
    \ std::vector<int> vs;\n        std::vector<int> ord(g.size(), -1);\n        std::vector<int>\
    \ low(g.size(), -1);\n        \n        const auto dfs = [&](const auto &dfs,\
    \ int v) -> void {\n            vs.push_back(v);\n            ord[v] = now++;\n\
    \            low[v] = ord[v];\n            for (int u : g[v]) {\n            \
    \    if (comp_id[u] != -1) {\n                    continue;\n                }\n\
    \                if (ord[u] == -1) {\n                    dfs(dfs, u);\n     \
    \           }\n                low[v] = std::min(low[v], low[u]);\n          \
    \  }\n            if (low[v] == ord[v]) {\n                while (true) {\n  \
    \                  int u = vs.back();\n                    vs.pop_back();\n  \
    \                  comp_id[u] = comp_num;\n                    if (u == v) {\n\
    \                        break;\n                    }\n                }\n  \
    \              ++comp_num;\n            }\n        };\n        \n        for (int\
    \ v = 0; v < (int) g.size(); ++v) {\n            if (ord[v] == -1) {\n       \
    \         dfs(dfs, v);\n            }\n        }\n        \n        for (int v\
    \ = 0; v < (int) g.size(); ++v) {\n            comp_id[v] = comp_num - 1 - comp_id[v];\n\
    \        }\n    }\n    \n    int comps() const {\n        return comp_num;\n \
    \   }\n\n    int operator[](int v) const {\n        assert(v >= 0 && v < (int)\
    \ comp_id.size());\n        return comp_id[v];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<std::vector<int>> ret(comp_num);\n   \
    \     for (int v = 0; v < (int) comp_id.size(); ++v) {\n            ret[comp_id[v]].push_back(v);\n\
    \        }\n        return ret;\n    }\n};\n\n#line 8 \"test/library_checker/scc.test.cpp\"\
    \n\nint main() {\n    i32 n, m;\n    cin >> n >> m;\n    Graph<i32> g(n);\n  \
    \  REP(e, m) {\n        i32 u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u,\
    \ v);\n    }\n    StronglyConnectedComponents<Graph<i32>> scc(g);\n    Vec<Vec<i32>>\
    \ groups = scc.groups();\n    cout << groups.size() << '\\n';\n    for (const\
    \ Vec<i32> &group : groups) {\n        cout << group.size();\n        for (i32\
    \ v : group) {\n            cout << ' ' << v;\n        }\n        cout << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#define FAST_IO\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/graph.hpp\"\
    \n#include \"../../graph/strongly_connected_components.hpp\"\n\nint main() {\n\
    \    i32 n, m;\n    cin >> n >> m;\n    Graph<i32> g(n);\n    REP(e, m) {\n  \
    \      i32 u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u, v);\n\
    \    }\n    StronglyConnectedComponents<Graph<i32>> scc(g);\n    Vec<Vec<i32>>\
    \ groups = scc.groups();\n    cout << groups.size() << '\\n';\n    for (const\
    \ Vec<i32> &group : groups) {\n        cout << group.size();\n        for (i32\
    \ v : group) {\n            cout << ' ' << v;\n        }\n        cout << '\\\
    n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/graph.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/library_checker/scc.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/scc.test.cpp
- /verify/test/library_checker/scc.test.cpp.html
title: test/library_checker/scc.test.cpp
---
