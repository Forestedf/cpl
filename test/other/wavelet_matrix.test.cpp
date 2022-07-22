#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../other/xorshift.hpp"
#include "../../data_structure/wavelet_matrix.hpp"

constexpr i32 ITER = 100;
constexpr i32 LEN = 100;
constexpr i32 SIGMA = 100;

void test(const Vec<i32> &a, XorShift64 &rd) {
    WaveletMatrix<i32> wm(a);
    
    i32 n = (i32) a.size();
    
    // access
    REP(i, n) {
        assert(wm.access(i) == a[i]);
    }
    
    // kth_smallest
    REP(_iter, ITER) {
        i32 l = rd.uniform(0, n - 1);
        i32 r = rd.uniform(l + 1, n);
        i32 k = rd.uniform(0, r - l - 1);
        
        Vec<i32> b(a.begin() + l, a.begin() + r);
        sort(ALL(b));
        assert(wm.kth_smallest(l, r, k) == b[k]);
    }
    
    // rank
    REP(_iter, ITER) {
        i32 l = rd.uniform(0, n - 1);
        i32 r = rd.uniform(l + 1, n);
        i32 v = rd.uniform(0, SIGMA + 10);
        
        assert(wm.rank(l, r, v) == count(a.begin() + l, a.begin() + r, v));
    }
    
    // range_freq
    REP(_iter, ITER) {
        i32 l = rd.uniform(0, n - 1);
        i32 r = rd.uniform(l + 1, n);
        i32 lower = rd.uniform(0, SIGMA);
        i32 upper = rd.uniform(lower + 1, SIGMA + 10);
        
        i32 cnt = 0;
        REP(i, l, r) {
            if (lower <= a[i] && a[i] < upper) {
                ++cnt;
            }
        }
        assert(wm.range_freq(l, r, lower, upper) == cnt);
    }
    
    // prev
    REP(_iter, ITER) {
        i32 l = rd.uniform(0, n - 1);
        i32 r = rd.uniform(l + 1, n);
        i32 upper = rd.uniform(0, SIGMA + 10);
        
        i32 mx = -1;
        REP(i, l, r) {
            if (a[i] < upper) {
                chmax(mx, a[i]);
            }
        }
        assert(wm.prev(l, r, upper) == mx);
    }
    
    // next
    REP(_iter, ITER) {
        i32 l = rd.uniform(0, n - 1);
        i32 r = rd.uniform(l + 1, n);
        i32 lower = rd.uniform(0, SIGMA + 10);
        
        i32 mn = INF;
        REP(i, l, r) {
            if (a[i] >= lower) {
                chmin(mn, a[i]);
            }
        }
        if (mn == INF) {
            assert(wm.next(l, r, lower) == -1);
        } else {
            assert(wm.next(l, r, lower) == mn);
        }
    }
    
    assert(wm.rank(0, n, 128) == 0);
    assert(wm.range_freq(0, n, 128) == n);
    assert(wm.prev(0, n, 128) == *max_element(ALL(a)));    
}

Vec<i32> gen_random(XorShift64 &rd) {
    Vec<i32> a(LEN);
    for (i32 &ele : a) {
        ele = rd.uniform(0, SIGMA - 1);
    }
    return a;
}

int main() {
    XorShift64 rd(138013123124ull);
    
    REP(_, 10) {
        test(gen_random(rd), rd);
    }
    
    cout << "Hello World\n";
}