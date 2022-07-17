#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../algebra/matrix.hpp"

using Mint = ModInt<mod998244353>;

int main() {
    i32 n, m, k;
    cin >> n >> m >> k;
    Matrix<Mint> a(n, m), b(m, k);
    REP(i, n) REP(j, m) {
        cin >> a(i, j);
    }
    REP(i, m) REP(j, k) {
        cin >> b(i, j);
    }
    Matrix<Mint> c = a * b;
    REP(i, n) REP(j, k) {
        cout << c(i, j) << " \n"[j + 1 == k];
    }
}