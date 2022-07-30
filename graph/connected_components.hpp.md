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
  bundledCode: "#line 2 \"graph/connected_components.hpp\"\n#include <queue>\n#include\
    \ <utility>\n#include <vector>\n\nclass ConnectedComponents {\n    std::vector<int>\
    \ number;\n    int comp;\n\npublic:\n    template <typename G>\n    ConnectedComponents(const\
    \ G &graph) :\n        number((int) graph.size(), -1), comp(0) {\n        std::queue<int>\
    \ que;\n        for (int i = 0; i < (int) graph.size(); ++i) {\n            if\
    \ (number[i] != -1) {\n                continue;\n            }\n            que.push(i);\n\
    \            number[i] = comp;\n            while (!que.empty()) {\n         \
    \       int v = que.front();\n                que.pop();\n                for\
    \ (const auto &e : graph[v]) {\n                    if (number[(int) e] == -1)\
    \ {\n                        number[(int) e] = number[v];\n                  \
    \      que.push((int)e);\n                    }\n                }\n         \
    \   }\n            ++comp;\n        }\n    }\n\n    int operator[](int v) const\
    \ {\n        assert(v >= 0 && v < (int) number.size());\n        return number[v];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() const {\n        std::vector<std::vector<int>>\
    \ ret(comp);\n        for (int i = 0; i < (int) number.size(); ++i)\n        \
    \    ret[number[i]].push_back(i);\n        return ret;\n    }\n\n    int components()\
    \ const {\n        return comp;\n    }\n};\n"
  code: "#pragma once\n#include <queue>\n#include <utility>\n#include <vector>\n\n\
    class ConnectedComponents {\n    std::vector<int> number;\n    int comp;\n\npublic:\n\
    \    template <typename G>\n    ConnectedComponents(const G &graph) :\n      \
    \  number((int) graph.size(), -1), comp(0) {\n        std::queue<int> que;\n \
    \       for (int i = 0; i < (int) graph.size(); ++i) {\n            if (number[i]\
    \ != -1) {\n                continue;\n            }\n            que.push(i);\n\
    \            number[i] = comp;\n            while (!que.empty()) {\n         \
    \       int v = que.front();\n                que.pop();\n                for\
    \ (const auto &e : graph[v]) {\n                    if (number[(int) e] == -1)\
    \ {\n                        number[(int) e] = number[v];\n                  \
    \      que.push((int)e);\n                    }\n                }\n         \
    \   }\n            ++comp;\n        }\n    }\n\n    int operator[](int v) const\
    \ {\n        assert(v >= 0 && v < (int) number.size());\n        return number[v];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() const {\n        std::vector<std::vector<int>>\
    \ ret(comp);\n        for (int i = 0; i < (int) number.size(); ++i)\n        \
    \    ret[number[i]].push_back(i);\n        return ret;\n    }\n\n    int components()\
    \ const {\n        return comp;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/connected_components.hpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/connected_components.hpp
layout: document
redirect_from:
- /library/graph/connected_components.hpp
- /library/graph/connected_components.hpp.html
title: graph/connected_components.hpp
---
