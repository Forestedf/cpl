#pragma once

#include <vector>
#include <queue>

template <typename G>
class CentroidDecomposition {
    const G &g;
    
    std::vector<std::vector<int>> to;
    std::vector<bool> used;
    std::vector<int> size;
    int first;
    
    void dfs(int v, int p) {
        size[v] = 1;
        for (int u : g[v]) {
            if (u == p || used[u]) {
                continue;
            }
            dfs(u, v);
            size[v] += size[u];
        }
    }
    
    int find_centroid(int v) {
        dfs(v, v);
        int sz = size[v];
        int p = v;
        while (true) {
            bool ok = true;
            for (int u : g[v]) {
                if (u == p || used[u]) {
                    continue;
                }
                if (size[u] > sz / 2) {
                    p = v;
                    v = u;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        return v;
    }
    
    int decomposite(int v) {
        int cent = find_centroid(v);
        used[cent] = true;
        for (int u : g[cent]) {
            if (used[u]) {
                continue;
            }
            to[cent].push_back(decomposite(u));
        }
        return cent;
    }
    
public:
    CentroidDecomposition(const G &_g) :
    g(_g),
    to((int) g.size()),
    used((int) g.size(), false),
    size((int) g.size(), 0) {
        first = decomposite(0);
    }
    
    int first_centroid() const {
        return first;
    }
    
    const std::vector<int> &next_centroids(int v) const {
        assert(v >= 0 && v < (int) g.size());
        return to[v];
    }
};

