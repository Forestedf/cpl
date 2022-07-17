#pragma once

#include "graph.hpp"

#include <queue>
#include <limits>
#include <functional>

template <typename T>
std::vector<T> dijkstra(const Graph<WeightedEdge<T>> &g, int s) {
    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> pq;
    dist[s] = T(0);
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) {
            continue;
        }
        for (const WeightedEdge<T> &e : g[v]) {
            if (d + e.wt < dist[e.to]) {
                dist[e.to] = d + e.wt;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
    return dist;
}