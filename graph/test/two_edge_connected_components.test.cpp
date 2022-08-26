#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#define FAST_IO

#include "../../template/template.hpp"
#include "../graph.hpp"
#include "../two_edge_connected_components.hpp"

int main() {
    i32 n, m;
    cin >> n >> m;
    Graph<i32> g(n);
    REP(i, m) {
        i32 u, v;
        cin >> u >> v;
        g.add_undirected_edge(u, v);
    }
    TwoEdgeConnectedComponents cc(g);
    Vec<Vec<i32>> groups = cc.groups();
    cout << groups.size() << '\n';
    for (const Vec<i32> &c : groups) {
        cout << c.size();
        for (i32 v : c) {
            cout << ' ' << v;
        }
        cout << '\n';
    }
}
