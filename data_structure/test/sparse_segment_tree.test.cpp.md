---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_segment_tree.hpp
    title: data_structure/sparse_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"data_structure/test/sparse_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#define\
    \ FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include\
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
    \  }\n} set_up_io;\n#line 2 \"data_structure/sparse_segment_tree.hpp\"\n\n#line\
    \ 4 \"data_structure/sparse_segment_tree.hpp\"\n\ntemplate <typename Monoid>\n\
    class SparseSegmentTree {\npublic:\n    using Value = typename Monoid::Value;\n\
    \    using Index = long long;\n    \nprivate:\n    struct Node {\n        Node\
    \ *lft;\n        Node *rgt;\n        Value prod;\n        \n        Node(Value\
    \ v) : lft(nullptr), rgt(nullptr), prod(v) {}\n        \n#ifdef LOCAL\n      \
    \  ~Node() {\n            if (lft) {\n                delete lft;\n          \
    \  }\n            if (rgt) {\n                delete rgt;\n            }\n   \
    \     }\n#endif\n        \n        void update_prod() {\n            if (!lft\
    \ && !rgt) {\n                prod = Monoid::id();\n            } else if (!lft)\
    \ {\n                prod = rgt->prod;\n            } else if (!rgt) {\n     \
    \           prod = lft->prod;\n            } else {\n                prod = Monoid::op(lft->prod,\
    \ rgt->prod);\n            }\n        }\n    };\n    \n    static Node *update(Node\
    \ *cur, Index curl, Index curr, Index upd, Value v) {\n        if (!cur) {\n \
    \           cur = new Node(Monoid::id());\n        }\n        if (curr - curl\
    \ == 1) {\n            cur->prod = v;\n        } else {\n            Index curm\
    \ = (curl + curr) / 2;\n            if (upd < curm) {\n                cur->lft\
    \ = update(cur->lft, curl, curm, upd, v);\n            } else {\n            \
    \    cur->rgt = update(cur->rgt, curm, curr, upd, v);\n            }\n       \
    \     cur->update_prod();\n        }\n        return cur;\n    }\n    \n    static\
    \ Value prod(Node *cur, Index curl, Index curr, Index qryl, Index qryr) {\n  \
    \      if (!cur || curr <= qryl || qryr <= curl) {\n            return Monoid::id();\n\
    \        }\n        if (qryl <= curl && curr <= qryr) {\n            return cur->prod;\n\
    \        }\n        Index curm = (curl + curr) / 2;\n        Value pl = prod(cur->lft,\
    \ curl, curm, qryl, qryr);\n        Value pr = prod(cur->rgt, curm, curr, qryl,\
    \ qryr);\n        return Monoid::op(pl, pr);\n    }\n    \n    Index lft;\n  \
    \  Index rgt;\n    Node *root;\n    \npublic:\n    SparseSegmentTree() : lft(0),\
    \ rgt(1), root(nullptr) {}\n    SparseSegmentTree(Index n) : lft(0), rgt(n), root(nullptr)\
    \ {\n        assert(n > 0);\n    }\n    SparseSegmentTree(Index l, Index r) :\
    \ lft(l), rgt(r), root(nullptr) {\n        assert(l < r);\n    }\n    \n    void\
    \ update(Index idx, Value v) {\n        root = update(root, lft, rgt, idx, v);\n\
    \    }\n    \n    Value prod(Index l, Index r) const {\n        return prod(root,\
    \ lft, rgt, l, r);\n    }\n};\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line\
    \ 5 \"number_theory/mod_int.hpp\"\n#include <type_traits>\n\n#line 2 \"number_theory/utils.hpp\"\
    \n\nconstexpr bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n     \
    \   return false;\n    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n      \
    \  if (n % i == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\nconstexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod)\
    \ {\n    unsigned ret = 1, self = x;\n    while (y != 0) {\n        if (y & 1)\
    \ {\n            ret = (unsigned) ((unsigned long long) ret * self % mod);\n \
    \       }\n        self = (unsigned) ((unsigned long long) self * self % mod);\n\
    \        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr\
    \ unsigned primitive_root() {\n    static_assert(is_prime(mod), \"`mod` must be\
    \ a prime number.\");\n    if (mod == 2) {\n        return 1;\n    }\n\n    unsigned\
    \ primes[32] = {};\n    int it = 0;\n    {\n        unsigned m = mod - 1;\n  \
    \      for (unsigned i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n\
    \                primes[it++] = i;\n                while (m % i == 0) {\n   \
    \                 m /= i;\n                }\n            }\n        }\n     \
    \   if (m != 1) {\n            primes[it++] = m;\n        }\n    }\n    for (unsigned\
    \ i = 2; i < mod; ++i) {\n        bool ok = true;\n        for (int j = 0; j <\
    \ it; ++j) {\n            if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok)\n            return i;\n    }\n    return 0;\n}\n\n// y >= 1\n\
    template <typename T>\nconstexpr T safe_mod(T x, T y) {\n    x %= y;\n    if (x\
    \ < 0) {\n        x += y;\n    }\n    return x;\n}\n\n// y != 0\ntemplate <typename\
    \ T>\nconstexpr T floor_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n\
    \        y *= -1;\n    }\n    if (x >= 0) {\n        return x / y;\n    } else\
    \ {\n        return -((-x + y - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename\
    \ T>\nconstexpr T ceil_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n \
    \       y *= -1;\n    }\n    if (x >= 0) {\n        return (x + y - 1) / y;\n\
    \    } else {\n        return -(-x / y);\n    }\n}\n#line 8 \"number_theory/mod_int.hpp\"\
    \n\ntemplate <unsigned mod>\nclass ModInt {\n    static_assert(mod != 0, \"`mod`\
    \ must not be equal to 0.\");\n    static_assert(\n        mod < (1u << 31),\n\
    \        \"`mod` must be less than (1u << 31) = 2147483648.\");\n\n    unsigned\
    \ val;\n\npublic:\n    static constexpr unsigned get_mod() {\n        return mod;\n\
    \    }\n    \n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ &is, ModInt<mod> &x) {\n        long long val;\n        is >> val;\n       \
    \ x.val = val % mod + (val < 0 ? mod : 0);\n        return is;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {\n       \
    \ os << x.val;\n        return os;\n    }\n\n    friend bool operator==(const\
    \ ModInt &lhs, const ModInt &rhs) {\n        return lhs.val == rhs.val;\n    }\n\
    \    \n    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) {\n  \
    \      return lhs.val != rhs.val;\n    }\n};\n\n[[maybe_unused]] constexpr unsigned\
    \ mod998244353 = 998244353;\n[[maybe_unused]] constexpr unsigned mod1000000007\
    \ = 1000000007;\n\n#line 8 \"data_structure/test/sparse_segment_tree.test.cpp\"\
    \n\nusing Mint = ModInt<mod998244353>;\n\nstruct Linear {\n    Mint a, b;\n  \
    \  Linear() : a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a),\
    \ b(_b) {}\n    Mint operator()(Mint x) {\n        return a * x + b;\n    }\n\
    };\n\n// f \\circ g\nLinear composite(const Linear &f, const Linear &g) {\n  \
    \  return Linear(f.a * g.a, f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value\
    \ = Linear;\n    static Value id() {\n        return Linear();\n    }\n    static\
    \ Value op(const Value &x, const Value &y) {\n        return composite(y, x);\n\
    \    }\n};\n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<Linear>\
    \ fs(n);\n    for (auto &[a, b] : fs) {\n        cin >> a >> b;\n    }\n    SparseSegmentTree<Ops>\
    \ seg(n);\n    REP(i, n) {\n        seg.update(i, fs[i]);\n    }\n    REP(qi,\
    \ q) {\n        i32 type;\n        cin >> type;\n        if (type == 0) {\n  \
    \          i32 p;\n            Linear f;\n            cin >> p >> f.a >> f.b;\n\
    \            seg.update(p, f);\n        } else {\n            i32 l, r;\n    \
    \        Mint x;\n            cin >> l >> r >> x;\n            cout << seg.prod(l,\
    \ r)(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/sparse_segment_tree.hpp\"\
    \n#include \"../../number_theory/mod_int.hpp\"\n\nusing Mint = ModInt<mod998244353>;\n\
    \nstruct Linear {\n    Mint a, b;\n    Linear() : a(Mint(1)), b(Mint(0)) {}\n\
    \    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n    Mint operator()(Mint x) {\n\
    \        return a * x + b;\n    }\n};\n\n// f \\circ g\nLinear composite(const\
    \ Linear &f, const Linear &g) {\n    return Linear(f.a * g.a, f.a * g.b + f.b);\n\
    }\n\nstruct Ops {\n    using Value = Linear;\n    static Value id() {\n      \
    \  return Linear();\n    }\n    static Value op(const Value &x, const Value &y)\
    \ {\n        return composite(y, x);\n    }\n};\n\nint main() {\n    i32 n, q;\n\
    \    cin >> n >> q;\n    Vec<Linear> fs(n);\n    for (auto &[a, b] : fs) {\n \
    \       cin >> a >> b;\n    }\n    SparseSegmentTree<Ops> seg(n);\n    REP(i,\
    \ n) {\n        seg.update(i, fs[i]);\n    }\n    REP(qi, q) {\n        i32 type;\n\
    \        cin >> type;\n        if (type == 0) {\n            i32 p;\n        \
    \    Linear f;\n            cin >> p >> f.a >> f.b;\n            seg.update(p,\
    \ f);\n        } else {\n            i32 l, r;\n            Mint x;\n        \
    \    cin >> l >> r >> x;\n            cout << seg.prod(l, r)(x) << '\\n';\n  \
    \      }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/sparse_segment_tree.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: true
  path: data_structure/test/sparse_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-04 19:50:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/sparse_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/sparse_segment_tree.test.cpp
- /verify/data_structure/test/sparse_segment_tree.test.cpp.html
title: data_structure/test/sparse_segment_tree.test.cpp
---
