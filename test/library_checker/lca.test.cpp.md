---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: graph/heavy_light_decomposition.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library_checker/lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\
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
    #line 2 \"graph/heavy_light_decomposition.hpp\"\n\n#line 7 \"graph/heavy_light_decomposition.hpp\"\
    \n\nclass HeavyLightDecomposition {\n    std::vector<int> siz;\n    std::vector<int>\
    \ par;\n    std::vector<int> hea;\n    std::vector<int> in;\n    std::vector<int>\
    \ out;\n    std::vector<int> dep;\n    std::vector<int> rev;\n\n    template <typename\
    \ G>\n    void dfs1(G &g, int v) {\n        if (!g[v].empty() && (int) g[v][0]\
    \ == par[v]) {\n            std::swap(g[v][0], g[v].back());\n        }\n    \
    \    for (auto &e : g[v]) {\n            int u = (int)e;\n            if (u !=\
    \ par[v]) {\n                par[u] = v;\n                dfs1(g, u);\n      \
    \          siz[v] += siz[u];\n                if (siz[u] > siz[g[v][0]]) {\n \
    \                   std::swap(g[v][0], e);\n                }\n            }\n\
    \        }\n    }\n\n    template <typename G>\n    void dfs2(const G &g, int\
    \ v, int &time) {\n        in[v] = time;\n        rev[time++] = v;\n        for\
    \ (auto &e : g[v]) {\n            int u = (int)e;\n            if (u == par[v])\
    \ {\n                continue;\n            }\n            if (u == (int) g[v][0])\
    \ {\n                hea[u] = hea[v];\n            } else {\n                hea[u]\
    \ = u;\n            }\n            dep[u] = dep[v] + 1;\n            dfs2(g, u,\
    \ time);\n        }\n        out[v] = time;\n    }\n\npublic:\n    template <typename\
    \ G>\n    HeavyLightDecomposition(G &g, int root = 0) :\n        siz(g.size(),\
    \ 1),\n        par(g.size(), root),\n        hea(g.size(), root),\n        in(g.size(),\
    \ 0),\n        out(g.size(), 0),\n        dep(g.size(), 0),\n        rev(g.size(),\
    \ 0) {\n        assert(root >= 0 && root < (int) g.size());\n        dfs1(g, root);\n\
    \        int time = 0;\n        dfs2(g, root, time);\n    }\n\n    int subtree_size(int\
    \ v) const {\n        assert(v >= 0 && v < (int) siz.size());\n        return\
    \ siz[v];\n    }\n\n    int parent(int v) const {\n        assert(v >= 0 && v\
    \ < (int) par.size());\n        return par[v];\n    }\n\n    int in_time(int v)\
    \ const {\n        assert(v >= 0 && v < (int) in.size());\n        return in[v];\n\
    \    }\n\n    int out_time(int v) const {\n        assert(v >= 0 && v < (int)\
    \ out.size());\n        return out[v];\n    }\n\n    int depth(int v) const {\n\
    \        assert(v >= 0 && v < (int) dep.size());\n        return dep[v];\n   \
    \ }\n\n    int time_to_vertex(int t) const {\n        assert(t >= 0 && t < (int)\
    \ rev.size());\n        return rev[t];\n    }\n    \n    int la(int v, int k)\
    \ const {\n        assert(v >= 0 && v < (int) dep.size());\n        assert(k >=\
    \ 0);\n        while (true) {\n            int u = hea[v];\n            if (in[u]\
    \ + k <= in[v]) {\n                return rev[in[v] - k];\n            }\n   \
    \         k -= in[v] - in[u] + 1;\n            v = par[u];\n        }\n      \
    \  return 0;\n    }\n    \n    int forward(int v, int dst) const {\n        assert(v\
    \ >= 0 && v < (int) dep.size());\n        assert(dst >= 0 && dst < (int) dep.size());\n\
    \        assert(v != dst);\n        int l = lca(v, dst);\n        if (l == v)\
    \ {\n            return la(dst, dist(v, dst) - 1);\n        } else {\n       \
    \     return par[v];\n        }\n    }\n\n    int lca(int u, int v) const {\n\
    \        assert(u >= 0 && u < (int) dep.size());\n        assert(v >= 0 && v <\
    \ (int) dep.size());\n        while (u != v) {\n            if (in[u] > in[v])\
    \ {\n                std::swap(u, v);\n            }\n            if (hea[u] ==\
    \ hea[v]) {\n                v = u;\n            } else {\n                v =\
    \ par[hea[v]];\n            }\n        }\n        return u;\n    }\n\n    int\
    \ dist(int u, int v) const {\n        assert(u >= 0 && u < (int) dep.size());\n\
    \        assert(v >= 0 && v < (int) dep.size());        \n        return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    std::vector<std::pair<int, int>>\
    \ path(int u, int v, bool edge) const {\n        assert(u >= 0 && u < (int) dep.size());\n\
    \        assert(v >= 0 && v < (int) dep.size());\n        std::vector<std::pair<int,\
    \ int>> fromu, fromv;\n        bool rev = false;\n        while (true) {\n   \
    \         if (u == v && edge) {\n                break;\n            }\n     \
    \       if (in[u] > in[v]) {\n                std::swap(u, v);\n             \
    \   std::swap(fromu, fromv);\n                rev ^= true;\n            }\n  \
    \          if (hea[u] == hea[v]) {\n                fromv.emplace_back(in[v],\
    \ in[u] + (int)edge);\n                v = u;\n                break;\n      \
    \      } else {\n                fromv.emplace_back(in[v], in[hea[v]]);\n    \
    \            v = par[hea[v]];\n            }\n        }\n        if (rev) {\n\
    \            std::swap(fromu, fromv);\n        }\n        std::reverse(fromv.begin(),\
    \ fromv.end());\n        fromu.reserve(fromv.size());\n        for (auto [x, y]\
    \ : fromv) {\n            fromu.emplace_back(y, x);\n        }\n        return\
    \ fromu;\n    }\n};\n\n#line 8 \"test/library_checker/lca.test.cpp\"\n\nint main()\
    \ {\n    i32 n, q;\n    cin >> n >> q;\n    Graph<i32> g(n);\n    REP(i, 1, n)\
    \ {\n        i32 p;\n        cin >> p;\n        g.add_undirected_edge(p, i);\n\
    \    }\n    HeavyLightDecomposition hld(g);\n    REP(qi, q) {\n        i32 u,\
    \ v;\n        cin >> u >> v;\n        cout << hld.lca(u, v) << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#define FAST_IO\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/graph.hpp\"\
    \n#include \"../../graph/heavy_light_decomposition.hpp\"\n\nint main() {\n   \
    \ i32 n, q;\n    cin >> n >> q;\n    Graph<i32> g(n);\n    REP(i, 1, n) {\n  \
    \      i32 p;\n        cin >> p;\n        g.add_undirected_edge(p, i);\n    }\n\
    \    HeavyLightDecomposition hld(g);\n    REP(qi, q) {\n        i32 u, v;\n  \
    \      cin >> u >> v;\n        cout << hld.lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/graph.hpp
  - graph/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/library_checker/lca.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 12:34:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/lca.test.cpp
- /verify/test/library_checker/lca.test.cpp.html
title: test/library_checker/lca.test.cpp
---
