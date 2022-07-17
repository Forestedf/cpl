#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../polynomial/with_acl.hpp"
#include "../../polynomial/fps_log.hpp"

using Mint = atcoder::modint998244353;

istream &operator>>(istream &is, Mint &x) {
    i32 val;
    is >> val;
    x = Mint(val);
    return is;
}
ostream &operator<<(ostream &os, Mint x) {
    os << x.val();
    return os;
}

int main() {
    using FPS = Polynomial<Mint, ACLNTT<998244353>>;
    
    i32 n;
    cin >> n;
    FPS f(n);
    REP(i, n) {
        cin >> f[i];
    }
    FPS g = fps_log(f);
    REP(i, n) {
        cout << g[i] << " \n"[i + 1 == n];
    }
}
