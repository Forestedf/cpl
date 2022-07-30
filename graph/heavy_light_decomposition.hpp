#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

class HeavyLightDecomposition {
    std::vector<int> siz;
    std::vector<int> par;
    std::vector<int> hea;
    std::vector<int> in;
    std::vector<int> out;
    std::vector<int> dep;
    std::vector<int> rev;

    template <typename G>
    void dfs1(G &g, int v) {
        if (!g[v].empty() && (int) g[v][0] == par[v]) {
            std::swap(g[v][0], g[v].back());
        }
        for (auto &e : g[v]) {
            int u = (int)e;
            if (u != par[v]) {
                par[u] = v;
                dfs1(g, u);
                siz[v] += siz[u];
                if (siz[u] > siz[g[v][0]]) {
                    std::swap(g[v][0], e);
                }
            }
        }
    }

    template <typename G>
    void dfs2(const G &g, int v, int &time) {
        in[v] = time;
        rev[time++] = v;
        for (auto &e : g[v]) {
            int u = (int)e;
            if (u == par[v]) {
                continue;
            }
            if (u == (int) g[v][0]) {
                hea[u] = hea[v];
            } else {
                hea[u] = u;
            }
            dep[u] = dep[v] + 1;
            dfs2(g, u, time);
        }
        out[v] = time;
    }

public:
    template <typename G>
    HeavyLightDecomposition(G &g, int root = 0) :
        siz(g.size(), 1),
        par(g.size(), root),
        hea(g.size(), root),
        in(g.size(), 0),
        out(g.size(), 0),
        dep(g.size(), 0),
        rev(g.size(), 0) {
        assert(root >= 0 && root < (int) g.size());
        dfs1(g, root);
        int time = 0;
        dfs2(g, root, time);
    }

    int subtree_size(int v) const {
        assert(v >= 0 && v < (int) siz.size());
        return siz[v];
    }

    int parent(int v) const {
        assert(v >= 0 && v < (int) par.size());
        return par[v];
    }

    int in_time(int v) const {
        assert(v >= 0 && v < (int) in.size());
        return in[v];
    }

    int out_time(int v) const {
        assert(v >= 0 && v < (int) out.size());
        return out[v];
    }

    int depth(int v) const {
        assert(v >= 0 && v < (int) dep.size());
        return dep[v];
    }

    int time_to_vertex(int t) const {
        assert(t >= 0 && t < (int) rev.size());
        return rev[t];
    }
    
    int la(int v, int k) const {
        assert(v >= 0 && v < (int) dep.size());
        assert(k >= 0);
        while (true) {
            int u = hea[v];
            if (in[u] + k <= in[v]) {
                return rev[in[v] - k];
            }
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
        return 0;
    }
    
    int forward(int v, int dst) const {
        assert(v >= 0 && v < (int) dep.size());
        assert(dst >= 0 && dst < (int) dep.size());
        assert(v != dst);
        int l = lca(v, dst);
        if (l == v) {
            return la(dst, dist(v, dst) - 1);
        } else {
            return par[v];
        }
    }

    int lca(int u, int v) const {
        assert(u >= 0 && u < (int) dep.size());
        assert(v >= 0 && v < (int) dep.size());
        while (u != v) {
            if (in[u] > in[v]) {
                std::swap(u, v);
            }
            if (hea[u] == hea[v]) {
                v = u;
            } else {
                v = par[hea[v]];
            }
        }
        return u;
    }

    int dist(int u, int v) const {
        assert(u >= 0 && u < (int) dep.size());
        assert(v >= 0 && v < (int) dep.size());        
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    std::vector<std::pair<int, int>> path(int u, int v, bool edge) const {
        assert(u >= 0 && u < (int) dep.size());
        assert(v >= 0 && v < (int) dep.size());
        std::vector<std::pair<int, int>> fromu, fromv;
        bool rev = false;
        while (true) {
            if (u == v && edge) {
                break;
            }
            if (in[u] > in[v]) {
                std::swap(u, v);
                std::swap(fromu, fromv);
                rev ^= true;
            }
            if (hea[u] == hea[v]) {
                fromv.emplace_back(in[v], in[u] + (int)edge);
                v = u;
                break;
            } else {
                fromv.emplace_back(in[v], in[hea[v]]);
                v = par[hea[v]];
            }
        }
        if (rev) {
            std::swap(fromu, fromv);
        }
        std::reverse(fromv.begin(), fromv.end());
        fromu.reserve(fromv.size());
        for (auto [x, y] : fromv) {
            fromu.emplace_back(y, x);
        }
        return fromu;
    }
};

