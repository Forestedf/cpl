#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../convolution/subset_convolution.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using Mint = ModInt<mod998244353>;
    
    i32 n;
    cin >> n;
    Vec<Mint> a(1 << n), b(1 << n);
    REP(i, 1 << n) {
        cin >> a[i];
    }
    REP(i, 1 << n) {
        cin >> b[i];
    }
    Vec<Mint> c = subset_convolution(a, b);
    REP(i, 1 << n) {
        cout << c[i] << " \n"[i + 1 == (1 << n)];
    }
}
