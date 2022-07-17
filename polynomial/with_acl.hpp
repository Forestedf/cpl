#pragma once

#include <atcoder/convolution>

template <int mod>
class ACLNTT {
public:
    using Mint = atcoder::static_modint<mod>;
    
    static void dft(std::vector<Mint> &a) {
        atcoder::internal::butterfly(a);
    }
    static void idft(std::vector<Mint> &a) {
        atcoder::internal::butterfly_inv(a);
        Mint inv = Mint::raw(a.size()).inv();
        for (Mint &ele : a) {
            ele *= inv;
        }
    }
    static std::vector<Mint> mul(std::vector<Mint> a, std::vector<Mint> b) {
        return atcoder::convolution(a, b);
    }
};