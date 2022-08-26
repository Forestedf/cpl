#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../convolution/or_convolution.hpp"
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
    i32 mask = (1 << n) - 1;
    REP(i, 1 << n) {
        if (i & 1) {
            swap(a[i], a[(~i) & mask]);
            swap(b[i], b[(~i) & mask]);
        }
    }
    Vec<Mint> c = or_convolution(a, b);
    REP(i, 1 << n) {
        if (i & 1) {
            swap(c[i], c[(~i) & mask]);
        }
    }
    REP(i, 1 << n) {
        cout << c[i] << " \n"[i + 1 == (1 << n)];
    }
}