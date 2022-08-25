---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':question:'
    path: number_theory/number_theoretic_transform.hpp
    title: number_theory/number_theoretic_transform.hpp
  - icon: ':question:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  - icon: ':question:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':question:'
    path: polynomial/fps_log.hpp
    title: polynomial/fps_log.hpp
  - icon: ':question:'
    path: polynomial/polynomial.hpp
    title: polynomial/polynomial.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"polynomial/test/log_of_formal_power_series.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
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
    \  }\n} set_up_io;\n#line 2 \"number_theory/number_theoretic_transform.hpp\"\n\
    \n#line 5 \"number_theory/number_theoretic_transform.hpp\"\n\n#line 2 \"number_theory/mod_int.hpp\"\
    \n\n#line 5 \"number_theory/mod_int.hpp\"\n#include <type_traits>\n\n#line 2 \"\
    number_theory/utils.hpp\"\n\nconstexpr bool is_prime(unsigned n) {\n    if (n\
    \ == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned i = 2; i\
    \ * i <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n   \
    \     }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned x,\
    \ unsigned y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y !=\
    \ 0) {\n        if (y & 1) {\n            ret = (unsigned) ((unsigned long long)\
    \ ret * self % mod);\n        }\n        self = (unsigned) ((unsigned long long)\
    \ self * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate\
    \ <unsigned mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n\
    \    }\n\n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned\
    \ m = mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if\
    \ (m % i == 0) {\n                primes[it++] = i;\n                while (m\
    \ % i == 0) {\n                    m /= i;\n                }\n            }\n\
    \        }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n\
    \    }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n  \
    \      for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) /\
    \ primes[j], mod) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if (ok)\n            return i;\n    }\n   \
    \ return 0;\n}\n\n// y >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x,\
    \ T y) {\n    x %= y;\n    if (x < 0) {\n        x += y;\n    }\n    return x;\n\
    }\n\n// y != 0\ntemplate <typename T>\nconstexpr T floor_div(T x, T y) {\n   \
    \ if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n\
    \        return x / y;\n    } else {\n        return -((-x + y - 1) / y);\n  \
    \  }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T ceil_div(T x, T y) {\n\
    \    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0)\
    \ {\n        return (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n\
    \    }\n}\n#line 8 \"number_theory/mod_int.hpp\"\n\ntemplate <unsigned mod>\n\
    class ModInt {\n    static_assert(mod != 0, \"`mod` must not be equal to 0.\"\
    );\n    static_assert(\n        mod < (1u << 31),\n        \"`mod` must be less\
    \ than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\npublic:\n    constexpr\
    \ ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ mod1000000007 = 1000000007;\n\n#line 2 \"template/bitop.hpp\"\n\ntemplate <typename\
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
    \ 1;\n    return x & mask;\n}\n#line 8 \"number_theory/number_theoretic_transform.hpp\"\
    \n\ntemplate <unsigned mod>\nclass NumberTheoreticTransform {\n    static constexpr\
    \ int calc_ex() {\n        unsigned m = mod - 1;\n        int ret = 0;\n     \
    \   while (!(m & 1)) {\n            m >>= 1;\n            ++ret;\n        }\n\
    \        return ret;\n    }\n\n    static constexpr int max_ex = calc_ex();\n\n\
    \    std::array<ModInt<mod>, max_ex + 1> root;\n    std::array<ModInt<mod>, max_ex\
    \ + 1> inv_root;\n    std::array<ModInt<mod>, max_ex + 2> inc;\n    std::array<ModInt<mod>,\
    \ max_ex + 2> inv_inc;\n\npublic:\n    void dft(std::vector<ModInt<mod>> &a) const\
    \ {\n        int n = (int) a.size();\n        int ex = ctz(n);\n        for (int\
    \ i = 0; i < ex; ++i) {\n            int pr = 1 << (ex - 1 - i);\n           \
    \ int len = 1 << i;\n            ModInt<mod> zeta(1);\n            for (int j\
    \ = 0; j < len; ++j) {\n                int offset = j << (ex - i);\n        \
    \        for (int k = 0; k < pr; ++k) {\n                    ModInt<mod> l = a[offset\
    \ + k];\n                    ModInt<mod> r = a[offset + k + pr] * zeta;\n    \
    \                a[offset + k] = l + r;\n                    a[offset + k + pr]\
    \ = l - r;\n                }\n                zeta *= inc[ctz(~j)];\n       \
    \     }\n        }\n    }\n\n    void idft(std::vector<ModInt<mod>> &a) const\
    \ {\n        int n = (int) a.size();\n        int ex = ctz(n);\n        for (int\
    \ i = ex - 1; i >= 0; --i) {\n            int pr = 1 << (ex - 1 - i);\n      \
    \      int len = 1 << i;\n            ModInt<mod> zeta(1);\n            for (int\
    \ j = 0; j < len; ++j) {\n                int offset = j << (ex - i);\n      \
    \          for (int k = 0; k < pr; ++k) {\n                    ModInt<mod> l =\
    \ a[offset + k];\n                    ModInt<mod> r = a[offset + k + pr];\n  \
    \                  a[offset + k] = l + r;\n                    a[offset + k +\
    \ pr] = (l - r) * zeta;\n                }\n                zeta *= inv_inc[ctz(~j)];\n\
    \            }\n        }\n        ModInt<mod> inv = ModInt<mod>::raw((unsigned)\
    \ a.size()).inv();\n        for (ModInt<mod> &ele : a) {\n            ele *= inv;\n\
    \        }\n    }\n\n    constexpr NumberTheoreticTransform() : root(), inv_root()\
    \ {\n        ModInt<mod> g = ModInt<mod>::raw(primitive_root<mod>()).pow((mod\
    \ - 1) >> max_ex);\n        root[max_ex] = g;\n        inv_root[max_ex] = g.inv();\n\
    \        for (int i = max_ex; i > 0; --i) {\n            root[i - 1] = root[i]\
    \ * root[i];\n            inv_root[i - 1] = inv_root[i] * inv_root[i];\n     \
    \   }\n        ModInt<mod> prod(1);\n        for (int i = 2; i <= max_ex; ++i)\
    \ {\n            inc[i - 2] = root[i] * prod;\n            prod *= inv_root[i];\n\
    \        }\n        prod = ModInt<mod>(1);\n        for (int i = 2; i <= max_ex;\
    \ ++i) {\n            inv_inc[i - 2] = inv_root[i] * prod;\n            prod *=\
    \ root[i];\n        }\n    }\n\n    std::vector<ModInt<mod>> multiply(\n     \
    \   std::vector<ModInt<mod>> a,\n        std::vector<ModInt<mod>> b) const {\n\
    \        if (a.empty() || b.empty())\n            return std::vector<ModInt<mod>>();\n\
    \        int siz = 1;\n        int s = (int) (a.size() + b.size());\n        while\
    \ (siz < s) {\n            siz <<= 1;\n        }\n        a.resize(siz, ModInt<mod>());\n\
    \        b.resize(siz, ModInt<mod>());\n        dft(a);\n        dft(b);\n   \
    \     for (int i = 0; i < siz; ++i) {\n            a[i] *= b[i];\n        }\n\
    \        idft(a);\n        a.resize(s - 1);\n        return a;\n    }\n};\n\n\
    template <unsigned mod>\nclass NTTMul {\n    static constexpr NumberTheoreticTransform<mod>\
    \ ntt = NumberTheoreticTransform<mod>();\n\npublic:\n    static void dft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.dft(a);\n    }\n\n    static void idft(std::vector<ModInt<mod>>\
    \ &a) {\n        ntt.idft(a);\n    }\n\n    static std::vector<ModInt<mod>> mul(\n\
    \        std::vector<ModInt<mod>> lhs,\n        std::vector<ModInt<mod>> rhs)\
    \ {\n        return ntt.multiply(std::move(lhs), std::move(rhs));\n    }\n};\n\
    \n#line 2 \"polynomial/fps_log.hpp\"\n\n#line 2 \"polynomial/fps_inv.hpp\"\n\n\
    #line 2 \"polynomial/polynomial.hpp\"\n\n#line 7 \"polynomial/polynomial.hpp\"\
    \n\ntemplate <typename T, typename Mul>\nclass Polynomial {\n    std::vector<T>\
    \ coeff;\n    \npublic:\n    using This = Polynomial<T, Mul>;\n    \n    Polynomial()\
    \ : coeff() {}\n    Polynomial(int n) : coeff(n, T(0)) {}\n    Polynomial(std::vector<T>\
    \ c) : coeff(std::move(c)) {}\n    \n    const std::vector<T> &vec() const {\n\
    \        return coeff;\n    }\n    \n    int size() const {\n        return (int)\
    \ coeff.size();\n    }\n    \n    const T &operator[](int idx) const {\n     \
    \   return coeff[idx];\n    }\n    T &operator[](int idx) {\n        return coeff[idx];\n\
    \    }\n    \n    T at(int idx) const {\n        if (idx < size()) {\n       \
    \     return coeff[idx];\n        } else {\n            return T(0);\n       \
    \ }\n    }\n    \n    void pre_(int n) {\n        assert(n >= 0);\n        coeff.resize(n,\
    \ T(0));\n    }\n    This pre(int n) const {\n        This tmp(*this);\n     \
    \   tmp.pre_(n);\n        return tmp;\n    }\n    \n    T operator()(const T &x)\
    \ const {\n        T p(1), sum(0);\n        for (const T &ele : coeff) {\n   \
    \         sum += p * ele;\n            p *= x;\n        }\n        return sum;\n\
    \    }\n    \n    This &operator+=(const This &rhs) {\n        if (coeff.size()\
    \ < rhs.coeff.size()) {\n            coeff.resize(rhs.coeff.size(), T(0));\n \
    \       }\n        for (int i = 0; i < (int) rhs.coeff.size(); ++i) {\n      \
    \      coeff[i] += rhs.coeff[i];\n        }\n        return *this;\n    }\n  \
    \  friend This operator+(This lhs, const This &rhs) {\n        lhs += rhs;\n \
    \       return lhs;\n    }\n    This &operator-=(const This &rhs) {\n        if\
    \ (coeff.size() < rhs.coeff.size()) {\n            coeff.resize(rhs.coeff.size(),\
    \ T(0));\n        }\n        for (int i = 0; i < (int) rhs.coeff.size(); ++i)\
    \ {\n            coeff[i] -= rhs.coeff[i];\n        }\n        return *this;\n\
    \    }\n    friend This operator-(This lhs, const This &rhs) {\n        lhs -=\
    \ rhs;\n        return lhs;\n    }\n    \n    This &operator*=(This rhs) {\n \
    \       coeff = Mul::mul(std::move(coeff), std::move(rhs.coeff));\n        return\
    \ *this;\n    }\n    friend This operator*(This lhs, This rhs) {\n        return\
    \ This(Mul::mul(std::move(lhs.coeff), std::move(rhs.coeff)));\n    }\n    \n \
    \   This diff() const {\n        if (coeff.empty()) {\n            return This();\n\
    \        }\n        std::vector<T> c(coeff.size() - 1);\n        for (int i =\
    \ 0; i < (int) c.size(); ++i) {\n            c[i] = T(i + 1) * coeff[i + 1];\n\
    \        }\n        return This(c);\n    }\n    This integ() const {\n       \
    \ std::vector<T> c(coeff.size() + 1, T(0));\n        for (int i = 0; i < (int)\
    \ coeff.size(); ++i) {\n            c[i + 1] = coeff[i] / T(i + 1);\n        }\n\
    \        return This(c);\n    }\n};\n#line 4 \"polynomial/fps_inv.hpp\"\n\ntemplate\
    \ <typename T, typename Mul>\nPolynomial<T, Mul> fps_inv(const Polynomial<T, Mul>\
    \ &f, int sz = -1) {\n    const std::vector<T> &coeff = f.vec();\n    assert(!coeff.empty()\
    \ && coeff[0] != T(0));\n    if (sz == -1) {\n        sz = (int) coeff.size();\n\
    \    }\n    assert(sz >= 0);\n    std::vector<T> g({T(1) / coeff[0]});\n    while\
    \ ((int) g.size() < sz) {\n        std::vector<T> fg;\n        if (2 * g.size()\
    \ <= coeff.size()) {\n            fg = std::vector<T>(coeff.begin(), coeff.begin()\
    \ + 2 * g.size());\n        } else {\n            fg = coeff;\n            fg.resize(2\
    \ * g.size());\n        }\n        Mul::dft(fg);\n        std::vector<T> dft_g\
    \ = g;\n        dft_g.resize(2 * g.size(), T(0));\n        Mul::dft(dft_g);\n\
    \        for (int i = 0; i < 2 * (int) g.size(); ++i) {\n            fg[i] *=\
    \ dft_g[i];\n        }\n        Mul::idft(fg);\n        std::fill(fg.begin(),\
    \ fg.begin() + g.size(), T(0));\n        Mul::dft(fg);\n        for (int i = 0;\
    \ i < 2 * (int) g.size(); ++i) {\n            fg[i] *= dft_g[i];\n        }\n\
    \        Mul::idft(fg);\n        g.resize(2 * g.size());\n        for (int i =\
    \ (int) g.size() / 2; i < (int) g.size(); ++i) {\n            g[i] = -fg[i];\n\
    \        }\n    }\n    g.resize(sz);\n    return Polynomial<T, Mul>(g);\n}\n#line\
    \ 4 \"polynomial/fps_log.hpp\"\n\ntemplate <typename T, typename Mul>\nPolynomial<T,\
    \ Mul> fps_log(const Polynomial<T, Mul> &f, int sz = -1) {\n    const std::vector<T>\
    \ &coeff = f.vec();\n    assert(!coeff.empty() && coeff[0] == T(1));\n    if (sz\
    \ == -1) {\n        sz = (int) coeff.size();\n    }\n    assert(sz >= 0);\n  \
    \  if (sz == 0) {\n        return Polynomial<T, Mul>();\n    }\n    return (f.diff().pre(sz\
    \ - 1) * fps_inv(f, sz - 1)).pre(sz - 1).integ();\n}\n#line 8 \"polynomial/test/log_of_formal_power_series.test.cpp\"\
    \n\nint main() {\n    using Mint = ModInt<mod998244353>;\n    using FPS = Polynomial<Mint,\
    \ NTTMul<mod998244353>>;\n    \n    i32 n;\n    cin >> n;\n    FPS f(n);\n   \
    \ REP(i, n) {\n        cin >> f[i];\n    }\n    FPS g = fps_log(f);\n    REP(i,\
    \ n) {\n        cout << g[i] << \" \\n\"[i + 1 == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/number_theoretic_transform.hpp\"\
    \n#include \"../../polynomial/fps_log.hpp\"\n\nint main() {\n    using Mint =\
    \ ModInt<mod998244353>;\n    using FPS = Polynomial<Mint, NTTMul<mod998244353>>;\n\
    \    \n    i32 n;\n    cin >> n;\n    FPS f(n);\n    REP(i, n) {\n        cin\
    \ >> f[i];\n    }\n    FPS g = fps_log(f);\n    REP(i, n) {\n        cout << g[i]\
    \ << \" \\n\"[i + 1 == n];\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - number_theory/number_theoretic_transform.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - template/bitop.hpp
  - polynomial/fps_log.hpp
  - polynomial/fps_inv.hpp
  - polynomial/polynomial.hpp
  isVerificationFile: true
  path: polynomial/test/log_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 20:03:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: polynomial/test/log_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/polynomial/test/log_of_formal_power_series.test.cpp
- /verify/polynomial/test/log_of_formal_power_series.test.cpp.html
title: polynomial/test/log_of_formal_power_series.test.cpp
---