#pragma once

#include <algorithm>
#include <cassert>
#include <utility>

#include "bit_vector.hpp"

template <typename T>
class WaveletMatrix {
    int n;
    int ht;
    std::vector<BitVector> vecs;
    
public:
    WaveletMatrix(std::vector<T> a) : n((int) a.size()), ht(0), vecs() {
        assert(n > 0);
        
        T mx = *std::max_element(a.begin(), a.end());
        ht = (int) floor_log2(mx) + 1;
        vecs.reserve(ht);
        
        for (T d = ht; d-- > 0;) {
            BitVector vec(n);
            for (int i = 0; i < n; ++i) {
                if (a[i] & ((T) 1 << d)) {
                    vec.rev(i);
                }
            }
            vec.build();
            std::vector<T> nxt(n);
            auto it0 = nxt.begin();
            auto it1 = nxt.begin() + vec.all_zeros();
            for (int i = 0; i < n; ++i) {
                if (vec[i]) {
                    *(it1++) = a[i];
                } else {
                    *(it0++) = a[i];
                }
            }
            std::swap(nxt, a);
            vecs.emplace_back(std::move(vec));
        }
    }
    
    T access(int idx) const {
        assert(0 <= idx && idx < n);
        T ret(0);
        for (int i = 0; i < ht; ++i) {
            ret <<= 1;
            if (vecs[i][idx]) {
                ret ^= 1;
                idx = vecs[i].all_zeros() + vecs[i].rank1(idx);
            } else {
                idx = vecs[i].rank0(idx);
            }
        }
        return ret;
    }
    
    T kth_smallest(int l, int r, int k) const {
        assert(0 <= l && l < r && r <= n && 0 <= k && k < r - l);
        T ret = 0;
        for (int i = 0; i < ht; ++i) {
            int l0 = vecs[i].rank0(l);
            int r0 = vecs[i].rank0(r);
            ret <<= 1;
            if (k < r0 - l0) {
                l = l0;
                r = r0;
            } else {
                ret ^= T(1);
                l += vecs[i].all_zeros() - l0;
                r += vecs[i].all_zeros() - r0;
                k -= r0 - l0;
            }
        }
        return ret;
    }
};