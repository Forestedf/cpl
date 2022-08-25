#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/number_theoretic_transform.hpp"
#include "../../polynomial/fps_pow.hpp"

int main() {
    using Mint = ModInt<mod998244353>;
    using FPS = Polynomial<Mint, NTTMul<mod998244353>>;
    
    i32 n;
    i64 m;
    cin >> n >> m;
    FPS f(n);
    REP(i, n) {
        cin >> f[i];
    }
    FPS g = fps_pow(f, m);
    REP(i, n) {
        cout << g[i] << " \n"[i + 1 == n];
    }
}
