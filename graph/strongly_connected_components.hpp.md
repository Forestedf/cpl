---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/two_sat.hpp
    title: graph/two_sat.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/scc.test.cpp
    title: test/library_checker/scc.test.cpp
  - icon: ':x:'
    path: test/library_checker/two_sat.test.cpp
    title: test/library_checker/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.hpp\"\n\n#include <vector>\n\
    \ntemplate <typename G>\nclass StronglyConnectedComponents {    \n    std::vector<int>\
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
    \        }\n        return ret;\n    }\n};\n\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename G>\nclass StronglyConnectedComponents\
    \ {    \n    std::vector<int> comp_id;\n    int comp_num;\n    \npublic:\n   \
    \ StronglyConnectedComponents(const G &g) : comp_id(g.size(), -1), comp_num(0)\
    \ {\n        int now = 0;\n        std::vector<int> vs;\n        std::vector<int>\
    \ ord(g.size(), -1);\n        std::vector<int> low(g.size(), -1);\n        \n\
    \        const auto dfs = [&](const auto &dfs, int v) -> void {\n            vs.push_back(v);\n\
    \            ord[v] = now++;\n            low[v] = ord[v];\n            for (int\
    \ u : g[v]) {\n                if (comp_id[u] != -1) {\n                    continue;\n\
    \                }\n                if (ord[u] == -1) {\n                    dfs(dfs,\
    \ u);\n                }\n                low[v] = std::min(low[v], low[u]);\n\
    \            }\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    int u = vs.back();\n                    vs.pop_back();\n\
    \                    comp_id[u] = comp_num;\n                    if (u == v) {\n\
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
    \        }\n        return ret;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy:
  - graph/two_sat.hpp
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/scc.test.cpp
  - test/library_checker/two_sat.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.hpp
- /library/graph/strongly_connected_components.hpp.html
title: graph/strongly_connected_components.hpp
---
