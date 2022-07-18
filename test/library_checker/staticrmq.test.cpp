#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../data_structure/sparse_table.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<i32> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    SparseTable<i32> sp(a);
    REP(qi, q) {
        i32 l, r;
        cin >> l >> r;
        cout << sp.min(l, r) << '\n';
    }
}