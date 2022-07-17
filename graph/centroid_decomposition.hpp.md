---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/centroid_decomposition.hpp\"\n\n#include <vector>\n\
    #include <queue>\n\ntemplate <typename G>\nclass CentroidDecomposition {\n   \
    \ const G &g;\n    \n    std::vector<std::vector<int>> to;\n    std::vector<bool>\
    \ used;\n    std::vector<int> size;\n    int first;\n    \n    void dfs(int v,\
    \ int p) {\n        size[v] = 1;\n        for (int u : g[v]) {\n            if\
    \ (u == p || used[u]) {\n                continue;\n            }\n          \
    \  dfs(u, v);\n            size[v] += size[u];\n        }\n    }\n    \n    int\
    \ find_centroid(int v) {\n        dfs(v, v);\n        int sz = size[v];\n    \
    \    int p = v;\n        while (true) {\n            bool ok = true;\n       \
    \     for (int u : g[v]) {\n                if (u == p || used[u]) {\n       \
    \             continue;\n                }\n                if (size[u] > sz /\
    \ 2) {\n                    p = v;\n                    v = u;\n             \
    \       ok = false;\n                    break;\n                }\n         \
    \   }\n            if (ok) {\n                break;\n            }\n        }\n\
    \        return v;\n    }\n    \n    int decomposite(int v) {\n        int cent\
    \ = find_centroid(v);\n        used[cent] = true;\n        for (int u : g[cent])\
    \ {\n            if (used[u]) {\n                continue;\n            }\n  \
    \          to[cent].push_back(decomposite(u));\n        }\n        return cent;\n\
    \    }\n    \npublic:\n    CentroidDecomposition(const G &_g) :\n    g(_g),\n\
    \    to(static_cast<int>(g.size())),\n    used(static_cast<int>(g.size()), false),\n\
    \    size(static_cast<int>(g.size()), 0) {\n        first = decomposite(0);\n\
    \    }\n    \n    int first_centroid() const {\n        return first;\n    }\n\
    \    \n    const std::vector<int> &next_centroids(int v) const {\n        assert(v\
    \ >= 0 && v < static_cast<int>(g.size()));\n        return to[v];\n    }\n};\n\
    \n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n\ntemplate <typename\
    \ G>\nclass CentroidDecomposition {\n    const G &g;\n    \n    std::vector<std::vector<int>>\
    \ to;\n    std::vector<bool> used;\n    std::vector<int> size;\n    int first;\n\
    \    \n    void dfs(int v, int p) {\n        size[v] = 1;\n        for (int u\
    \ : g[v]) {\n            if (u == p || used[u]) {\n                continue;\n\
    \            }\n            dfs(u, v);\n            size[v] += size[u];\n    \
    \    }\n    }\n    \n    int find_centroid(int v) {\n        dfs(v, v);\n    \
    \    int sz = size[v];\n        int p = v;\n        while (true) {\n         \
    \   bool ok = true;\n            for (int u : g[v]) {\n                if (u ==\
    \ p || used[u]) {\n                    continue;\n                }\n        \
    \        if (size[u] > sz / 2) {\n                    p = v;\n               \
    \     v = u;\n                    ok = false;\n                    break;\n  \
    \              }\n            }\n            if (ok) {\n                break;\n\
    \            }\n        }\n        return v;\n    }\n    \n    int decomposite(int\
    \ v) {\n        int cent = find_centroid(v);\n        used[cent] = true;\n   \
    \     for (int u : g[cent]) {\n            if (used[u]) {\n                continue;\n\
    \            }\n            to[cent].push_back(decomposite(u));\n        }\n \
    \       return cent;\n    }\n    \npublic:\n    CentroidDecomposition(const G\
    \ &_g) :\n    g(_g),\n    to(static_cast<int>(g.size())),\n    used(static_cast<int>(g.size()),\
    \ false),\n    size(static_cast<int>(g.size()), 0) {\n        first = decomposite(0);\n\
    \    }\n    \n    int first_centroid() const {\n        return first;\n    }\n\
    \    \n    const std::vector<int> &next_centroids(int v) const {\n        assert(v\
    \ >= 0 && v < static_cast<int>(g.size()));\n        return to[v];\n    }\n};\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
