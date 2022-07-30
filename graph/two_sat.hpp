#pragma once

#include "strongly_connected_components.hpp"

#include <optional>

class TwoSat {
public:
    struct Variable {
    private:
        int idx;
            
        Variable(int i) : idx(i) {}
        
    public:
        Variable operator!() const noexcept {
            return Variable(idx ^ 1);
        }
        
        int index() const {
            return idx / 2;
        }
        
        friend class TwoSat;
    };
    
private:
    std::vector<std::vector<int>> graph;
    
public:
    TwoSat() : graph() {}
    
    TwoSat::Variable add_variable() {
        Variable var(graph.size());
        graph.resize(graph.size() + 2, std::vector<int>());
        return var;
    }
    
    std::vector<TwoSat::Variable> add_variables(int num) {
        std::vector<TwoSat::Variable> vars;
        vars.reserve(num);
        for (int i = 0; i < num; ++i) {
            vars.emplace_back(Variable((int) graph.size() + 2 * i));
        }
        graph.resize((int) graph.size() + 2 * num, std::vector<int>());
        return vars;
    }
    
    // x or y
    void add_clause(Variable x, Variable y) {
        graph[(!x).idx].push_back(y.idx);
        graph[(!y).idx].push_back(x.idx);
    }
    
    // x implies y
    void implies(Variable x, Variable y) {
        add_clause(!x, y);
    }
    
    void at_most_one(const std::vector<Variable> &vars) {
        if (vars.size() <= 1) {
            return;
        }
        std::vector<Variable> sum = add_variables((int) vars.size() - 1);
        for (int i = 0; i < (int) sum.size(); ++i) {
            implies(vars[i], sum[i]);
            implies(sum[i], !vars[i + 1]);
        }
        for (int i = 0; i < (int) sum.size() - 1; ++i) {
            implies(sum[i], sum[i + 1]);
        }
    }
    
    std::optional<std::vector<bool>> solve() {
        StronglyConnectedComponents scc(graph);
        std::vector<bool> ans(graph.size() / 2, false);
        for (int i = 0; i < (int) graph.size() / 2; ++i) {
            if (scc[2 * i] == scc[2 * i + 1]) {
                return std::nullopt;
            }
            if (scc[2 * i] > scc[2 * i + 1]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};

