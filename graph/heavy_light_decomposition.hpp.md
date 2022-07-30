---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/jump_on_tree.test.cpp
    title: test/library_checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/lca.test.cpp
    title: test/library_checker/lca.test.cpp
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
  bundledCode: "#line 2 \"graph/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nclass HeavyLightDecomposition\
    \ {\n    std::vector<int> siz;\n    std::vector<int> par;\n    std::vector<int>\
    \ hea;\n    std::vector<int> in;\n    std::vector<int> out;\n    std::vector<int>\
    \ dep;\n    std::vector<int> rev;\n\n    template <typename G>\n    void dfs1(G\
    \ &g, int v) {\n        if (!g[v].empty() && (int) g[v][0] == par[v]) {\n    \
    \        std::swap(g[v][0], g[v].back());\n        }\n        for (auto &e : g[v])\
    \ {\n            int u = (int)e;\n            if (u != par[v]) {\n           \
    \     par[u] = v;\n                dfs1(g, u);\n                siz[v] += siz[u];\n\
    \                if (siz[u] > siz[g[v][0]]) {\n                    std::swap(g[v][0],\
    \ e);\n                }\n            }\n        }\n    }\n\n    template <typename\
    \ G>\n    void dfs2(const G &g, int v, int &time) {\n        in[v] = time;\n \
    \       rev[time++] = v;\n        for (auto &e : g[v]) {\n            int u =\
    \ (int)e;\n            if (u == par[v]) {\n                continue;\n       \
    \     }\n            if (u == (int) g[v][0]) {\n                hea[u] = hea[v];\n\
    \            } else {\n                hea[u] = u;\n            }\n          \
    \  dep[u] = dep[v] + 1;\n            dfs2(g, u, time);\n        }\n        out[v]\
    \ = time;\n    }\n\npublic:\n    template <typename G>\n    HeavyLightDecomposition(G\
    \ &g, int root = 0) :\n        siz(g.size(), 1),\n        par(g.size(), root),\n\
    \        hea(g.size(), root),\n        in(g.size(), 0),\n        out(g.size(),\
    \ 0),\n        dep(g.size(), 0),\n        rev(g.size(), 0) {\n        assert(root\
    \ >= 0 && root < (int) g.size());\n        dfs1(g, root);\n        int time =\
    \ 0;\n        dfs2(g, root, time);\n    }\n\n    int subtree_size(int v) const\
    \ {\n        assert(v >= 0 && v < (int) siz.size());\n        return siz[v];\n\
    \    }\n\n    int parent(int v) const {\n        assert(v >= 0 && v < (int) par.size());\n\
    \        return par[v];\n    }\n\n    int in_time(int v) const {\n        assert(v\
    \ >= 0 && v < (int) in.size());\n        return in[v];\n    }\n\n    int out_time(int\
    \ v) const {\n        assert(v >= 0 && v < (int) out.size());\n        return\
    \ out[v];\n    }\n\n    int depth(int v) const {\n        assert(v >= 0 && v <\
    \ (int) dep.size());\n        return dep[v];\n    }\n\n    int time_to_vertex(int\
    \ t) const {\n        assert(t >= 0 && t < (int) rev.size());\n        return\
    \ rev[t];\n    }\n    \n    int la(int v, int k) const {\n        assert(v >=\
    \ 0 && v < (int) dep.size());\n        assert(k >= 0);\n        if (k > dep[v])\
    \ {\n            return -1;\n        }\n        while (true) {\n            int\
    \ u = hea[v];\n            if (in[u] + k <= in[v]) {\n                return rev[in[v]\
    \ - k];\n            }\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n\
    \        }\n        return 0;\n    }\n    \n    int forward(int v, int dst) const\
    \ {\n        assert(v >= 0 && v < (int) dep.size());\n        assert(dst >= 0\
    \ && dst < (int) dep.size());\n        assert(v != dst);\n        int l = lca(v,\
    \ dst);\n        if (l == v) {\n            return la(dst, dist(v, dst) - 1);\n\
    \        } else {\n            return par[v];\n        }\n    }\n\n    int lca(int\
    \ u, int v) const {\n        assert(u >= 0 && u < (int) dep.size());\n       \
    \ assert(v >= 0 && v < (int) dep.size());\n        while (u != v) {\n        \
    \    if (in[u] > in[v]) {\n                std::swap(u, v);\n            }\n \
    \           if (hea[u] == hea[v]) {\n                v = u;\n            } else\
    \ {\n                v = par[hea[v]];\n            }\n        }\n        return\
    \ u;\n    }\n\n    int dist(int u, int v) const {\n        assert(u >= 0 && u\
    \ < (int) dep.size());\n        assert(v >= 0 && v < (int) dep.size());\n    \
    \    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge) const {\n        assert(u >= 0 && u < (int)\
    \ dep.size());\n        assert(v >= 0 && v < (int) dep.size());\n        std::vector<std::pair<int,\
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
    \ fromu;\n    }\n    \n    int jump(int u, int v, int k) const {\n        assert(u\
    \ >= 0 && u < (int) dep.size());\n        assert(v >= 0 && v < (int) dep.size());\n\
    \        assert(k >= 0);\n        int l = lca(u, v);\n        int dis = dep[u]\
    \ + dep[v] - 2 * dep[l];\n        if (k > dis) {\n            return -1;\n   \
    \     }\n        if (k <= dep[u] - dep[l]) {\n            return la(u, k);\n \
    \       } else {\n            return la(v, dis - k);\n        }\n    }\n};\n\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nclass HeavyLightDecomposition {\n    std::vector<int> siz;\n\
    \    std::vector<int> par;\n    std::vector<int> hea;\n    std::vector<int> in;\n\
    \    std::vector<int> out;\n    std::vector<int> dep;\n    std::vector<int> rev;\n\
    \n    template <typename G>\n    void dfs1(G &g, int v) {\n        if (!g[v].empty()\
    \ && (int) g[v][0] == par[v]) {\n            std::swap(g[v][0], g[v].back());\n\
    \        }\n        for (auto &e : g[v]) {\n            int u = (int)e;\n    \
    \        if (u != par[v]) {\n                par[u] = v;\n                dfs1(g,\
    \ u);\n                siz[v] += siz[u];\n                if (siz[u] > siz[g[v][0]])\
    \ {\n                    std::swap(g[v][0], e);\n                }\n         \
    \   }\n        }\n    }\n\n    template <typename G>\n    void dfs2(const G &g,\
    \ int v, int &time) {\n        in[v] = time;\n        rev[time++] = v;\n     \
    \   for (auto &e : g[v]) {\n            int u = (int)e;\n            if (u ==\
    \ par[v]) {\n                continue;\n            }\n            if (u == (int)\
    \ g[v][0]) {\n                hea[u] = hea[v];\n            } else {\n       \
    \         hea[u] = u;\n            }\n            dep[u] = dep[v] + 1;\n     \
    \       dfs2(g, u, time);\n        }\n        out[v] = time;\n    }\n\npublic:\n\
    \    template <typename G>\n    HeavyLightDecomposition(G &g, int root = 0) :\n\
    \        siz(g.size(), 1),\n        par(g.size(), root),\n        hea(g.size(),\
    \ root),\n        in(g.size(), 0),\n        out(g.size(), 0),\n        dep(g.size(),\
    \ 0),\n        rev(g.size(), 0) {\n        assert(root >= 0 && root < (int) g.size());\n\
    \        dfs1(g, root);\n        int time = 0;\n        dfs2(g, root, time);\n\
    \    }\n\n    int subtree_size(int v) const {\n        assert(v >= 0 && v < (int)\
    \ siz.size());\n        return siz[v];\n    }\n\n    int parent(int v) const {\n\
    \        assert(v >= 0 && v < (int) par.size());\n        return par[v];\n   \
    \ }\n\n    int in_time(int v) const {\n        assert(v >= 0 && v < (int) in.size());\n\
    \        return in[v];\n    }\n\n    int out_time(int v) const {\n        assert(v\
    \ >= 0 && v < (int) out.size());\n        return out[v];\n    }\n\n    int depth(int\
    \ v) const {\n        assert(v >= 0 && v < (int) dep.size());\n        return\
    \ dep[v];\n    }\n\n    int time_to_vertex(int t) const {\n        assert(t >=\
    \ 0 && t < (int) rev.size());\n        return rev[t];\n    }\n    \n    int la(int\
    \ v, int k) const {\n        assert(v >= 0 && v < (int) dep.size());\n       \
    \ assert(k >= 0);\n        if (k > dep[v]) {\n            return -1;\n       \
    \ }\n        while (true) {\n            int u = hea[v];\n            if (in[u]\
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
    \        assert(v >= 0 && v < (int) dep.size());\n        return dep[u] + dep[v]\
    \ - 2 * dep[lca(u, v)];\n    }\n\n    std::vector<std::pair<int, int>> path(int\
    \ u, int v, bool edge) const {\n        assert(u >= 0 && u < (int) dep.size());\n\
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
    \ fromu;\n    }\n    \n    int jump(int u, int v, int k) const {\n        assert(u\
    \ >= 0 && u < (int) dep.size());\n        assert(v >= 0 && v < (int) dep.size());\n\
    \        assert(k >= 0);\n        int l = lca(u, v);\n        int dis = dep[u]\
    \ + dep[v] - 2 * dep[l];\n        if (k > dis) {\n            return -1;\n   \
    \     }\n        if (k <= dep[u] - dep[l]) {\n            return la(u, k);\n \
    \       } else {\n            return la(v, dis - k);\n        }\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2022-07-30 13:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/vertex_add_subtree_sum.test.cpp
  - test/library_checker/vertex_add_path_sum.test.cpp
  - test/library_checker/vertex_set_path_composite.test.cpp
  - test/library_checker/jump_on_tree.test.cpp
  - test/library_checker/lca.test.cpp
documentation_of: graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/graph/heavy_light_decomposition.hpp
- /library/graph/heavy_light_decomposition.hpp.html
title: graph/heavy_light_decomposition.hpp
---
