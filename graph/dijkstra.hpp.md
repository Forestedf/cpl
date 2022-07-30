---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\n#line 2 \"graph/graph.hpp\"\n\n\
    #include <utility>\n#include <vector>\n#include <numeric>\n#include <cassert>\n\
    \ntemplate <typename Edge>\nclass Graph {\n    std::vector<std::vector<Edge>>\
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
    \    }\n\n    using Weight = std::size_t;\n    Weight weight() const {\n     \
    \   return 1;\n    }\n};\n\ntemplate <typename T>\nstruct WeightedEdge {\n   \
    \ int to;\n    T wt;\n\n    WeightedEdge(int t, const T &w) : to(t), wt(w) {}\n\
    \n    explicit operator int() const {\n        return to;\n    }\n\n    using\
    \ Weight = T;\n    Weight weight() const {\n        return wt;\n    }\n};\n\n\
    #line 4 \"graph/dijkstra.hpp\"\n\n#include <queue>\n#include <limits>\n#include\
    \ <functional>\n\ntemplate <typename T>\nstd::vector<T> dijkstra(const Graph<WeightedEdge<T>>\
    \ &g, int s) {\n    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    \    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>>\
    \ pq;\n    dist[s] = T(0);\n    pq.emplace(0, s);\n    while (!pq.empty()) {\n\
    \        auto [d, v] = pq.top();\n        pq.pop();\n        if (d > dist[v])\
    \ {\n            continue;\n        }\n        for (const WeightedEdge<T> &e :\
    \ g[v]) {\n            if (d + e.wt < dist[e.to]) {\n                dist[e.to]\
    \ = d + e.wt;\n                pq.emplace(dist[e.to], e.to);\n            }\n\
    \        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\n#include <queue>\n#include <limits>\n\
    #include <functional>\n\ntemplate <typename T>\nstd::vector<T> dijkstra(const\
    \ Graph<WeightedEdge<T>> &g, int s) {\n    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    \    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>>\
    \ pq;\n    dist[s] = T(0);\n    pq.emplace(0, s);\n    while (!pq.empty()) {\n\
    \        auto [d, v] = pq.top();\n        pq.pop();\n        if (d > dist[v])\
    \ {\n            continue;\n        }\n        for (const WeightedEdge<T> &e :\
    \ g[v]) {\n            if (d + e.wt < dist[e.to]) {\n                dist[e.to]\
    \ = d + e.wt;\n                pq.emplace(dist[e.to], e.to);\n            }\n\
    \        }\n    }\n    return dist;\n}"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
