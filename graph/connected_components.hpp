#pragma once
#include <queue>
#include <utility>
#include <vector>

class ConnectedComponents {
    std::vector<int> number;
    int comp;

public:
    template <typename G>
    ConnectedComponents(const G &graph) :
        number(static_cast<int>(graph.size()), -1), comp(0) {
        std::queue<int> que;
        for (int i = 0; i < static_cast<int>(graph.size()); ++i) {
            if (number[i] != -1) {
                continue;
            }
            que.push(i);
            number[i] = comp;
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (const auto &e : graph[v]) {
                    if (number[(int) e] == -1) {
                        number[(int) e] = number[v];
                        que.push((int)e);
                    }
                }
            }
            ++comp;
        }
    }

    int operator[](int v) const {
        assert(v >= 0 && v < static_cast<int>(number.size()));
        return number[v];
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> ret(comp);
        for (int i = 0; i < static_cast<int>(number.size()); ++i)
            ret[number[i]].push_back(i);
        return ret;
    }

    int components() const {
        return comp;
    }
};
