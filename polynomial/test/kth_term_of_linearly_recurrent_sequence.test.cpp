#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../polynomial/fps_div_at.hpp"
#include "../../number_theory/number_theoretic_transform.hpp"

using Mint = ModInt<mod998244353>;
using FPS = Polynomial<Mint, NTTMul<mod998244353>>;

int main() {
    i32 d;
    i64 k;
    cin >> d >> k;
    Vec<Mint> a(d);
    REP(i, d) {
        cin >> a[i];
    }
    Vec<Mint> c(d + 1);
    REP(i, 1, d + 1) {
        cin >> c[i];
    }
    
    c[0] = Mint(1);
    REP(i, 1, d + 1) {
        c[i] = -c[i];
    }
    
    FPS f = FPS(a) * FPS(c);
    f.pre_(d);
    Mint ans = fps_div_at(f, FPS(c), k);
    cout << ans << '\n';
}