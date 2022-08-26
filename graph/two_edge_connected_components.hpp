#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

class TwoEdgeConnectedComponents {
    int comp_num;
    std::vector<int> comp;
    
public:
    template <typename G>
    TwoEdgeConnectedComponents(const G &g) : comp_num(0), comp(g.size(), -1) {
        std::vector<int> ord(g.size(), -1);
        std::vector<int> low(g.size(), -1);
        std::vector<int> found(g.size(), 0);
        const auto dfs0 = [&](const auto &dfs0, int v, int p, int &t) -> void {
            ord[v] = t++;
            low[v] = ord[v];
            bool par = false;
            for (const auto &e : g[v]) {
                int u = (int) e;
                if (!found[u]) {
                    found[u] = 1;
                    dfs0(dfs0, u, v, t);
                    low[v] = std::min(low[v], low[u]);
                }
                bool back = ord[u] < ord[v];
                if (u == p) {
                    if (!par) {
                        back = false;
                        par = true;
                    }
                }
                if (back) {
                    low[v] = std::min(low[v], ord[u]);
                }
            }
        };
        int t = 0;
        for (int v = 0; v < (int) g.size(); ++v) {
            if (!found[v]) {
                found[v] = 1;
                dfs0(dfs0, v, -1, t);
            }
        }
        const auto dfs1 = [&](const auto &dfs1, i32 v, i32 k) -> void {
            comp[v] = k;
            for (const auto &e : g[v]) {
                int u = (int) e;
                if (comp[u] == -1) {
                    if (low[u] > ord[v]) {
                        dfs1(dfs1, u, comp_num++);
                    } else {
                        dfs1(dfs1, u, k);
                    }
                }
            }
        };
        for (int v = 0; v < (int) g.size(); ++v) {
            if (comp[v] == -1) {
                dfs1(dfs1, v, comp_num++);
            }
        }
    }
    
    int operator[](int v) const {
        return comp[v];
    }
    int compc() const {
        return comp_num;
    }
    
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> gs(comp_num);
        for (int i = 0; i < (int) comp.size(); ++i) {
            gs[comp[i]].push_back(i);
        }
        return gs;
    }
};