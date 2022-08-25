---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/static_range_frequency.test.cpp
    title: data_structure/test/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_kth_smallest.test.cpp
    title: test/library_checker/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_frequency.test.cpp
    title: test/library_checker/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/other/wavelet_matrix.test.cpp
    title: test/other/wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/wavelet_matrix.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n\n#line 2 \"data_structure/bit_vector.hpp\"\
    \n\n#include <vector>\n\n#line 2 \"template/bitop.hpp\"\n\ntemplate <typename\
    \ T, typename U>\nbool ith_bit(T n, U i) {\n    return (n & ((T) 1 << i)) != 0;\n\
    }\n\nint popcount(int x) {\n    return __builtin_popcount(x);\n}\nunsigned popcount(unsigned\
    \ x) {\n    return __builtin_popcount(x);\n}\nlong long popcount(long long x)\
    \ {\n    return __builtin_popcountll(x);\n}\nunsigned long long popcount(unsigned\
    \ long long x) {\n    return __builtin_popcountll(x);\n}\n\n// x must not be 0\n\
    int clz(int x) {\n    return __builtin_clz(x);\n}\nunsigned clz(unsigned x) {\n\
    \    return __builtin_clz(x);\n}\nlong long clz(long long x) {\n    return __builtin_clzll(x);\n\
    }\nunsigned long long clz(unsigned long long x) {\n    return __builtin_clzll(x);\n\
    }\n\n// x must not be 0\nint ctz(int x) {\n    return __builtin_ctz(x);\n}\nunsigned\
    \ ctz(unsigned int x) {\n    return __builtin_ctz(x);\n}\nlong long ctz(long long\
    \ x) {\n    return __builtin_ctzll(x);\n}\nunsigned long long ctz(unsigned long\
    \ long x) {\n    return __builtin_ctzll(x);\n}\n\nint floor_log2(int x) {\n  \
    \  return 31 - clz(x);\n}\nunsigned floor_log2(unsigned x) {\n    return 31 -\
    \ clz(x);\n}\nlong long floor_log2(long long x) {\n    return 63 - clz(x);\n}\n\
    unsigned long long floor_log2(unsigned long long x) {\n    return 63 - clz(x);\n\
    }\n\ntemplate <typename T>\nT mask_n(T x, T n) {\n    T mask = ((T) 1 << n) -\
    \ 1;\n    return x & mask;\n}\n#line 6 \"data_structure/bit_vector.hpp\"\n\nclass\
    \ BitVector {\n    static constexpr int WIDTH = 64;\n    \n    int n;\n    std::vector<unsigned\
    \ long long> bits;\n    std::vector<unsigned long long> sum;\n    int zeros;\n\
    \    \npublic:\n    BitVector(int _n) : n(_n), bits(n / WIDTH + 1, 0), sum(n /\
    \ WIDTH + 1, 0), zeros(0) {}\n    \n    void rev(int idx) {\n        bits[idx\
    \ / WIDTH] ^= 1ULL << (idx % WIDTH);\n    }\n    \n    bool operator[](int idx)\
    \ const {\n        return (bits[idx / WIDTH] & (1ULL << (idx % WIDTH))) != 0;\n\
    \    }\n    \n    void build() {\n        for (int i = 1; i < (int) sum.size();\
    \ ++i) {\n            sum[i] = sum[i - 1] + popcount(bits[i - 1]);\n        }\n\
    \        zeros = rank0(n);\n    }\n    \n    int rank0(int n) const {\n      \
    \  return n - rank1(n);\n    }\n    int rank1(int n) const {\n        return sum[n\
    \ / WIDTH] + popcount(mask_n(bits[n / WIDTH], (unsigned long long) (n % WIDTH)));\n\
    \    }\n    int all_zeros() const {\n        return zeros;\n    }\n};\n#line 8\
    \ \"data_structure/wavelet_matrix.hpp\"\n\ntemplate <typename T>\nclass WaveletMatrix\
    \ {\n    int n;\n    int ht;\n    std::vector<BitVector> vecs;\n    \npublic:\n\
    \    WaveletMatrix(std::vector<T> a) : n((int) a.size()), ht(0), vecs() {\n  \
    \      assert(n > 0);\n        for (T ele : a) {\n            assert(ele >= 0);\n\
    \        }\n        \n        T mx = std::max(T(1), *std::max_element(a.begin(),\
    \ a.end()));\n        ht = (int) floor_log2(mx) + 1;\n        vecs.reserve(ht);\n\
    \        \n        for (T d = ht; d-- > 0;) {\n            BitVector vec(n);\n\
    \            for (int i = 0; i < n; ++i) {\n                if (ith_bit(a[i],\
    \ d)) {\n                    vec.rev(i);\n                }\n            }\n \
    \           vec.build();\n            std::vector<T> nxt(n);\n            auto\
    \ it0 = nxt.begin();\n            auto it1 = nxt.begin() + vec.all_zeros();\n\
    \            for (int i = 0; i < n; ++i) {\n                if (vec[i]) {\n  \
    \                  *(it1++) = a[i];\n                } else {\n              \
    \      *(it0++) = a[i];\n                }\n            }\n            std::swap(nxt,\
    \ a);\n            vecs.emplace_back(std::move(vec));\n        }\n    }\n    \n\
    \    T access(int idx) const {\n        assert(0 <= idx && idx < n);\n       \
    \ T ret(0);\n        for (int i = 0; i < ht; ++i) {\n            ret <<= 1;\n\
    \            if (vecs[i][idx]) {\n                ret ^= 1;\n                idx\
    \ = vecs[i].all_zeros() + vecs[i].rank1(idx);\n            } else {\n        \
    \        idx = vecs[i].rank0(idx);\n            }\n        }\n        return ret;\n\
    \    }\n    \n    T kth_smallest(int l, int r, int k) const {\n        assert(0\
    \ <= l && l < r && r <= n && 0 <= k && k < r - l);\n        T ret = 0;\n     \
    \   for (int i = 0; i < ht; ++i) {\n            int l0 = vecs[i].rank0(l);\n \
    \           int r0 = vecs[i].rank0(r);\n            ret <<= 1;\n            if\
    \ (k < r0 - l0) {\n                l = l0;\n                r = r0;\n        \
    \    } else {\n                ret ^= T(1);\n                l += vecs[i].all_zeros()\
    \ - l0;\n                r += vecs[i].all_zeros() - r0;\n                k -=\
    \ r0 - l0;\n            }\n        }\n        return ret;\n    }\n    T kth_largest(int\
    \ l, int r, int k) const {\n        return kth_smallest(l, r, r - l - k - 1);\n\
    \    }\n    \n    // count i s.t. i \\in [l, r) and a[i] = v \n    int rank(int\
    \ l, int r, T v) const {\n        assert(0 <= l && l <= r && r <= n);\n      \
    \  if (v != 0 && floor_log2(v) >= ht) {\n            return 0;\n        }\n  \
    \      for (int i = 0; i < ht; ++i) {\n            i32 l0 = vecs[i].rank0(l);\n\
    \            i32 r0 = vecs[i].rank0(r);\n            if (ith_bit(v, ht - 1 - i))\
    \ {\n                l += vecs[i].all_zeros() - l0;\n                r += vecs[i].all_zeros()\
    \ - r0;\n            } else {\n                l = l0;\n                r = r0;\n\
    \            }\n        }\n        return r - l;\n    }\n    \n    // count i\
    \ s.t. i \\in [l, r) and a[i] < upper\n    int range_freq(int l, int r, T upper)\
    \ const {\n        assert(0 <= l && l < r && r <= n);\n        if (upper != 0\
    \ && floor_log2(upper) >= ht) {\n            return r - l;\n        }\n      \
    \  int cnt = 0;\n        for (int i = 0; i < ht; ++i) {\n            i32 l0 =\
    \ vecs[i].rank0(l);\n            i32 r0 = vecs[i].rank0(r);\n            if (ith_bit(upper,\
    \ ht - 1 - i)) {\n                cnt += r0 - l0;\n                l += vecs[i].all_zeros()\
    \ - l0;\n                r += vecs[i].all_zeros() - r0;\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return cnt;\n    }\n    // count i s.t. i \\in [l, r) and a[i] \\in [lower,\
    \ upper)\n    int range_freq(int l, int r, T lower, T upper) const {\n       \
    \ if (lower >= upper) {\n            return 0;\n        } else {\n           \
    \ return range_freq(l, r, upper) - range_freq(l, r, lower);\n        }\n    }\n\
    \    \n    // max v s.t. v \\in a[l, r) and v < upper\n    int prev(int l, int\
    \ r, T upper) const {\n        int freq = range_freq(l, r, upper);\n        if\
    \ (freq == 0) {\n            return T(-1);\n        } else {\n            return\
    \ kth_smallest(l, r, freq - 1);\n        }\n    }\n    \n    // min v s.t. v \\\
    in a[l, r) and v \\geq lower\n    int next(int l, int r, T lower) const {\n  \
    \      int freq = range_freq(l, r, lower);\n        if (freq == r - l) {\n   \
    \         return T(-1);\n        } else {\n            return kth_smallest(l,\
    \ r, freq);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    \n#include \"bit_vector.hpp\"\n\ntemplate <typename T>\nclass WaveletMatrix {\n\
    \    int n;\n    int ht;\n    std::vector<BitVector> vecs;\n    \npublic:\n  \
    \  WaveletMatrix(std::vector<T> a) : n((int) a.size()), ht(0), vecs() {\n    \
    \    assert(n > 0);\n        for (T ele : a) {\n            assert(ele >= 0);\n\
    \        }\n        \n        T mx = std::max(T(1), *std::max_element(a.begin(),\
    \ a.end()));\n        ht = (int) floor_log2(mx) + 1;\n        vecs.reserve(ht);\n\
    \        \n        for (T d = ht; d-- > 0;) {\n            BitVector vec(n);\n\
    \            for (int i = 0; i < n; ++i) {\n                if (ith_bit(a[i],\
    \ d)) {\n                    vec.rev(i);\n                }\n            }\n \
    \           vec.build();\n            std::vector<T> nxt(n);\n            auto\
    \ it0 = nxt.begin();\n            auto it1 = nxt.begin() + vec.all_zeros();\n\
    \            for (int i = 0; i < n; ++i) {\n                if (vec[i]) {\n  \
    \                  *(it1++) = a[i];\n                } else {\n              \
    \      *(it0++) = a[i];\n                }\n            }\n            std::swap(nxt,\
    \ a);\n            vecs.emplace_back(std::move(vec));\n        }\n    }\n    \n\
    \    T access(int idx) const {\n        assert(0 <= idx && idx < n);\n       \
    \ T ret(0);\n        for (int i = 0; i < ht; ++i) {\n            ret <<= 1;\n\
    \            if (vecs[i][idx]) {\n                ret ^= 1;\n                idx\
    \ = vecs[i].all_zeros() + vecs[i].rank1(idx);\n            } else {\n        \
    \        idx = vecs[i].rank0(idx);\n            }\n        }\n        return ret;\n\
    \    }\n    \n    T kth_smallest(int l, int r, int k) const {\n        assert(0\
    \ <= l && l < r && r <= n && 0 <= k && k < r - l);\n        T ret = 0;\n     \
    \   for (int i = 0; i < ht; ++i) {\n            int l0 = vecs[i].rank0(l);\n \
    \           int r0 = vecs[i].rank0(r);\n            ret <<= 1;\n            if\
    \ (k < r0 - l0) {\n                l = l0;\n                r = r0;\n        \
    \    } else {\n                ret ^= T(1);\n                l += vecs[i].all_zeros()\
    \ - l0;\n                r += vecs[i].all_zeros() - r0;\n                k -=\
    \ r0 - l0;\n            }\n        }\n        return ret;\n    }\n    T kth_largest(int\
    \ l, int r, int k) const {\n        return kth_smallest(l, r, r - l - k - 1);\n\
    \    }\n    \n    // count i s.t. i \\in [l, r) and a[i] = v \n    int rank(int\
    \ l, int r, T v) const {\n        assert(0 <= l && l <= r && r <= n);\n      \
    \  if (v != 0 && floor_log2(v) >= ht) {\n            return 0;\n        }\n  \
    \      for (int i = 0; i < ht; ++i) {\n            i32 l0 = vecs[i].rank0(l);\n\
    \            i32 r0 = vecs[i].rank0(r);\n            if (ith_bit(v, ht - 1 - i))\
    \ {\n                l += vecs[i].all_zeros() - l0;\n                r += vecs[i].all_zeros()\
    \ - r0;\n            } else {\n                l = l0;\n                r = r0;\n\
    \            }\n        }\n        return r - l;\n    }\n    \n    // count i\
    \ s.t. i \\in [l, r) and a[i] < upper\n    int range_freq(int l, int r, T upper)\
    \ const {\n        assert(0 <= l && l < r && r <= n);\n        if (upper != 0\
    \ && floor_log2(upper) >= ht) {\n            return r - l;\n        }\n      \
    \  int cnt = 0;\n        for (int i = 0; i < ht; ++i) {\n            i32 l0 =\
    \ vecs[i].rank0(l);\n            i32 r0 = vecs[i].rank0(r);\n            if (ith_bit(upper,\
    \ ht - 1 - i)) {\n                cnt += r0 - l0;\n                l += vecs[i].all_zeros()\
    \ - l0;\n                r += vecs[i].all_zeros() - r0;\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return cnt;\n    }\n    // count i s.t. i \\in [l, r) and a[i] \\in [lower,\
    \ upper)\n    int range_freq(int l, int r, T lower, T upper) const {\n       \
    \ if (lower >= upper) {\n            return 0;\n        } else {\n           \
    \ return range_freq(l, r, upper) - range_freq(l, r, lower);\n        }\n    }\n\
    \    \n    // max v s.t. v \\in a[l, r) and v < upper\n    int prev(int l, int\
    \ r, T upper) const {\n        int freq = range_freq(l, r, upper);\n        if\
    \ (freq == 0) {\n            return T(-1);\n        } else {\n            return\
    \ kth_smallest(l, r, freq - 1);\n        }\n    }\n    \n    // min v s.t. v \\\
    in a[l, r) and v \\geq lower\n    int next(int l, int r, T lower) const {\n  \
    \      int freq = range_freq(l, r, lower);\n        if (freq == r - l) {\n   \
    \         return T(-1);\n        } else {\n            return kth_smallest(l,\
    \ r, freq);\n        }\n    }\n};"
  dependsOn:
  - data_structure/bit_vector.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/range_kth_smallest.test.cpp
  - test/library_checker/static_range_frequency.test.cpp
  - test/other/wavelet_matrix.test.cpp
  - data_structure/test/range_kth_smallest.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
  - data_structure/test/static_range_frequency.test.cpp
documentation_of: data_structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/data_structure/wavelet_matrix.hpp
- /library/data_structure/wavelet_matrix.hpp.html
title: data_structure/wavelet_matrix.hpp
---