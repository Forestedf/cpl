#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../graph/graph.hpp"
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../data_structure/fenwick_tree.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<i64> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    Graph<i32> g(n);
    REP(i, 1, n) {
        i32 p;
        cin >> p;
        g.add_undirected_edge(p, i);
    }
    HeavyLightDecomposition hld(g);
    FenwickTree<Add<i64>> fw(n);
    REP(i, n) {
        fw.add(hld.in_time(i), a[i]);
    }
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 u;
            i64 x;
            cin >> u >> x;
            fw.add(hld.in_time(u), x);
        } else{
            i32 u;
            cin >> u;
            cout << fw.sum(hld.in_time(u), hld.out_time(u)) << '\n';
        }
    }
}