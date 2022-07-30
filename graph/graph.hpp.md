---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/jump_on_tree.test.cpp
    title: test/library_checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/lca.test.cpp
    title: test/library_checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/scc.test.cpp
    title: test/library_checker/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/vertex_add_path_sum.test.cpp
    title: test/library_checker/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/vertex_add_subtree_sum.test.cpp
    title: test/library_checker/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/vertex_set_path_composite.test.cpp
    title: test/library_checker/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n\n#include <utility>\n#include <vector>\n\
    #include <numeric>\n#include <cassert>\n\ntemplate <typename Edge>\nclass Graph\
    \ {\n    std::vector<std::vector<Edge>> edges;\n\npublic:\n    Graph() : edges()\
    \ {}\n    Graph(int v) : edges(v) {\n        assert(v >= 0);\n    }\n    \n  \
    \  std::vector<int> add_vertices(int n) {\n        int v = (int) edges.size();\n\
    \        std::vector<int> idx(n);\n        std::iota(idx.begin(), idx.end(), v);\n\
    \        edges.resize(edges.size() + n);\n        return idx;\n    }\n\n    template\
    \ <typename... T>\n    void add_directed_edge(int from, int to, T &&...val) {\n\
    \        assert(from >= 0 && from < (int) edges.size());\n        assert(to >=\
    \ 0 && to < (int) edges.size());\n        edges[from].emplace_back(Edge(to, std::forward<T>(val)...));\n\
    \    }\n\n    template <typename... T>\n    void add_undirected_edge(int u, int\
    \ v, const T &...val) {\n        assert(u >= 0 && u < (int) edges.size());\n \
    \       assert(v >= 0 && v < (int) edges.size());\n        edges[u].emplace_back(Edge(v,\
    \ val...));\n        edges[v].emplace_back(Edge(u, val...));\n    }\n\n    int\
    \ size() const {\n        return (int) edges.size();\n    }\n\n    const std::vector<Edge>\
    \ &operator[](int v) const {\n        assert(v >= 0 && v < (int) edges.size());\n\
    \        return edges[v];\n    }\n\n    std::vector<Edge> &operator[](int v) {\n\
    \        assert(v >= 0 && v < (int) edges.size());\n        return edges[v];\n\
    \    }\n};\n\nstruct UnweightedEdge {\n    int to;\n\n    UnweightedEdge(int t)\
    \ : to(t) {}\n    \n    explicit operator int() const {\n        return to;\n\
    \    }\n\n    using Weight = std::size_t;\n    Weight weight() const {\n     \
    \   return 1;\n    }\n};\n\ntemplate <typename T>\nstruct WeightedEdge {\n   \
    \ int to;\n    T wt;\n\n    WeightedEdge(int t, const T &w) : to(t), wt(w) {}\n\
    \n    explicit operator int() const {\n        return to;\n    }\n\n    using\
    \ Weight = T;\n    Weight weight() const {\n        return wt;\n    }\n};\n\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n#include <numeric>\n\
    #include <cassert>\n\ntemplate <typename Edge>\nclass Graph {\n    std::vector<std::vector<Edge>>\
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
    \ Weight = T;\n    Weight weight() const {\n        return wt;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/vertex_add_subtree_sum.test.cpp
  - test/library_checker/vertex_add_path_sum.test.cpp
  - test/library_checker/vertex_set_path_composite.test.cpp
  - test/library_checker/scc.test.cpp
  - test/library_checker/jump_on_tree.test.cpp
  - test/library_checker/lca.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
