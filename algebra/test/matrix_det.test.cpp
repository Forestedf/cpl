#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../algebra/matrix.hpp"

using Mint = ModInt<mod998244353>;

int main() {
    i32 n;
    cin >> n;
    Matrix<Mint> a(n);
    REP(i, n) REP(j, n) {
        cin >> a(i, j);
    }
    Mint det = a.det();
    cout << det << '\n';
}