#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../graph/graph.hpp"
#include "../../graph/heavy_light_decomposition.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    Graph<i32> g(n);
    REP(ei, n - 1) {
        i32 a, b;
        cin >> a >> b;
        g.add_undirected_edge(a, b);
    }
    HeavyLightDecomposition hld(g);
    REP(qi, q) {
        i32 s, t, i;
        cin >> s >> t >> i;
        cout << hld.jump(s, t, i) << '\n';
    }
}