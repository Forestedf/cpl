#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../convolution/subset_convolution_exp.hpp"
#include "../../number_theory/mod_int.hpp"

using Mint = ModInt<mod998244353>;

int main() {
    i32 n;
    cin >> n;
    Vec<Mint> a(1 << n);
    REP(i, 1 << n) {
        cin >> a[i];
    }
    Vec<Mint> b = subset_convolution_exp(a);
    REP(i, 1 << n) {
        cout << b[i] << " \n"[i + 1 == (1 << n)];
    }
}