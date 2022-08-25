#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

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
    REP(e, n - 1) {
        i32 u, v;
        cin >> u >> v;
        g.add_undirected_edge(u, v);
    }
    HeavyLightDecomposition hld(g);
    FenwickTree<Add<i64>> ft(n);
    REP(i, n) {
        ft.add(hld.in_time(i), a[i]);
    }
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 p;
            i64 x;
            cin >> p >> x;
            ft.add(hld.in_time(p), x);
        } else {
            i32 u, v;
            cin >> u >> v;
            i64 ans = 0;
            for (auto [l, r] : hld.path(u, v, false)) {
                if (l > r) {
                    swap(l, r);
                }
                ans += ft.sum(l, r + 1);
            }
            cout << ans << '\n';
        }        
    }
}