#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../other/coordinate_compression.hpp"
#include "../../data_structure/wavelet_matrix.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<i32> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    CoordinateCompression<i32> cc(a);
    WaveletMatrix<i32> wm(a);
    REP(qi, q) {
        i32 l, r, k;
        cin >> l >> r >> k;
        i32 sm = wm.kth_smallest(l, r, k);
        cout << cc[sm] << '\n';
    }
}
