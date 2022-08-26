---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_sat.hpp
    title: graph/two_sat.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"graph/test/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n\
    #define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n)\
    \ for (i32 i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >=\
    \ 0; --i)\n#define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\n\
    using f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing\
    \ Vec = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\n\nistream &operator>>(istream\
    \ &is, i128 &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\n\
    istream &operator>>(istream &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x =\
    \ v;\n    return is;\n}\nostream &operator<<(ostream &os, u128 x) {\n    os <<\
    \ (u64) x;\n    return os;\n}\n\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n\
    [[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n\
    \    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n     \
    \   cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n  \
    \  }\n} set_up_io;\n#line 2 \"graph/two_sat.hpp\"\n\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n\n#line 4 \"graph/strongly_connected_components.hpp\"\n\ntemplate <typename\
    \ G>\nclass StronglyConnectedComponents {    \n    std::vector<int> comp_id;\n\
    \    int comp_num;\n    \npublic:\n    StronglyConnectedComponents(const G &g)\
    \ : comp_id(g.size(), -1), comp_num(0) {\n        int now = 0;\n        std::vector<int>\
    \ vs;\n        std::vector<int> ord(g.size(), -1);\n        std::vector<int> low(g.size(),\
    \ -1);\n        \n        const auto dfs = [&](const auto &dfs, int v) -> void\
    \ {\n            vs.push_back(v);\n            ord[v] = now++;\n            low[v]\
    \ = ord[v];\n            for (int u : g[v]) {\n                if (comp_id[u]\
    \ != -1) {\n                    continue;\n                }\n               \
    \ if (ord[u] == -1) {\n                    dfs(dfs, u);\n                }\n \
    \               low[v] = std::min(low[v], low[u]);\n            }\n          \
    \  if (low[v] == ord[v]) {\n                while (true) {\n                 \
    \   int u = vs.back();\n                    vs.pop_back();\n                 \
    \   comp_id[u] = comp_num;\n                    if (u == v) {\n              \
    \          break;\n                    }\n                }\n                ++comp_num;\n\
    \            }\n        };\n        \n        for (int v = 0; v < (int) g.size();\
    \ ++v) {\n            if (ord[v] == -1) {\n                dfs(dfs, v);\n    \
    \        }\n        }\n        \n        for (int v = 0; v < (int) g.size(); ++v)\
    \ {\n            comp_id[v] = comp_num - 1 - comp_id[v];\n        }\n    }\n \
    \   \n    int comps() const {\n        return comp_num;\n    }\n\n    int operator[](int\
    \ v) const {\n        assert(v >= 0 && v < (int) comp_id.size());\n        return\
    \ comp_id[v];\n    }\n\n    std::vector<std::vector<int>> groups() const {\n \
    \       std::vector<std::vector<int>> ret(comp_num);\n        for (int v = 0;\
    \ v < (int) comp_id.size(); ++v) {\n            ret[comp_id[v]].push_back(v);\n\
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
    \  return ans;\n    }\n};\n\n#line 7 \"graph/test/two_sat.test.cpp\"\n\nint main()\
    \ {\n    string dummy;\n    cin >> dummy >> dummy;\n    i32 n, m;\n    cin >>\
    \ n >> m;\n    TwoSat sat;\n    Vec<TwoSat::Variable> vars = sat.add_variables(n);\n\
    \    REP(ci, m) {\n        i32 a, b;\n        cin >> a >> b >> dummy;\n      \
    \  TwoSat::Variable a_ = (a > 0 ? vars[a - 1] : !vars[-a - 1]);\n        TwoSat::Variable\
    \ b_ = (b > 0 ? vars[b - 1] : !vars[-b - 1]);\n        sat.add_clause(a_, b_);\n\
    \    }\n    optional<Vec<bool>> ans = sat.solve();\n    if (ans.has_value()) {\n\
    \        cout << \"s SATISFIABLE\\n\";\n        cout << \"v \";\n        REP(i,\
    \ n) {\n            bool b = (*ans)[vars[i].index()];\n            cout << (b\
    \ ? i + 1 : -i - 1) << ' ';\n        }\n        cout << \"0\\n\";\n    } else\
    \ {\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#define FAST_IO\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/two_sat.hpp\"\
    \n\nint main() {\n    string dummy;\n    cin >> dummy >> dummy;\n    i32 n, m;\n\
    \    cin >> n >> m;\n    TwoSat sat;\n    Vec<TwoSat::Variable> vars = sat.add_variables(n);\n\
    \    REP(ci, m) {\n        i32 a, b;\n        cin >> a >> b >> dummy;\n      \
    \  TwoSat::Variable a_ = (a > 0 ? vars[a - 1] : !vars[-a - 1]);\n        TwoSat::Variable\
    \ b_ = (b > 0 ? vars[b - 1] : !vars[-b - 1]);\n        sat.add_clause(a_, b_);\n\
    \    }\n    optional<Vec<bool>> ans = sat.solve();\n    if (ans.has_value()) {\n\
    \        cout << \"s SATISFIABLE\\n\";\n        cout << \"v \";\n        REP(i,\
    \ n) {\n            bool b = (*ans)[vars[i].index()];\n            cout << (b\
    \ ? i + 1 : -i - 1) << ' ';\n        }\n        cout << \"0\\n\";\n    } else\
    \ {\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/two_sat.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: graph/test/two_sat.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 19:58:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/two_sat.test.cpp
layout: document
redirect_from:
- /verify/graph/test/two_sat.test.cpp
- /verify/graph/test/two_sat.test.cpp.html
title: graph/test/two_sat.test.cpp
---
