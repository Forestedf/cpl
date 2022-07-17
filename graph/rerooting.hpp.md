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
  bundledCode: "#line 2 \"graph/rerooting.hpp\"\n\n#include <optional>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename G, typename T, typename\
    \ Apply, typename Merge>\nT rerooting_sub1(\n    const G &g,\n    const T &id,\n\
    \    const Apply &ap,\n    const Merge &me,\n    int v,\n    int p,\n    std::vector<std::vector<std::optional<T>>>\
    \ &dp) {\n    T acc = id;\n    for (int i = 0; i < (int) g[v].size(); ++i) {\n\
    \        if ((int) g[v][i] != p) {\n            T val = rerooting_sub1(g, id,\
    \ ap, me, (int) g[v][i], v, dp);\n            dp[v][i] = ap(val, v, g[v][i]);\n\
    \            acc = me(acc, *dp[v][i]);\n        }\n    }\n    return acc;\n}\n\
    \ntemplate <typename G, typename T, typename Apply, typename Merge>\nvoid rerooting_sub2(\n\
    \    const G &g,\n    const T &id,\n    const Apply &ap,\n    const Merge &me,\n\
    \    int root,\n    std::vector<std::vector<std::optional<T>>> &dp) {\n    std::queue<std::pair<int,\
    \ T>> que;\n    que.emplace(root, id);\n    while (!que.empty()) {\n        auto\
    \ [v, val] = que.front();\n        que.pop();\n        std::vector<T> acc_l(g[v].size()\
    \ + 1);\n        acc_l[0] = id;\n        int emp_idx = -1;\n        for (int i\
    \ = 0; i < (int) g[v].size(); ++i) {\n            if (!(bool) dp[v][i]) {\n  \
    \              dp[v][i] = ap(val, v, g[v][i]);\n                emp_idx = i;\n\
    \            }\n            acc_l[i + 1] = me(acc_l[i], *dp[v][i]);\n        }\n\
    \        T acc_r = id;\n        for (int i = (int) g[v].size() - 1; i >= 0; --i)\
    \ {\n            if (i != emp_idx) {\n                que.emplace((int) g[v][i],\
    \ me(acc_l[i], acc_r));\n            }\n            acc_r = me(*dp[v][i], acc_r);\n\
    \        }\n    }\n}\n\n// Apply: Fn(T, int, E) -> T\n// Merge: Fn(T, T) -> T\n\
    template <typename G, typename T, typename Apply, typename Merge>\nstd::vector<T>\n\
    rerooting(const G &g, const T &id, const Apply &ap, const Merge &me) {\n    std::vector<std::vector<std::optional<T>>>\
    \ dp(g.size());\n    for (int i = 0; i < (int) g.size(); ++i) {\n        dp[i].resize(g[i].size(),\
    \ std::nullopt);\n    }\n    rerooting_sub1(g, id, ap, me, 0, 0, dp);\n    rerooting_sub2(g,\
    \ id, ap, me, 0, dp);\n    std::vector<T> buf(g.size(), id);\n    for (int i =\
    \ 0; i < (int) g.size(); ++i) {\n        for (std::optional<T> &val : dp[i]) {\n\
    \            buf[i] = me(buf[i], std::move(*val));\n        }\n    }\n    return\
    \ buf;\n}\n\ntemplate <typename G, typename T, typename Apply, typename Merge>\n\
    std::vector<std::vector<T>>\nrerooting_raw(const G &g, const T &id, const Apply\
    \ &ap, const Merge &me) {\n    std::vector<std::vector<std::optional<T>>> dp(g.size());\n\
    \    for (int i = 0; i < (int) g.size(); ++i) {\n        dp[i].resize(g[i].size(),\
    \ std::nullopt);\n    }\n    rerooting_sub1(g, id, ap, me, 0, 0, dp);\n    rerooting_sub2(g,\
    \ id, ap, me, 0, dp);\n    std::vector<std::vector<T>> buf(g.size());\n    for\
    \ (int i = 0; i < (int) g.size(); ++i) {\n        buf[i].reserve(g[i].size());\n\
    \        for (const std::optional<T> &val : dp[i]) {\n            buf[i].emplace_back(*val);\n\
    \        }\n    }\n    return buf;\n}\n"
  code: "#pragma once\n\n#include <optional>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename G, typename T, typename Apply, typename\
    \ Merge>\nT rerooting_sub1(\n    const G &g,\n    const T &id,\n    const Apply\
    \ &ap,\n    const Merge &me,\n    int v,\n    int p,\n    std::vector<std::vector<std::optional<T>>>\
    \ &dp) {\n    T acc = id;\n    for (int i = 0; i < (int) g[v].size(); ++i) {\n\
    \        if ((int) g[v][i] != p) {\n            T val = rerooting_sub1(g, id,\
    \ ap, me, (int) g[v][i], v, dp);\n            dp[v][i] = ap(val, v, g[v][i]);\n\
    \            acc = me(acc, *dp[v][i]);\n        }\n    }\n    return acc;\n}\n\
    \ntemplate <typename G, typename T, typename Apply, typename Merge>\nvoid rerooting_sub2(\n\
    \    const G &g,\n    const T &id,\n    const Apply &ap,\n    const Merge &me,\n\
    \    int root,\n    std::vector<std::vector<std::optional<T>>> &dp) {\n    std::queue<std::pair<int,\
    \ T>> que;\n    que.emplace(root, id);\n    while (!que.empty()) {\n        auto\
    \ [v, val] = que.front();\n        que.pop();\n        std::vector<T> acc_l(g[v].size()\
    \ + 1);\n        acc_l[0] = id;\n        int emp_idx = -1;\n        for (int i\
    \ = 0; i < (int) g[v].size(); ++i) {\n            if (!(bool) dp[v][i]) {\n  \
    \              dp[v][i] = ap(val, v, g[v][i]);\n                emp_idx = i;\n\
    \            }\n            acc_l[i + 1] = me(acc_l[i], *dp[v][i]);\n        }\n\
    \        T acc_r = id;\n        for (int i = (int) g[v].size() - 1; i >= 0; --i)\
    \ {\n            if (i != emp_idx) {\n                que.emplace((int) g[v][i],\
    \ me(acc_l[i], acc_r));\n            }\n            acc_r = me(*dp[v][i], acc_r);\n\
    \        }\n    }\n}\n\n// Apply: Fn(T, int, E) -> T\n// Merge: Fn(T, T) -> T\n\
    template <typename G, typename T, typename Apply, typename Merge>\nstd::vector<T>\n\
    rerooting(const G &g, const T &id, const Apply &ap, const Merge &me) {\n    std::vector<std::vector<std::optional<T>>>\
    \ dp(g.size());\n    for (int i = 0; i < (int) g.size(); ++i) {\n        dp[i].resize(g[i].size(),\
    \ std::nullopt);\n    }\n    rerooting_sub1(g, id, ap, me, 0, 0, dp);\n    rerooting_sub2(g,\
    \ id, ap, me, 0, dp);\n    std::vector<T> buf(g.size(), id);\n    for (int i =\
    \ 0; i < (int) g.size(); ++i) {\n        for (std::optional<T> &val : dp[i]) {\n\
    \            buf[i] = me(buf[i], std::move(*val));\n        }\n    }\n    return\
    \ buf;\n}\n\ntemplate <typename G, typename T, typename Apply, typename Merge>\n\
    std::vector<std::vector<T>>\nrerooting_raw(const G &g, const T &id, const Apply\
    \ &ap, const Merge &me) {\n    std::vector<std::vector<std::optional<T>>> dp(g.size());\n\
    \    for (int i = 0; i < (int) g.size(); ++i) {\n        dp[i].resize(g[i].size(),\
    \ std::nullopt);\n    }\n    rerooting_sub1(g, id, ap, me, 0, 0, dp);\n    rerooting_sub2(g,\
    \ id, ap, me, 0, dp);\n    std::vector<std::vector<T>> buf(g.size());\n    for\
    \ (int i = 0; i < (int) g.size(); ++i) {\n        buf[i].reserve(g[i].size());\n\
    \        for (const std::optional<T> &val : dp[i]) {\n            buf[i].emplace_back(*val);\n\
    \        }\n    }\n    return buf;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting.hpp
layout: document
redirect_from:
- /library/graph/rerooting.hpp
- /library/graph/rerooting.hpp.html
title: graph/rerooting.hpp
---
