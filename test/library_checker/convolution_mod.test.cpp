#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/number_theoretic_transform.hpp"

int main() {
    using Mint = ModInt<mod998244353>;
    
    constexpr NumberTheoreticTransform<mod998244353> ntt;
    
    i32 n, m;
    cin >> n >> m;
    Vec<Mint> a(n), b(m);
    REP(i, n) {
        cin >> a[i];
    }
    REP(i, m) {
        cin >> b[i];
    }
    Vec<Mint> c = ntt.multiply(a, b);
    REP(i, c.size()) {
        cout << c[i] << " \n"[i + 1 == (int) c.size()];
    }
}