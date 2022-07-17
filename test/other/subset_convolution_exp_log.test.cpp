#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../convolution/subset_convolution_exp.hpp"
#include "../../convolution/subset_convolution_log.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../other/xorshift.hpp"

constexpr u32 MOD = 998244353;
using Mint = ModInt<MOD>;

void test1(const Vec<Mint> &a) {
    Vec<Mint> exp_a = subset_convolution_exp(a);
    Vec<Mint> log_exp_a = subset_convolution_log(exp_a);
    assert(a == log_exp_a);
}

void test2(const Vec<Mint> &a) {
    Vec<Mint> log_a = subset_convolution_log(a);
    Vec<Mint> exp_log_a = subset_convolution_exp(log_a);
    assert(a == exp_log_a);
}

int main() {
    constexpr u64 SEED = 1309420975327ull;
    XorShift64 rd(SEED);
    
    REP(iter, 5) {
        i32 n = rd.uniform(1, 16);
        Vec<Mint> a(1 << n);
        REP(i, 1, 1 << n) {
            a[i] = rd.uniform(0u, MOD - 1u);
        }
        test1(a);
    }
    REP(iter, 5) {
        i32 n = rd.uniform(1, 16);
        Vec<Mint> a(1 << n);
        a[0] = Mint(1);
        REP(i, 1, 1 << n) {
            a[i] = rd.uniform(0u, MOD - 1u);
        }
        test2(a);
    }
    
    cout << "Hello World\n";
}