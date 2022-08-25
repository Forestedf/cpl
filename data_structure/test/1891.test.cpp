#define PROBLEM "https://yukicoder.me/problems/no/1891"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../data_structure/segment_tree_xor_range.hpp"

using Mint = ModInt<mod998244353>;

struct Linear {
    Mint a, b;
    Linear() : a(Mint(1)), b(Mint(0)) {}
    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}
    Mint operator()(Mint x) {
        return a * x + b;
    }
};

// f \circ g
Linear composite(const Linear &f, const Linear &g) {
    return Linear(f.a * g.a, f.a * g.b + f.b);
}

struct Ops {
    using Value = Linear;
    static Value id() {
        return Linear();
    }
    static Value op(const Value &x, const Value &y) {
        return composite(y, x);
    }
};

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<Linear> fs(n);
    REP(i, n) {
        cin >> fs[i].a >> fs[i].b;
    }
    SegmentTreeXorRange<Ops> seg(fs);
    REP(qi, q) {
        i32 l, r, p;
        Mint x;
        cin >> l >> r >> p >> x;
        cout << seg.prod(l, r, p)(x) << '\n';
    }
}