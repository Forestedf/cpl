#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../graph/graph.hpp"
#include "../../graph/strongly_connected_components.hpp"

int main() {
    i32 n, m;
    cin >> n >> m;
    Graph<i32> g(n);
    REP(e, m) {
        i32 u, v;
        cin >> u >> v;
        g.add_directed_edge(u, v);
    }
    StronglyConnectedComponents<Graph<i32>> scc(g);
    Vec<Vec<i32>> groups = scc.groups();
    cout << groups.size() << '\n';
    for (const Vec<i32> &group : groups) {
        cout << group.size();
        for (i32 v : group) {
            cout << ' ' << v;
        }
        cout << '\n';
    }
}