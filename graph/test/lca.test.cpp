#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../graph/graph.hpp"
#include "../../graph/heavy_light_decomposition.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    Graph<i32> g(n);
    REP(i, 1, n) {
        i32 p;
        cin >> p;
        g.add_undirected_edge(p, i);
    }
    HeavyLightDecomposition hld(g);
    REP(qi, q) {
        i32 u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << '\n';
    }
}