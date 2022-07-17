#pragma once

#include <vector>

template <typename G>
class StronglyConnectedComponents {    
    std::vector<int> comp_id;
    int comp_num;
    
public:
    StronglyConnectedComponents(const G &g) : comp_id(g.size(), -1), comp_num(0) {
        int now = 0;
        std::vector<int> vs;
        std::vector<int> ord(g.size(), -1);
        std::vector<int> low(g.size(), -1);
        
        const auto dfs = [&](const auto &dfs, int v) -> void {
            vs.push_back(v);
            ord[v] = now++;
            low[v] = ord[v];
            for (int u : g[v]) {
                if (comp_id[u] != -1) {
                    continue;
                }
                if (ord[u] == -1) {
                    dfs(dfs, u);
                }
                low[v] = std::min(low[v], low[u]);
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = vs.back();
                    vs.pop_back();
                    comp_id[u] = comp_num;
                    if (u == v) {
                        break;
                    }
                }
                ++comp_num;
            }
        };
        
        for (int v = 0; v < static_cast<int>(g.size()); ++v) {
            if (ord[v] == -1) {
                dfs(dfs, v);
            }
        }
        
        for (int v = 0; v < static_cast<int>(g.size()); ++v) {
            comp_id[v] = comp_num - 1 - comp_id[v];
        }
    }
    
    int comps() const {
        return comp_num;
    }

    int operator[](int v) const {
        assert(v >= 0 && v < static_cast<int>(comp_id.size()));
        return comp_id[v];
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> ret(comp_num);
        for (int v = 0; v < static_cast<int>(comp_id.size()); ++v) {
            ret[comp_id[v]].push_back(v);
        }
        return ret;
    }
};

