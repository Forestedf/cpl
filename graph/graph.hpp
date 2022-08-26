#pragma once

#include <utility>
#include <vector>
#include <numeric>
#include <cassert>

template <typename Edge>
class Graph {
    std::vector<std::vector<Edge>> edges;

public:
    Graph() : edges() {}
    Graph(int v) : edges(v) {
        assert(v >= 0);
    }
    
    std::vector<int> add_vertices(int n) {
        int v = (int) edges.size();
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), v);
        edges.resize(edges.size() + n);
        return idx;
    }

    template <typename... T>
    void add_directed_edge(int from, int to, T &&...val) {
        assert(from >= 0 && from < (int) edges.size());
        assert(to >= 0 && to < (int) edges.size());
        edges[from].emplace_back(Edge(to, std::forward<T>(val)...));
    }

    template <typename... T>
    void add_undirected_edge(int u, int v, const T &...val) {
        assert(u >= 0 && u < (int) edges.size());
        assert(v >= 0 && v < (int) edges.size());
        edges[u].emplace_back(Edge(v, val...));
        edges[v].emplace_back(Edge(u, val...));
    }

    int size() const {
        return (int) edges.size();
    }

    const std::vector<Edge> &operator[](int v) const {
        assert(v >= 0 && v < (int) edges.size());
        return edges[v];
    }

    std::vector<Edge> &operator[](int v) {
        assert(v >= 0 && v < (int) edges.size());
        return edges[v];
    }
};

struct UnweightedEdge {
    int to;

    UnweightedEdge(int t) : to(t) {}
    
    explicit operator int() const {
        return to;
    }

    using Weight = int;
    Weight weight() const {
        return 1;
    }
};

template <typename T>
struct WeightedEdge {
    int to;
    T wt;

    WeightedEdge(int t, const T &w) : to(t), wt(w) {}

    explicit operator int() const {
        return to;
    }

    using Weight = T;
    Weight weight() const {
        return wt;
    }
};

