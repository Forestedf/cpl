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
  bundledCode: "#line 2 \"graph/minimum_cost_flow_with_acl.hpp\"\n\n#include <atcoder/mincostflow>\n\
    #include <optional>\n\ntemplate <typename Cap, typename Cost>\nclass MinCostFlow\
    \ {\n    atcoder::mcf_graph<Cap, Cost> graph;\n    std::vector<Cap> supply;\n\
    \    Cost ans;\n    \npublic:\n    MinCostFlow(int n) : graph(n + 2), supply(n,\
    \ 0), ans(0) {}\n    \n    void add_supply(int v, Cap s) {\n        assert(v <\
    \ static_cast<int>(supply.size()));\n        supply[v] += s;\n    }\n    \n  \
    \  void add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(from\
    \ >= 0 && from < supply.size() && to >= 0 && to < supply.size());\n        assert(0\
    \ <= cap);\n        if (cost < 0) {\n            ans += cost * cap;\n        \
    \    add_supply(to, cap);\n            add_supply(from, -cap);\n            graph.add_edge(to,\
    \ from, cap, -cost);\n        } else {\n            graph.add_edge(from, to, cap,\
    \ cost);\n        }\n    }\n    \n    void add_edge(int from, int to, Cap lower,\
    \ Cap upper, Cost cost) {\n        assert(from >= 0 && from < supply.size() &&\
    \ to >= 0 && to < supply.size());\n        assert(0 <= lower && lower <= upper);\n\
    \        ans += cost * lower;\n        add_supply(to, lower);\n        add_supply(from,\
    \ -lower);\n        add_edge(from, to, upper - lower, cost);\n    }\n    \n  \
    \  std::optional<Cost> solve() {\n        int super_s = static_cast<int>(supply.size());\n\
    \        int super_t = super_s + 1;\n        Cap neg_sum = 0;\n        Cap pos_sum\
    \ = 0;\n        for (int i = 0; i < supply.size(); ++i) {\n            if (supply[i]\
    \ < 0) {\n                graph.add_edge(i, super_t, -supply[i], 0);\n       \
    \         neg_sum += supply[i];\n            } else if (supply[i] > 0) {\n   \
    \             graph.add_edge(super_s, i, supply[i], 0);\n                pos_sum\
    \ += supply[i];\n            }\n        }\n        if (-neg_sum != pos_sum) {\n\
    \            return std::nullopt;\n        }\n        std::pair<Cap, Cost> ret\
    \ = graph.flow(super_s, super_t, pos_sum);\n        if (ret.first != pos_sum)\
    \ {\n            return std::nullopt;\n        } else {\n            return std::optional<Cost>(ans\
    \ + ret.second);\n        }\n    }\n};\n\n"
  code: "#pragma once\n\n#include <atcoder/mincostflow>\n#include <optional>\n\ntemplate\
    \ <typename Cap, typename Cost>\nclass MinCostFlow {\n    atcoder::mcf_graph<Cap,\
    \ Cost> graph;\n    std::vector<Cap> supply;\n    Cost ans;\n    \npublic:\n \
    \   MinCostFlow(int n) : graph(n + 2), supply(n, 0), ans(0) {}\n    \n    void\
    \ add_supply(int v, Cap s) {\n        assert(v < static_cast<int>(supply.size()));\n\
    \        supply[v] += s;\n    }\n    \n    void add_edge(int from, int to, Cap\
    \ cap, Cost cost) {\n        assert(from >= 0 && from < supply.size() && to >=\
    \ 0 && to < supply.size());\n        assert(0 <= cap);\n        if (cost < 0)\
    \ {\n            ans += cost * cap;\n            add_supply(to, cap);\n      \
    \      add_supply(from, -cap);\n            graph.add_edge(to, from, cap, -cost);\n\
    \        } else {\n            graph.add_edge(from, to, cap, cost);\n        }\n\
    \    }\n    \n    void add_edge(int from, int to, Cap lower, Cap upper, Cost cost)\
    \ {\n        assert(from >= 0 && from < supply.size() && to >= 0 && to < supply.size());\n\
    \        assert(0 <= lower && lower <= upper);\n        ans += cost * lower;\n\
    \        add_supply(to, lower);\n        add_supply(from, -lower);\n        add_edge(from,\
    \ to, upper - lower, cost);\n    }\n    \n    std::optional<Cost> solve() {\n\
    \        int super_s = static_cast<int>(supply.size());\n        int super_t =\
    \ super_s + 1;\n        Cap neg_sum = 0;\n        Cap pos_sum = 0;\n        for\
    \ (int i = 0; i < supply.size(); ++i) {\n            if (supply[i] < 0) {\n  \
    \              graph.add_edge(i, super_t, -supply[i], 0);\n                neg_sum\
    \ += supply[i];\n            } else if (supply[i] > 0) {\n                graph.add_edge(super_s,\
    \ i, supply[i], 0);\n                pos_sum += supply[i];\n            }\n  \
    \      }\n        if (-neg_sum != pos_sum) {\n            return std::nullopt;\n\
    \        }\n        std::pair<Cap, Cost> ret = graph.flow(super_s, super_t, pos_sum);\n\
    \        if (ret.first != pos_sum) {\n            return std::nullopt;\n     \
    \   } else {\n            return std::optional<Cost>(ans + ret.second);\n    \
    \    }\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum_cost_flow_with_acl.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum_cost_flow_with_acl.hpp
layout: document
redirect_from:
- /library/graph/minimum_cost_flow_with_acl.hpp
- /library/graph/minimum_cost_flow_with_acl.hpp.html
title: graph/minimum_cost_flow_with_acl.hpp
---
