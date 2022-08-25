---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.hpp
    title: data_structure/sliding_window_aggregation.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"data_structure/test/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#define FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n\
    #define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n)\
    \ for (i32 i = (i32) (m); i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER(i, n) for (i32 i = (i32) (n) - 1; i >=\
    \ 0; --i)\n#define ALL(x) begin(x), end(x)\n\nusing namespace std;\n\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing i128 = __int128_t;\n\
    using f64 = double;\nusing f80 = long double;\n\ntemplate <typename T>\nusing\
    \ Vec = vector<T>;\n\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
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
    \ mod1000000007 = 1000000007;\n\n#line 2 \"data_structure/sliding_window_aggregation.hpp\"\
    \n\n#line 6 \"data_structure/sliding_window_aggregation.hpp\"\n\ntemplate <typename\
    \ Monoid>\nclass SlidingWindowAggregation {\npublic:\n    using Value = typename\
    \ Monoid::Value;\n\nprivate:\n    std::stack<Value> st0;\n    std::stack<Value>\
    \ st1;\n    Value st1_prod;\n\npublic:\n    SlidingWindowAggregation() : st0({Monoid::id()}),\
    \ st1({Monoid::id()}), st1_prod(Monoid::id()) {}\n\n    void push(Value val) {\n\
    \        st1_prod = Monoid::op(st1_prod, val);\n        st1.emplace(std::move(val));\n\
    \    }\n\n    void pop() {\n        if (st0.size() == 1) {\n            while\
    \ (st1.size() > 1) {\n                st0.emplace(Monoid::op(st1.top(), st0.top()));\n\
    \                st1.pop();\n            }\n            st1_prod = Monoid::id();\n\
    \        }\n        st0.pop();\n    }\n\n    int size() const {\n        return\
    \ (int) (st0.size() + st1.size() - 2);\n    }\n\n    bool empty() const {\n  \
    \      return size() == 0;\n    }\n\n    Value prod() const {\n        return\
    \ Monoid::op(st0.top(), st1_prod);\n    }\n};\n\n#line 8 \"data_structure/test/queue_operate_all_composite.test.cpp\"\
    \n\nusing Mint = ModInt<mod998244353>;\n\nstruct Linear {\n    Mint a, b;\n  \
    \  Linear() : a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a),\
    \ b(_b) {}\n    Mint operator()(Mint x) {\n        return a * x + b;\n    }\n\
    };\n\n// f \\circ g\nLinear composite(const Linear &f, const Linear &g) {\n  \
    \  return Linear(f.a * g.a, f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value\
    \ = Linear;\n    static Value id() {\n        return Linear();\n    }\n    static\
    \ Value op(const Value &x, const Value &y) {\n        return composite(y, x);\n\
    \    }\n};\n\nint main() {\n    i32 q;\n    cin >> q;\n    SlidingWindowAggregation<Ops>\
    \ swag;\n    REP(qi, q) {\n        i32 type;\n        cin >> type;\n        if\
    \ (type == 0) {\n            Linear f;\n            cin >> f.a >> f.b;\n     \
    \       swag.push(f);\n        } else if (type == 1) {\n            swag.pop();\n\
    \        } else {\n            Mint x;\n            cin >> x;\n            cout\
    \ << swag.prod()(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../data_structure/sliding_window_aggregation.hpp\"\n\nusing Mint\
    \ = ModInt<mod998244353>;\n\nstruct Linear {\n    Mint a, b;\n    Linear() : a(Mint(1)),\
    \ b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n    Mint operator()(Mint\
    \ x) {\n        return a * x + b;\n    }\n};\n\n// f \\circ g\nLinear composite(const\
    \ Linear &f, const Linear &g) {\n    return Linear(f.a * g.a, f.a * g.b + f.b);\n\
    }\n\nstruct Ops {\n    using Value = Linear;\n    static Value id() {\n      \
    \  return Linear();\n    }\n    static Value op(const Value &x, const Value &y)\
    \ {\n        return composite(y, x);\n    }\n};\n\nint main() {\n    i32 q;\n\
    \    cin >> q;\n    SlidingWindowAggregation<Ops> swag;\n    REP(qi, q) {\n  \
    \      i32 type;\n        cin >> type;\n        if (type == 0) {\n           \
    \ Linear f;\n            cin >> f.a >> f.b;\n            swag.push(f);\n     \
    \   } else if (type == 1) {\n            swag.pop();\n        } else {\n     \
    \       Mint x;\n            cin >> x;\n            cout << swag.prod()(x) <<\
    \ '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - data_structure/sliding_window_aggregation.hpp
  isVerificationFile: true
  path: data_structure/test/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 19:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/queue_operate_all_composite.test.cpp
- /verify/data_structure/test/queue_operate_all_composite.test.cpp.html
title: data_structure/test/queue_operate_all_composite.test.cpp
---