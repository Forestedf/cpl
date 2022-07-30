#pragma once

#include <atcoder/mincostflow>
#include <optional>

template <typename Cap, typename Cost>
class MinCostFlow {
    atcoder::mcf_graph<Cap, Cost> graph;
    std::vector<Cap> supply;
    Cost ans;
    
public:
    MinCostFlow(int n) : graph(n + 2), supply(n, 0), ans(0) {}
    
    void add_supply(int v, Cap s) {
        assert(v < (int) supply.size());
        supply[v] += s;
    }
    
    void add_edge(int from, int to, Cap cap, Cost cost) {
        assert(from >= 0 && from < supply.size() && to >= 0 && to < supply.size());
        assert(0 <= cap);
        if (cost < 0) {
            ans += cost * cap;
            add_supply(to, cap);
            add_supply(from, -cap);
            graph.add_edge(to, from, cap, -cost);
        } else {
            graph.add_edge(from, to, cap, cost);
        }
    }
    
    void add_edge(int from, int to, Cap lower, Cap upper, Cost cost) {
        assert(from >= 0 && from < supply.size() && to >= 0 && to < supply.size());
        assert(0 <= lower && lower <= upper);
        ans += cost * lower;
        add_supply(to, lower);
        add_supply(from, -lower);
        add_edge(from, to, upper - lower, cost);
    }
    
    std::optional<Cost> solve() {
        int super_s = (int) supply.size();
        int super_t = super_s + 1;
        Cap neg_sum = 0;
        Cap pos_sum = 0;
        for (int i = 0; i < supply.size(); ++i) {
            if (supply[i] < 0) {
                graph.add_edge(i, super_t, -supply[i], 0);
                neg_sum += supply[i];
            } else if (supply[i] > 0) {
                graph.add_edge(super_s, i, supply[i], 0);
                pos_sum += supply[i];
            }
        }
        if (-neg_sum != pos_sum) {
            return std::nullopt;
        }
        std::pair<Cap, Cost> ret = graph.flow(super_s, super_t, pos_sum);
        if (ret.first != pos_sum) {
            return std::nullopt;
        } else {
            return std::optional<Cost>(ans + ret.second);
        }
    }
};

