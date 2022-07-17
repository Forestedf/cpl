---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/matrix.hpp
    title: algebra/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/library_checker/matrix_det.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#define FAST_IO\n\n#line 1\
    \ \"template/template.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cmath>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for\
    \ (i32 i = 0; i < (i32) (n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32) (m);\
    \ i < (i32) (n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n\
    #define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)\n#define ALL(x) begin(x),\
    \ end(x)\n\nusing namespace std;\n\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing u128 = __uint128_t;\nusing i32 = signed int;\nusing i64 =\
    \ signed long long;\nusing i128 = __int128_t;\nusing f64 = double;\nusing f80\
    \ = long double;\n\ntemplate <typename T>\nusing Vec = vector<T>;\n\ntemplate\
    \ <typename T>\nbool chmin(T &x, const T &y) {\n    if (x > y) {\n        x =\
    \ y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename T>\n\
    bool chmax(T &x, const T &y) {\n    if (x < y) {\n        x = y;\n        return\
    \ true;\n    }\n    return false;\n}\n\nistream &operator>>(istream &is, i128\
    \ &x) {\n    i64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream &operator<<(ostream\
    \ &os, i128 x) {\n    os << (i64) x;\n    return os;\n}\nistream &operator>>(istream\
    \ &is, u128 &x) {\n    u64 v;\n    is >> v;\n    x = v;\n    return is;\n}\nostream\
    \ &operator<<(ostream &os, u128 x) {\n    os << (u64) x;\n    return os;\n}\n\n\
    [[maybe_unused]] constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr i64\
    \ INF64 = 3000000000000000100;\nstruct SetUpIO {\n    SetUpIO() {\n#ifdef FAST_IO\n\
    \        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n#endif\n   \
    \     cout << fixed << setprecision(15);\n    }\n} set_up_io;\n#line 2 \"number_theory/mod_int.hpp\"\
    \n\n#line 5 \"number_theory/mod_int.hpp\"\n#include <type_traits>\n\n#line 2 \"\
    number_theory/utils.hpp\"\n\nconstexpr bool is_prime(unsigned n) {\n    if (n\
    \ == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned i = 2; i\
    \ * i <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n   \
    \     }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned x,\
    \ unsigned y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y !=\
    \ 0) {\n        if (y & 1) {\n            ret = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(ret) * self % mod);\n        }\n        self = static_cast<unsigned>(static_cast<unsigned\
    \ long long>(self) * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\
    \ntemplate <unsigned mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
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
    \ ModInt() : val(0) {}\n    template <typename T>\n    constexpr ModInt(T x) :\
    \ val(static_cast<unsigned>(safe_mod(x, static_cast<T>(mod)))) {}\n\n    static\
    \ constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n        ret.val\
    \ = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val() const {\n\
    \        return val;\n    }\n\n    constexpr ModInt operator+() const {\n    \
    \    return *this;\n    }\n    constexpr ModInt operator-() const {\n        return\
    \ ModInt<mod>(0u) - *this;\n    }\n\n    constexpr ModInt &operator+=(const ModInt\
    \ &rhs) {\n        val += rhs.val;\n        if (val >= mod)\n            val -=\
    \ mod;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const ModInt\
    \ &rhs) {\n        if (val < rhs.val)\n            val += mod;\n        val -=\
    \ rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
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
    \ mod1000000007 = 1000000007;\n\n#line 2 \"algebra/matrix.hpp\"\n\n#line 6 \"\
    algebra/matrix.hpp\"\n\ntemplate <typename T>\nclass Matrix {\n    std::vector<std::vector<T>>\
    \ data;\n    \npublic:\n    Matrix(int n) : data(n, std::vector<T>(n, T(0))) {}\n\
    \    Matrix(int h, int w) : data(h, std::vector<T>(w, T(0))) {}\n    // must be\
    \ rectangular\n    Matrix(std::vector<std::vector<T>> a) : data(std::move(a))\
    \ {}\n    \n    int height() const {\n        return data.size();\n    }\n   \
    \ int width() const {\n        return data.empty() ? 0 : data[0].size();\n   \
    \ }\n    bool is_square() const {\n        return height() == width();\n    }\n\
    \    \n    const T &operator()(int i, int j) const {\n        return data[i][j];\n\
    \    }\n    T &operator()(int i, int j) {\n        return data[i][j];\n    }\n\
    \    \n    Matrix<T> trans() const {\n        const int h = height(), w = width();\n\
    \        Matrix<T> ret(w, h);\n        for (int i = 0; i < h; ++i) {\n       \
    \     for (int j = 0; j < w; ++j) {\n                ret.data[j][i] = data[i][j];\n\
    \            }\n        }\n        return ret;\n    }\n    \n    Matrix<T> operator+()\
    \ const {\n        return *this;\n    }\n    Matrix<T> operator-() const {\n \
    \       const int h = height(), w = width();\n        Matrix<T> ret = *this;\n\
    \        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j)\
    \ {\n                ret.data[i][j] = -ret.data[i][j];\n            }\n      \
    \  }\n        return ret;\n    }\n    \n    Matrix<T> &operator+=(const Matrix<T>\
    \ &rhs) {\n        assert(height() == rhs.height() && width() == rhs.width());\n\
    \        const int h = height(), w = width();\n        for (int i = 0; i < h;\
    \ ++i) {\n            for (int j = 0; j < w; ++j) {\n                data[i][j]\
    \ += rhs.data[i][j];\n            }\n        }\n        return *this;\n    }\n\
    \    Matrix<T> &operator-=(const Matrix<T> &rhs) {\n        assert(height() ==\
    \ rhs.height() && width() == rhs.width());\n        const int h = height(), w\
    \ = width();\n        for (int i = 0; i < h; ++i) {\n            for (int j =\
    \ 0; j < w; ++j) {\n                data[i][j] -= rhs.data[i][j];\n          \
    \  }\n        }\n        return *this;\n    }\n    friend Matrix<T> operator+(const\
    \ Matrix<T> &lhs, const Matrix<T> &rhs) {\n        return lhs += rhs;\n    }\n\
    \    friend Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {\n\
    \        return lhs -= rhs;\n    }\n    \n    friend Matrix<T> operator*(const\
    \ Matrix<T> &lhs, const Matrix<T> &rhs) {\n        assert(lhs.width() == rhs.height());\n\
    \        const int n = lhs.height(), m = rhs.height(), k = rhs.width();\n    \
    \    Matrix<T> ret(n, k);\n        for (int i = 0; i < n; ++i) {\n           \
    \ for (int j = 0; j < k; ++j) {\n                for (int l = 0; l < m; ++l) {\n\
    \                    ret.data[i][j] += lhs.data[i][l] * rhs.data[l][j];\n    \
    \            }\n            }\n        }\n        return ret;\n    }\n    Matrix<T>\
    \ &operator*=(const Matrix<T> &rhs) {\n        return *this = *this * rhs;\n \
    \   }\n    \n    static Matrix<T> e(int n) {\n        Matrix<T> mat(n);\n    \
    \    for (int i = 0; i < n; ++i) {\n            mat.data[i][i] = T(1);\n     \
    \   }\n        return mat;\n    }\n    \n    Matrix<T> pow(unsigned long long\
    \ t) {\n        assert(height() == width());\n        Matrix<T> ret = Matrix::e(height());\n\
    \        Matrix<T> self = *this;\n        while (t > 0) {\n            if (t %\
    \ 2 == 1) {\n                ret = ret * self;\n            }\n            self\
    \ = self * self;\n            t /= 2;\n        }\n        return ret;\n    }\n\
    \    \n    T det() const {\n        assert(is_square());\n        const int n\
    \ = height();\n        std::vector<std::vector<T>> a = data;\n        T ans(1);\n\
    \        for (int i = 0; i < n; ++i) {\n            int nonzero = -1;\n      \
    \      for (int j = i; j < n; ++j) {\n                if (a[j][i] != T(0)) {\n\
    \                    nonzero = j;\n                    break;\n              \
    \  }\n            }\n            if (nonzero == -1) {\n                return\
    \ T(0);\n            }\n            if (nonzero != i) {\n                std::swap(a[i],\
    \ a[nonzero]);\n                ans = -ans;\n            }\n            ans *=\
    \ a[i][i];\n            {\n                const T inv = T(1) / T(a[i][i]);\n\
    \                for (int j = i; j < n; ++j) {\n                    a[i][j] *=\
    \ inv;\n                }\n            }\n            for (int j = i + 1; j <\
    \ n; ++j) {\n                const T tmp = a[j][i];\n                for (int\
    \ k = i; k < n; ++k) {\n                    a[j][k] -= tmp * a[i][k];\n      \
    \          }\n            }\n        }\n        return ans;\n    }\n};\n#line\
    \ 8 \"test/library_checker/matrix_det.test.cpp\"\n\nusing Mint = ModInt<mod998244353>;\n\
    \nint main() {\n    i32 n;\n    cin >> n;\n    Matrix<Mint> a(n);\n    REP(i,\
    \ n) REP(j, n) {\n        cin >> a(i, j);\n    }\n    Mint det = a.det();\n  \
    \  cout << det << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#define\
    \ FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../algebra/matrix.hpp\"\n\nusing Mint = ModInt<mod998244353>;\n\
    \nint main() {\n    i32 n;\n    cin >> n;\n    Matrix<Mint> a(n);\n    REP(i,\
    \ n) REP(j, n) {\n        cin >> a(i, j);\n    }\n    Mint det = a.det();\n  \
    \  cout << det << '\\n';\n}"
  dependsOn:
  - template/template.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - algebra/matrix.hpp
  isVerificationFile: true
  path: test/library_checker/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 16:00:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix_det.test.cpp
- /verify/test/library_checker/matrix_det.test.cpp.html
title: test/library_checker/matrix_det.test.cpp
---
