---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/two_sat.test.cpp
    title: test/library_checker/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two_sat.hpp\"\n\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n\n#include <vector>\n\ntemplate <typename G>\nclass StronglyConnectedComponents\
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
    \        }\n        return ret;\n    }\n};\n\n#line 4 \"graph/two_sat.hpp\"\n\n\
    #include <optional>\n\nclass TwoSat {\npublic:\n    struct Variable {\n    private:\n\
    \        int idx;\n            \n        Variable(int i) : idx(i) {}\n       \
    \ \n    public:\n        Variable operator!() const noexcept {\n            return\
    \ Variable(idx ^ 1);\n        }\n        \n        int index() const {\n     \
    \       return idx / 2;\n        }\n        \n        friend class TwoSat;\n \
    \   };\n    \nprivate:\n    std::vector<std::vector<int>> graph;\n    \npublic:\n\
    \    TwoSat() : graph() {}\n    \n    TwoSat::Variable add_variable() {\n    \
    \    Variable var(graph.size());\n        graph.resize(graph.size() + 2, std::vector<int>());\n\
    \        return var;\n    }\n    \n    std::vector<TwoSat::Variable> add_variables(int\
    \ num) {\n        std::vector<TwoSat::Variable> vars;\n        vars.reserve(num);\n\
    \        for (int i = 0; i < num; ++i) {\n            vars.emplace_back(Variable((int)\
    \ graph.size() + 2 * i));\n        }\n        graph.resize((int) graph.size()\
    \ + 2 * num, std::vector<int>());\n        return vars;\n    }\n    \n    // x\
    \ or y\n    void add_clause(Variable x, Variable y) {\n        graph[(!x).idx].push_back(y.idx);\n\
    \        graph[(!y).idx].push_back(x.idx);\n    }\n    \n    // x implies y\n\
    \    void implies(Variable x, Variable y) {\n        add_clause(!x, y);\n    }\n\
    \    \n    void at_most_one(const std::vector<Variable> &vars) {\n        if (vars.size()\
    \ <= 1) {\n            return;\n        }\n        std::vector<Variable> sum =\
    \ add_variables((int) vars.size() - 1);\n        for (int i = 0; i < (int) sum.size();\
    \ ++i) {\n            implies(vars[i], sum[i]);\n            implies(sum[i], !vars[i\
    \ + 1]);\n        }\n        for (int i = 0; i < (int) sum.size() - 1; ++i) {\n\
    \            implies(sum[i], sum[i + 1]);\n        }\n    }\n    \n    std::optional<std::vector<bool>>\
    \ solve() {\n        StronglyConnectedComponents scc(graph);\n        std::vector<bool>\
    \ ans(graph.size() / 2, false);\n        for (int i = 0; i < (int) graph.size()\
    \ / 2; ++i) {\n            if (scc[2 * i] == scc[2 * i + 1]) {\n             \
    \   return std::nullopt;\n            }\n            if (scc[2 * i] > scc[2 *\
    \ i + 1]) {\n                ans[i] = true;\n            }\n        }\n      \
    \  return ans;\n    }\n};\n\n"
  code: "#pragma once\n\n#include \"strongly_connected_components.hpp\"\n\n#include\
    \ <optional>\n\nclass TwoSat {\npublic:\n    struct Variable {\n    private:\n\
    \        int idx;\n            \n        Variable(int i) : idx(i) {}\n       \
    \ \n    public:\n        Variable operator!() const noexcept {\n            return\
    \ Variable(idx ^ 1);\n        }\n        \n        int index() const {\n     \
    \       return idx / 2;\n        }\n        \n        friend class TwoSat;\n \
    \   };\n    \nprivate:\n    std::vector<std::vector<int>> graph;\n    \npublic:\n\
    \    TwoSat() : graph() {}\n    \n    TwoSat::Variable add_variable() {\n    \
    \    Variable var(graph.size());\n        graph.resize(graph.size() + 2, std::vector<int>());\n\
    \        return var;\n    }\n    \n    std::vector<TwoSat::Variable> add_variables(int\
    \ num) {\n        std::vector<TwoSat::Variable> vars;\n        vars.reserve(num);\n\
    \        for (int i = 0; i < num; ++i) {\n            vars.emplace_back(Variable((int)\
    \ graph.size() + 2 * i));\n        }\n        graph.resize((int) graph.size()\
    \ + 2 * num, std::vector<int>());\n        return vars;\n    }\n    \n    // x\
    \ or y\n    void add_clause(Variable x, Variable y) {\n        graph[(!x).idx].push_back(y.idx);\n\
    \        graph[(!y).idx].push_back(x.idx);\n    }\n    \n    // x implies y\n\
    \    void implies(Variable x, Variable y) {\n        add_clause(!x, y);\n    }\n\
    \    \n    void at_most_one(const std::vector<Variable> &vars) {\n        if (vars.size()\
    \ <= 1) {\n            return;\n        }\n        std::vector<Variable> sum =\
    \ add_variables((int) vars.size() - 1);\n        for (int i = 0; i < (int) sum.size();\
    \ ++i) {\n            implies(vars[i], sum[i]);\n            implies(sum[i], !vars[i\
    \ + 1]);\n        }\n        for (int i = 0; i < (int) sum.size() - 1; ++i) {\n\
    \            implies(sum[i], sum[i + 1]);\n        }\n    }\n    \n    std::optional<std::vector<bool>>\
    \ solve() {\n        StronglyConnectedComponents scc(graph);\n        std::vector<bool>\
    \ ans(graph.size() / 2, false);\n        for (int i = 0; i < (int) graph.size()\
    \ / 2; ++i) {\n            if (scc[2 * i] == scc[2 * i + 1]) {\n             \
    \   return std::nullopt;\n            }\n            if (scc[2 * i] > scc[2 *\
    \ i + 1]) {\n                ans[i] = true;\n            }\n        }\n      \
    \  return ans;\n    }\n};\n\n"
  dependsOn:
  - graph/strongly_connected_components.hpp
  isVerificationFile: false
  path: graph/two_sat.hpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/two_sat.test.cpp
documentation_of: graph/two_sat.hpp
layout: document
redirect_from:
- /library/graph/two_sat.hpp
- /library/graph/two_sat.hpp.html
title: graph/two_sat.hpp
---
