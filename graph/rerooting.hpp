#pragma once

#include <optional>
#include <queue>
#include <utility>
#include <vector>

template <typename G, typename T, typename Apply, typename Merge>
T rerooting_sub1(
    const G &g,
    const T &id,
    const Apply &ap,
    const Merge &me,
    int v,
    int p,
    std::vector<std::vector<std::optional<T>>> &dp) {
    T acc = id;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if ((int) g[v][i] != p) {
            T val = rerooting_sub1(g, id, ap, me, (int) g[v][i], v, dp);
            dp[v][i] = ap(val, v, g[v][i]);
            acc = me(acc, *dp[v][i]);
        }
    }
    return acc;
}

template <typename G, typename T, typename Apply, typename Merge>
void rerooting_sub2(
    const G &g,
    const T &id,
    const Apply &ap,
    const Merge &me,
    int root,
    std::vector<std::vector<std::optional<T>>> &dp) {
    std::queue<std::pair<int, T>> que;
    que.emplace(root, id);
    while (!que.empty()) {
        auto [v, val] = que.front();
        que.pop();
        std::vector<T> acc_l(g[v].size() + 1);
        acc_l[0] = id;
        int emp_idx = -1;
        for (int i = 0; i < (int) g[v].size(); ++i) {
            if (!(bool) dp[v][i]) {
                dp[v][i] = ap(val, v, g[v][i]);
                emp_idx = i;
            }
            acc_l[i + 1] = me(acc_l[i], *dp[v][i]);
        }
        T acc_r = id;
        for (int i = (int) g[v].size() - 1; i >= 0; --i) {
            if (i != emp_idx) {
                que.emplace((int) g[v][i], me(acc_l[i], acc_r));
            }
            acc_r = me(*dp[v][i], acc_r);
        }
    }
}

// Apply: Fn(T, int, E) -> T
// Merge: Fn(T, T) -> T
template <typename G, typename T, typename Apply, typename Merge>
std::vector<T>
rerooting(const G &g, const T &id, const Apply &ap, const Merge &me) {
    std::vector<std::vector<std::optional<T>>> dp(g.size());
    for (int i = 0; i < (int) g.size(); ++i) {
        dp[i].resize(g[i].size(), std::nullopt);
    }
    rerooting_sub1(g, id, ap, me, 0, 0, dp);
    rerooting_sub2(g, id, ap, me, 0, dp);
    std::vector<T> buf(g.size(), id);
    for (int i = 0; i < (int) g.size(); ++i) {
        for (std::optional<T> &val : dp[i]) {
            buf[i] = me(buf[i], std::move(*val));
        }
    }
    return buf;
}

template <typename G, typename T, typename Apply, typename Merge>
std::vector<std::vector<T>>
rerooting_raw(const G &g, const T &id, const Apply &ap, const Merge &me) {
    std::vector<std::vector<std::optional<T>>> dp(g.size());
    for (int i = 0; i < (int) g.size(); ++i) {
        dp[i].resize(g[i].size(), std::nullopt);
    }
    rerooting_sub1(g, id, ap, me, 0, 0, dp);
    rerooting_sub2(g, id, ap, me, 0, dp);
    std::vector<std::vector<T>> buf(g.size());
    for (int i = 0; i < (int) g.size(); ++i) {
        buf[i].reserve(g[i].size());
        for (const std::optional<T> &val : dp[i]) {
            buf[i].emplace_back(*val);
        }
    }
    return buf;
}
