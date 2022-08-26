---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/two_edge_connected_components.test.cpp
    title: graph/test/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two_edge_connected_components.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nclass TwoEdgeConnectedComponents {\n\
    \    int comp_num;\n    std::vector<int> comp;\n    \npublic:\n    template <typename\
    \ G>\n    TwoEdgeConnectedComponents(const G &g) : comp_num(0), comp(g.size(),\
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
    \      }\n        return gs;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nclass TwoEdgeConnectedComponents {\n    int comp_num;\n    std::vector<int>\
    \ comp;\n    \npublic:\n    template <typename G>\n    TwoEdgeConnectedComponents(const\
    \ G &g) : comp_num(0), comp(g.size(), -1) {\n        std::vector<int> ord(g.size(),\
    \ -1);\n        std::vector<int> low(g.size(), -1);\n        std::vector<int>\
    \ found(g.size(), 0);\n        const auto dfs0 = [&](const auto &dfs0, int v,\
    \ int p, int &t) -> void {\n            ord[v] = t++;\n            low[v] = ord[v];\n\
    \            bool par = false;\n            for (const auto &e : g[v]) {\n   \
    \             int u = (int) e;\n                if (!found[u]) {\n           \
    \         found[u] = 1;\n                    dfs0(dfs0, u, v, t);\n          \
    \          low[v] = std::min(low[v], low[u]);\n                }\n           \
    \     bool back = ord[u] < ord[v];\n                if (u == p) {\n          \
    \          if (!par) {\n                        back = false;\n              \
    \          par = true;\n                    }\n                }\n           \
    \     if (back) {\n                    low[v] = std::min(low[v], ord[u]);\n  \
    \              }\n            }\n        };\n        int t = 0;\n        for (int\
    \ v = 0; v < (int) g.size(); ++v) {\n            if (!found[v]) {\n          \
    \      found[v] = 1;\n                dfs0(dfs0, v, -1, t);\n            }\n \
    \       }\n        const auto dfs1 = [&](const auto &dfs1, i32 v, i32 k) -> void\
    \ {\n            comp[v] = k;\n            for (const auto &e : g[v]) {\n    \
    \            int u = (int) e;\n                if (comp[u] == -1) {\n        \
    \            if (low[u] > ord[v]) {\n                        dfs1(dfs1, u, comp_num++);\n\
    \                    } else {\n                        dfs1(dfs1, u, k);\n   \
    \                 }\n                }\n            }\n        };\n        for\
    \ (int v = 0; v < (int) g.size(); ++v) {\n            if (comp[v] == -1) {\n \
    \               dfs1(dfs1, v, comp_num++);\n            }\n        }\n    }\n\
    \    \n    int operator[](int v) const {\n        return comp[v];\n    }\n   \
    \ int compc() const {\n        return comp_num;\n    }\n    \n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<std::vector<int>> gs(comp_num);\n    \
    \    for (int i = 0; i < (int) comp.size(); ++i) {\n            gs[comp[i]].push_back(i);\n\
    \        }\n        return gs;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2022-08-26 11:02:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.hpp
- /library/graph/two_edge_connected_components.hpp.html
title: graph/two_edge_connected_components.hpp
---
