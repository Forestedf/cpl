---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':question:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: other/coordinate_compression.hpp
    title: other/coordinate_compression.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/library_checker/range_kth_smallest.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#define FAST_IO\n\
    \n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n\
    #include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n#define\
    \ REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n) for (i32\
    \ i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3,\
    \ REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)\n\
    #define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\nusing i32\
    \ = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\nusing\
    \ f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing Vec\
    \ = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n    if\
    \ (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\n\nistream &operator>>(istream\
    \ &is, i128 &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\n\
    istream &operator>>(istream &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x =\
    \ v;\n    return is;\n}\nostream &operator<<(ostream &os, u128 x) {\n    os <<\
    \ (u64) x;\n    return os;\n}\n\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n\
    [[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n\
    \    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n     \
    \   cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n  \
    \  }\n} set_up_io;\n#line 2 \"other/coordinate_compression.hpp\"\n\n#line 5 \"\
    other/coordinate_compression.hpp\"\n\ntemplate <typename T>\nclass CoordinateCompression\
    \ {\n    std::vector<T> data;\n\n    int size_sum() {\n        return 0;\n   \
    \ }\n\n    template <typename... Tail>\n    int size_sum(const std::vector<T>\
    \ &head, const Tail &...tail) {\n        return (int) head.size() + size_sum(tail...);\n\
    \    }\n\n    void push() {}\n\n    template <typename... Tail>\n    void push(const\
    \ std::vector<T> &head, const Tail &...tail) {\n        for (const T &ele : head)\
    \ {\n            data.emplace_back(ele);\n        }\n        push(tail...);\n\
    \    }\n\n    void compress() {}\n\n    template <typename... Tail>\n    void\
    \ compress(std::vector<T> &head, Tail &...tail) {\n        for (T &ele : head)\
    \ {\n            ele = (T) (std::lower_bound(data.begin(), data.end(), ele) -\
    \ data.begin());\n        }\n        compress(tail...);\n    }\n\npublic:\n  \
    \  template <typename... V>\n    CoordinateCompression(V &...v) {\n        data.reserve(size_sum(v...));\n\
    \        push(v...);\n        std::sort(data.begin(), data.end());\n        data.erase(std::unique(data.begin(),\
    \ data.end()), data.end());\n        compress(v...);\n    }\n\n    const T &operator[](const\
    \ T &ele) const {\n        return data[ele];\n    }\n\n    int size() const {\n\
    \        return data.size();\n    }\n    \n    bool contains(const T &ele) const\
    \ {\n        auto it = std::lower_bound(data.begin(), data.end(), ele);\n    \
    \    return it != data.end() && *it == ele;\n    }\n    \n    T cc(const T &ele)\
    \ const {\n        return (T) (std::lower_bound(data.begin(), data.end(), ele)\
    \ - data.begin());\n    }\n};\n#line 2 \"data_structure/wavelet_matrix.hpp\"\n\
    \n#line 6 \"data_structure/wavelet_matrix.hpp\"\n\n#line 2 \"data_structure/bit_vector.hpp\"\
    \n\n#line 4 \"data_structure/bit_vector.hpp\"\n\n#line 2 \"template/bitop.hpp\"\
    \n\ntemplate <typename T, typename U>\nbool ith_bit(T n, U i) {\n    return (n\
    \ & ((T) 1 << i)) != 0;\n}\n\nint popcount(int x) {\n    return __builtin_popcount(x);\n\
    }\nunsigned popcount(unsigned x) {\n    return __builtin_popcount(x);\n}\nlong\
    \ long popcount(long long x) {\n    return __builtin_popcountll(x);\n}\nunsigned\
    \ long long popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n\
    }\n\n// x must not be 0\nint clz(int x) {\n    return __builtin_clz(x);\n}\nunsigned\
    \ clz(unsigned x) {\n    return __builtin_clz(x);\n}\nlong long clz(long long\
    \ x) {\n    return __builtin_clzll(x);\n}\nunsigned long long clz(unsigned long\
    \ long x) {\n    return __builtin_clzll(x);\n}\n\n// x must not be 0\nint ctz(int\
    \ x) {\n    return __builtin_ctz(x);\n}\nunsigned ctz(unsigned int x) {\n    return\
    \ __builtin_ctz(x);\n}\nlong long ctz(long long x) {\n    return __builtin_ctzll(x);\n\
    }\nunsigned long long ctz(unsigned long long x) {\n    return __builtin_ctzll(x);\n\
    }\n\nint floor_log2(int x) {\n    return 31 - clz(x);\n}\nunsigned floor_log2(unsigned\
    \ x) {\n    return 31 - clz(x);\n}\nlong long floor_log2(long long x) {\n    return\
    \ 63 - clz(x);\n}\nunsigned long long floor_log2(unsigned long long x) {\n   \
    \ return 63 - clz(x);\n}\n\ntemplate <typename T>\nT mask_n(T x, T n) {\n    T\
    \ mask = ((T) 1 << n) - 1;\n    return x & mask;\n}\n#line 6 \"data_structure/bit_vector.hpp\"\
    \n\nclass BitVector {\n    static constexpr int WIDTH = 64;\n    \n    int n;\n\
    \    std::vector<unsigned long long> bits;\n    std::vector<unsigned long long>\
    \ sum;\n    int zeros;\n    \npublic:\n    BitVector(int _n) : n(_n), bits(n /\
    \ WIDTH + 1, 0), sum(n / WIDTH + 1, 0), zeros(0) {}\n    \n    void rev(int idx)\
    \ {\n        bits[idx / WIDTH] ^= 1ULL << (idx % WIDTH);\n    }\n    \n    bool\
    \ operator[](int idx) const {\n        return (bits[idx / WIDTH] & (1ULL << (idx\
    \ % WIDTH))) != 0;\n    }\n    \n    void build() {\n        for (int i = 1; i\
    \ < (int) sum.size(); ++i) {\n            sum[i] = sum[i - 1] + popcount(bits[i\
    \ - 1]);\n        }\n        zeros = rank0(n);\n    }\n    \n    int rank0(int\
    \ n) const {\n        return n - rank1(n);\n    }\n    int rank1(int n) const\
    \ {\n        return sum[n / WIDTH] + popcount(mask_n(bits[n / WIDTH], (unsigned\
    \ long long) (n % WIDTH)));\n    }\n    int all_zeros() const {\n        return\
    \ zeros;\n    }\n};\n#line 8 \"data_structure/wavelet_matrix.hpp\"\n\ntemplate\
    \ <typename T>\nclass WaveletMatrix {\n    int n;\n    int ht;\n    std::vector<BitVector>\
    \ vecs;\n    \npublic:\n    WaveletMatrix(std::vector<T> a) : n((int) a.size()),\
    \ ht(0), vecs() {\n        assert(n > 0);\n        for (T ele : a) {\n       \
    \     assert(ele >= 0);\n        }\n        \n        T mx = *std::max_element(a.begin(),\
    \ a.end());\n        ht = (int) floor_log2(mx) + 1;\n        vecs.reserve(ht);\n\
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
    \  if (floor_log2(v) >= ht) {\n            return 0;\n        }\n        for (int\
    \ i = 0; i < ht; ++i) {\n            i32 l0 = vecs[i].rank0(l);\n            i32\
    \ r0 = vecs[i].rank0(r);\n            if (ith_bit(v, ht - 1 - i)) {\n        \
    \        l += vecs[i].all_zeros() - l0;\n                r += vecs[i].all_zeros()\
    \ - r0;\n            } else {\n                l = l0;\n                r = r0;\n\
    \            }\n        }\n        return r - l;\n    }\n    \n    // count i\
    \ s.t. i \\in [l, r) and a[i] < upper\n    int range_freq(int l, int r, T upper)\
    \ const {\n        assert(0 <= l && l < r && r <= n);\n        if (floor_log2(upper)\
    \ >= ht) {\n            return r - l;\n        }\n        int cnt = 0;\n     \
    \   for (int i = 0; i < ht; ++i) {\n            i32 l0 = vecs[i].rank0(l);\n \
    \           i32 r0 = vecs[i].rank0(r);\n            if (ith_bit(upper, ht - 1\
    \ - i)) {\n                cnt += r0 - l0;\n                l += vecs[i].all_zeros()\
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
    \ r, freq);\n        }\n    }\n};\n#line 8 \"test/library_checker/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<i32> a(n);\n    REP(i,\
    \ n) {\n        cin >> a[i];\n    }\n    CoordinateCompression<i32> cc(a);\n \
    \   WaveletMatrix<i32> wm(a);\n    REP(qi, q) {\n        i32 l, r, k;\n      \
    \  cin >> l >> r >> k;\n        i32 sm = wm.kth_smallest(l, r, k);\n        cout\
    \ << cc[sm] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../other/coordinate_compression.hpp\"\
    \n#include \"../../data_structure/wavelet_matrix.hpp\"\n\nint main() {\n    i32\
    \ n, q;\n    cin >> n >> q;\n    Vec<i32> a(n);\n    REP(i, n) {\n        cin\
    \ >> a[i];\n    }\n    CoordinateCompression<i32> cc(a);\n    WaveletMatrix<i32>\
    \ wm(a);\n    REP(qi, q) {\n        i32 l, r, k;\n        cin >> l >> r >> k;\n\
    \        i32 sm = wm.kth_smallest(l, r, k);\n        cout << cc[sm] << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - other/coordinate_compression.hpp
  - data_structure/wavelet_matrix.hpp
  - data_structure/bit_vector.hpp
  - template/bitop.hpp
  isVerificationFile: true
  path: test/library_checker/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2022-07-22 13:30:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/range_kth_smallest.test.cpp
- /verify/test/library_checker/range_kth_smallest.test.cpp.html
title: test/library_checker/range_kth_smallest.test.cpp
---
