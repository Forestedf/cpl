---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
  - icon: ':question:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':question:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"data_structure/test/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n\
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
    \  }\n} set_up_io;\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line 5 \"number_theory/mod_int.hpp\"\
    \n#include <type_traits>\n\n#line 2 \"number_theory/utils.hpp\"\n\nconstexpr bool\
    \ is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return false;\n\
    \    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\nconstexpr\
    \ unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned ret =\
    \ 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n            ret =\
    \ (unsigned) ((unsigned long long) ret * self % mod);\n        }\n        self\
    \ = (unsigned) ((unsigned long long) self * self % mod);\n        y /= 2;\n  \
    \  }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned primitive_root()\
    \ {\n    static_assert(is_prime(mod), \"`mod` must be a prime number.\");\n  \
    \  if (mod == 2) {\n        return 1;\n    }\n\n    unsigned primes[32] = {};\n\
    \    int it = 0;\n    {\n        unsigned m = mod - 1;\n        for (unsigned\
    \ i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n                primes[it++]\
    \ = i;\n                while (m % i == 0) {\n                    m /= i;\n  \
    \              }\n            }\n        }\n        if (m != 1) {\n          \
    \  primes[it++] = m;\n        }\n    }\n    for (unsigned i = 2; i < mod; ++i)\
    \ {\n        bool ok = true;\n        for (int j = 0; j < it; ++j) {\n       \
    \     if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n                ok =\
    \ false;\n                break;\n            }\n        }\n        if (ok)\n\
    \            return i;\n    }\n    return 0;\n}\n\n// y >= 1\ntemplate <typename\
    \ T>\nconstexpr T safe_mod(T x, T y) {\n    x %= y;\n    if (x < 0) {\n      \
    \  x += y;\n    }\n    return x;\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T floor_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return x / y;\n    } else {\n        return\
    \ -((-x + y - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T ceil_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return (x + y - 1) / y;\n    } else {\n   \
    \     return -(-x / y);\n    }\n}\n#line 8 \"number_theory/mod_int.hpp\"\n\ntemplate\
    \ <unsigned mod>\nclass ModInt {\n    static_assert(mod != 0, \"`mod` must not\
    \ be equal to 0.\");\n    static_assert(\n        mod < (1u << 31),\n        \"\
    `mod` must be less than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\n\
    public:\n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned) ((long long) x % (long\
    \ long) mod + (x < 0 ? mod : 0))) {}\n    template <typename T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned) (x % mod)) {}\n\n \
    \   static constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n    \
    \    ret.val = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val()\
    \ const {\n        return val;\n    }\n\n    constexpr ModInt operator+() const\
    \ {\n        return *this;\n    }\n    constexpr ModInt operator-() const {\n\
    \        return ModInt<mod>(0u) - *this;\n    }\n\n    constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n        val += rhs.val;\n        if (val >= mod)\n         \
    \   val -= mod;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n        if (val < rhs.val)\n            val += mod;\n      \
    \  val -= rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n        val = (unsigned long long)val * rhs.val % mod;\n   \
    \     return *this;\n    }\n    constexpr ModInt &operator/=(const ModInt &rhs)\
    \ {\n        val = (unsigned long long)val * rhs.inv().val % mod;\n        return\
    \ *this;\n    }\n\n    friend constexpr ModInt operator+(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) += rhs;\n    }\n    friend constexpr\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ -= rhs;\n    }\n    friend constexpr ModInt operator*(const ModInt &lhs, const\
    \ ModInt &rhs) {\n        return ModInt<mod>(lhs) *= rhs;\n    }\n    friend constexpr\
    \ ModInt operator/(const ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs)\
    \ /= rhs;\n    }\n\n    constexpr ModInt pow(unsigned long long x) const {\n \
    \       ModInt<mod> ret = ModInt<mod>::raw(1);\n        ModInt<mod> self = *this;\n\
    \        while (x != 0) {\n            if (x & 1)\n                ret *= self;\n\
    \            self *= self;\n            x >>= 1;\n        }\n        return ret;\n\
    \    }\n    constexpr ModInt inv() const {\n        static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n        assert(val != 0);\n        return\
    \ this->pow(mod - 2);\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, ModInt<mod> &x) {\n        is >> x.val;\n        x.val %= mod;\n      \
    \  return is;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const ModInt<mod> &x) {\n        os << x.val;\n        return os;\n    }\n\n\
    \    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {\n        return\
    \ lhs.val == rhs.val;\n    }\n    \n    friend bool operator!=(const ModInt &lhs,\
    \ const ModInt &rhs) {\n        return lhs.val != rhs.val;\n    }\n};\n\n[[maybe_unused]]\
    \ constexpr unsigned mod998244353 = 998244353;\n[[maybe_unused]] constexpr unsigned\
    \ mod1000000007 = 1000000007;\n\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n#line 6 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate <typename MonoidFunc>\n\
    class LazySegmentTree {\npublic:\n    using Value = typename MonoidFunc::Value;\n\
    \    using Func = typename MonoidFunc::Func;\n\nprivate:\n    int old_length;\n\
    \    int lg;\n    int length;\n    std::vector<Value> values;\n    std::vector<Func>\
    \ funcs;\n\n    static int lg2(int n) {\n        int x = 1;\n        int l = 0;\n\
    \        while (x < n) {\n            x <<= 1;\n            ++l;\n        }\n\
    \        return l;\n    }\n\n    void _apply(int idx, const Func &func) {\n  \
    \      values[idx] = MonoidFunc::apply(func, values[idx]);\n        funcs[idx]\
    \ = MonoidFunc::composite(func, funcs[idx]);\n    }\n\n    void push(int idx)\
    \ {\n        _apply(idx << 1, funcs[idx]);\n        _apply(idx << 1 | 1, funcs[idx]);\n\
    \        funcs[idx] = MonoidFunc::func_id();\n    }\n\n    void recalc_values(int\
    \ idx) {\n        values[idx] = MonoidFunc::op(values[idx << 1], values[idx <<\
    \ 1 | 1]);\n    }\n\npublic:\n    LazySegmentTree(int n) :\n        old_length(n),\n\
    \        lg(lg2(n)),\n        length(1 << lg),\n        values(length << 1, MonoidFunc::id()),\n\
    \        funcs(length << 1, MonoidFunc::func_id()) {\n        assert(n >= 0);\
    \    \n    }\n\n    LazySegmentTree(const std::vector<Value> &v) :\n        old_length((int)\
    \ v.size()),\n        lg(lg2(old_length)),\n        length(1 << lg),\n       \
    \ values(length << 1, MonoidFunc::id()),\n        funcs(length << 1, MonoidFunc::func_id())\
    \ {\n        for (int i = 0; i < old_length; ++i) {\n            values[i + length]\
    \ = v[i];\n        }\n        for (int i = length - 1; i > 0; --i) {\n       \
    \     recalc_values(i);\n        }\n    }\n\n    template <typename F>\n    LazySegmentTree(int\
    \ n, const F &f) :\n        old_length(n),\n        lg(lg2(n)),\n        length(1\
    \ << lg),\n        values(length << 1, MonoidFunc::id()),\n        funcs(length\
    \ << 1, MonoidFunc::func_id()) {\n        for (int i = 0; i < old_length; ++i)\
    \ {\n            values[i + length] = f(i);\n        }\n        for (int i = length\
    \ - 1; i > 0; --i) {\n            recalc_values(i);\n        }\n    }\n\n    void\
    \ update(int idx, Value val) {\n        assert(idx >= 0 && idx < old_length);\n\
    \        idx += length;\n        for (int i = lg; i > 0; --i) {\n            push(idx\
    \ >> i);\n        }\n        values[idx] = std::move(val);\n        while (idx\
    \ >>= 1) {\n            recalc_values(idx);\n        }\n    }\n\n    void apply(int\
    \ l, int r, const Func &func) {\n        assert(l >= 0 && l <= r && r <= old_length);\n\
    \        if (l == r) {\n            return;\n        }\n        l += length;\n\
    \        r += length;\n        int _l = l;\n        int _r = r;\n        for (int\
    \ i = lg; i > 0; --i) {\n            push(_l >> i);\n            push((_r - 1)\
    \ >> i);\n        }\n        while (l < r) {\n            if (l & 1) {\n     \
    \           _apply(l++, func);\n            }\n            if (r & 1) {\n    \
    \            _apply(--r, func);\n            }\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        for (int i = 1; i <= lg; ++i) {\n         \
    \   if ((_l >> i << i) != _l) {\n                recalc_values(_l >> i);\n   \
    \         }\n            if ((_r >> i << i) != _r) {\n                recalc_values((_r\
    \ - 1) >> i);\n            }\n        }\n    }\n\n    Value prod(int l, int r)\
    \ {\n        assert(l >= 0 && l <= r && r <= old_length);\n        if (l == r)\
    \ {\n            return MonoidFunc::id();\n        }\n        l += length;\n \
    \       r += length;\n        for (int i = lg; i > 0; --i) {\n            push(l\
    \ >> i);\n            push((r - 1) >> i);\n        }\n        Value lp = MonoidFunc::id();\n\
    \        Value rp = MonoidFunc::id();\n        while (l < r) {\n            if\
    \ (l & 1) {\n                lp = MonoidFunc::op(lp, values[l++]);\n         \
    \   }\n            if (r & 1) {\n                rp = MonoidFunc::op(values[--r],\
    \ rp);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return MonoidFunc::op(lp, rp);\n    }\n    \n    Value all_prod() const\
    \ {\n        return values[1];\n    }\n};\n\n#line 8 \"data_structure/test/range_affine_range_sum.test.cpp\"\
    \n\nusing Mint = ModInt<mod998244353>;\n\nstruct Node {\n    i32 len;\n    Mint\
    \ sum;\n};\n\nstruct Fn {\n    Mint a, b;\n};\n\nstruct Ops {\n    using Value\
    \ = Node;\n    using Func = Fn;\n    static Value id() {\n        return Node{0,\
    \ Mint()};\n    }\n    static Value op(const Value &x, const Value &y) {\n   \
    \     return Node{x.len + y.len, x.sum + y.sum};\n    }\n    static Func func_id()\
    \ {\n        return Fn{Mint(1), Mint()};\n    }\n    static Func composite(const\
    \ Func &f, const Func &g) {\n        return Fn{f.a * g.a, f.a * g.b + f.b};\n\
    \    }\n    static Value apply(const Func &f, const Value &x) {\n        return\
    \ Node{x.len, x.sum * f.a + Mint(x.len) * f.b};\n    }\n};\n\nint main() {\n \
    \   i32 n, q;\n    cin >> n >> q;\n    Vec<Node> a(n);\n    REP(i, n) {\n    \
    \    a[i].len = 1;\n        cin >> a[i].sum;\n    }\n    LazySegmentTree<Ops>\
    \ seg(a);\n    REP(qi, q) {\n        i32 type;\n        cin >> type;\n       \
    \ if (type == 0) {\n            i32 l, r;\n            Fn f;\n            cin\
    \ >> l >> r >> f.a >> f.b;\n            seg.apply(l, r, f);\n        } else {\n\
    \            i32 l, r;\n            cin >> l >> r;\n            cout << seg.prod(l,\
    \ r).sum << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../data_structure/lazy_segment_tree.hpp\"\n\nusing Mint = ModInt<mod998244353>;\n\
    \nstruct Node {\n    i32 len;\n    Mint sum;\n};\n\nstruct Fn {\n    Mint a, b;\n\
    };\n\nstruct Ops {\n    using Value = Node;\n    using Func = Fn;\n    static\
    \ Value id() {\n        return Node{0, Mint()};\n    }\n    static Value op(const\
    \ Value &x, const Value &y) {\n        return Node{x.len + y.len, x.sum + y.sum};\n\
    \    }\n    static Func func_id() {\n        return Fn{Mint(1), Mint()};\n   \
    \ }\n    static Func composite(const Func &f, const Func &g) {\n        return\
    \ Fn{f.a * g.a, f.a * g.b + f.b};\n    }\n    static Value apply(const Func &f,\
    \ const Value &x) {\n        return Node{x.len, x.sum * f.a + Mint(x.len) * f.b};\n\
    \    }\n};\n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<Node> a(n);\n\
    \    REP(i, n) {\n        a[i].len = 1;\n        cin >> a[i].sum;\n    }\n   \
    \ LazySegmentTree<Ops> seg(a);\n    REP(qi, q) {\n        i32 type;\n        cin\
    \ >> type;\n        if (type == 0) {\n            i32 l, r;\n            Fn f;\n\
    \            cin >> l >> r >> f.a >> f.b;\n            seg.apply(l, r, f);\n \
    \       } else {\n            i32 l, r;\n            cin >> l >> r;\n        \
    \    cout << seg.prod(l, r).sum << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: data_structure/test/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 19:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/range_affine_range_sum.test.cpp
- /verify/data_structure/test/range_affine_range_sum.test.cpp.html
title: data_structure/test/range_affine_range_sum.test.cpp
---
