#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/number_theoretic_transform.hpp"
#include "../../number_theory/factorial_table.hpp"
#include "../../polynomial/taylor_shift.hpp"

int main() {
    using Mint = ModInt<mod998244353>;
    
    i32 n;
    Mint c;
    cin >> n >> c;
    Vec<Mint> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    FactorialTable<Mint> table(n);
    Vec<Mint> b = taylor_shift<Mint, FactorialTable<Mint>, NTTMul<mod998244353>>(a, c, table);
    REP(i, n) {
        cout << b[i] << " \n"[i + 1 == n];
    }
}
