#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../graph/graph.hpp"
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../data_structure/segment_tree.hpp"

using Mint = ModInt<mod998244353>;

struct Linear {
    Mint a, b;
    Linear() : a(Mint(1)), b(Mint(0)) {}
    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}
    Mint operator()(Mint x) const {
        return a * x + b;
    }
};

Linear composite(const Linear &f, const Linear &g) {
    return Linear(f.a * g.a, f.a * g.b + f.b);
}

struct Ops {
    using Value = Linear;
    static Value id() {
        return Linear();
    }
    static Value op(const Value &f, const Value &g) {
        return composite(f, g);
    }
};

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<Linear> fs(n);
    REP(i, n) {
        cin >> fs[i].a >> fs[i].b;
    }
    Graph<i32> g(n);
    REP(e, n - 1) {
        i32 u, v;
        cin >> u >> v;
        g.add_undirected_edge(u, v);
    }
    HeavyLightDecomposition hld(g);
    SegmentTree<Reversible<Ops>> seg(n, [&](i32 i) -> typename Reversible<Ops>::Value {
        Linear f = fs[hld.time_to_vertex(i)];
        return pair<Linear, Linear>(f, f);
    });
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 p;
            Linear f;
            cin >> p >> f.a >> f.b;
            seg.update(hld.in_time(p), pair<Linear, Linear>(f, f));
        } else {
            i32 u, v;
            Mint x;
            cin >> u >> v >> x;
            Linear f;
            for (auto [l, r] : hld.path(u, v, false)) {
                if (l < r) {
                    f = composite(seg.prod(l, r + 1).second, f);
                } else {
                    f = composite(seg.prod(r, l + 1).first, f);
                }
            }
            cout << f(x) << '\n';
        }
    }
}
