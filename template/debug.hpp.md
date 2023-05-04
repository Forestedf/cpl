---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/debug.hpp\"\n\n#include <array>\n#include <deque>\n\
    #include <iostream>\n#include <map>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <type_traits>\n#include <utility>\n#include <vector>\n#include\
    \ <tuple>\n\n#line 2 \"number_theory/mod_int.hpp\"\n\n#include <cassert>\n#line\
    \ 6 \"number_theory/mod_int.hpp\"\n\n#line 2 \"number_theory/utils.hpp\"\n\nconstexpr\
    \ bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return false;\n\
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
    public:\n    static constexpr unsigned get_mod() {\n        return mod;\n    }\n\
    \    \n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ = 1000000007;\n\n#line 16 \"template/debug.hpp\"\n\ntemplate <typename T, std::enable_if_t<std::is_integral_v<T>>\
    \ * = nullptr>\nvoid debug(T x) {\n    std::cerr << x;\n}\n\ntemplate <typename\
    \ T, std::enable_if_t<std::is_floating_point_v<T>> * = nullptr>\nvoid debug(T\
    \ x) {\n    std::cerr << x;\n}\n\nvoid debug(bool b) {\n    if (b) {\n       \
    \ std::cerr << \"true\";\n    } else {\n        std::cerr << \"false\";\n    }\n\
    }\n\ntemplate <typename T>\nvoid debug(const std::vector<T> &x);\n\ntemplate <unsigned\
    \ mod>\nvoid debug(const ModInt<mod> &x) {\n    std::cerr << x;\n}\n\nvoid debug(const\
    \ std::string &s) {\n    std::cerr << '\"' << s << '\"';\n}\n\ntemplate <typename\
    \ T, typename U>\nvoid debug(const std::pair<T, U> &p) {\n    std::cerr << '(';\n\
    \    debug(p.first);\n    std::cerr << \", \";\n    debug(p.second);\n    std::cerr\
    \ << ')';\n}\n\ntemplate <std::size_t cur, typename... Args>\nvoid tuple_debug_inner(const\
    \ std::tuple<Args...> &t) {\n    std::cerr << std::get<cur>(t);\n    if constexpr\
    \ (cur + 1 != sizeof...(Args)) {\n        std::cerr << \", \";\n        tuple_debug_inner<cur\
    \ + 1, Args...>(t);\n    }\n}\n\ntemplate <typename... Args>\nvoid debug(const\
    \ std::tuple<Args...> &t) {\n    std::cerr << '(';\n    tuple_debug_inner<0, Args...>(t);\n\
    \    std::cerr << ')';\n}\n\ntemplate <typename T, std::size_t s>\nvoid debug(const\
    \ std::array<T, s> &arr) {\n    std::cerr << '[';\n    for (std::size_t i = 0;\
    \ i < s; ++i) {\n        debug(arr[i]);\n        if (i + 1 != s) {\n         \
    \   std::cerr << \", \";\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate\
    \ <typename K, typename V>\nvoid debug(const std::map<K, V> &mp) {\n    std::cerr\
    \ << '{';\n    for (const auto [k, v] : mp) {\n        std::cerr << ' ';\n   \
    \     debug(k);\n        std::cerr << ':';\n        debug(v);\n    }\n    std::cerr\
    \ << \" }\";\n}\n\ntemplate <typename T>\nvoid debug(const std::set<T> &st) {\n\
    \    std::cerr << '{';\n    for (const T &ele : st) {\n        std::cerr << '\
    \ ';\n        debug(ele);\n    }\n    std::cerr << \" }\";\n}\n\ntemplate <typename\
    \ T>\nvoid debug(std::queue<T> que) {\n    std::cerr << '[';\n    while (!que.empty())\
    \ {\n        T ele = que.front();\n        que.pop();\n        debug(ele);\n \
    \       if (!que.empty()) {\n            std::cerr << ' ';\n        }\n    }\n\
    \    std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid debug(const std::vector<T>\
    \ &v) {\n    std::cerr << '[';\n    for (std::size_t i = 0; i < v.size(); ++i)\
    \ {\n        debug(v[i]);\n        if (i + 1 != v.size()) {\n            std::cerr\
    \ << \", \";\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename\
    \ T, typename Container, typename Comp>\nvoid debug(std::priority_queue<T, Container,\
    \ Comp> que) {\n    std::cerr << '[';\n    while (!que.empty()) {\n        T ele\
    \ = que.top();\n        que.pop();\n        debug(ele);\n        if (!que.empty())\
    \ {\n            std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n\
    }\n\ntemplate <typename T>\nvoid debug(std::stack<T> sta) {\n    std::cerr <<\
    \ '[';\n    while (!sta.empty()) {\n        T ele = sta.top();\n        sta.pop();\n\
    \        debug(ele);\n        if (!sta.empty()) {\n            std::cerr << '\
    \ ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid\
    \ debug(std::deque<T> dq) {\n    std::cerr << '[';\n    while (!dq.empty()) {\n\
    \        T ele = dq.front();\n        dq.pop_front();\n        debug(ele);\n \
    \       if (!dq.empty()) {\n            std::cerr << ' ';\n        }\n    }\n\
    \    std::cerr << ']';\n}\n\n#define DBG(x)                   \\\n    do {   \
    \                      \\\n        std::cerr << #x << \": \"; \\\n        debug(x);\
    \                \\\n        std::cerr << std::endl;  \\\n    } while (false)\n"
  code: "#pragma once\n\n#include <array>\n#include <deque>\n#include <iostream>\n\
    #include <map>\n#include <queue>\n#include <set>\n#include <stack>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n#include <tuple>\n\n#include \"../number_theory/mod_int.hpp\"\
    \n\ntemplate <typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>\n\
    void debug(T x) {\n    std::cerr << x;\n}\n\ntemplate <typename T, std::enable_if_t<std::is_floating_point_v<T>>\
    \ * = nullptr>\nvoid debug(T x) {\n    std::cerr << x;\n}\n\nvoid debug(bool b)\
    \ {\n    if (b) {\n        std::cerr << \"true\";\n    } else {\n        std::cerr\
    \ << \"false\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(const std::vector<T>\
    \ &x);\n\ntemplate <unsigned mod>\nvoid debug(const ModInt<mod> &x) {\n    std::cerr\
    \ << x;\n}\n\nvoid debug(const std::string &s) {\n    std::cerr << '\"' << s <<\
    \ '\"';\n}\n\ntemplate <typename T, typename U>\nvoid debug(const std::pair<T,\
    \ U> &p) {\n    std::cerr << '(';\n    debug(p.first);\n    std::cerr << \", \"\
    ;\n    debug(p.second);\n    std::cerr << ')';\n}\n\ntemplate <std::size_t cur,\
    \ typename... Args>\nvoid tuple_debug_inner(const std::tuple<Args...> &t) {\n\
    \    std::cerr << std::get<cur>(t);\n    if constexpr (cur + 1 != sizeof...(Args))\
    \ {\n        std::cerr << \", \";\n        tuple_debug_inner<cur + 1, Args...>(t);\n\
    \    }\n}\n\ntemplate <typename... Args>\nvoid debug(const std::tuple<Args...>\
    \ &t) {\n    std::cerr << '(';\n    tuple_debug_inner<0, Args...>(t);\n    std::cerr\
    \ << ')';\n}\n\ntemplate <typename T, std::size_t s>\nvoid debug(const std::array<T,\
    \ s> &arr) {\n    std::cerr << '[';\n    for (std::size_t i = 0; i < s; ++i) {\n\
    \        debug(arr[i]);\n        if (i + 1 != s) {\n            std::cerr << \"\
    , \";\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename K, typename\
    \ V>\nvoid debug(const std::map<K, V> &mp) {\n    std::cerr << '{';\n    for (const\
    \ auto [k, v] : mp) {\n        std::cerr << ' ';\n        debug(k);\n        std::cerr\
    \ << ':';\n        debug(v);\n    }\n    std::cerr << \" }\";\n}\n\ntemplate <typename\
    \ T>\nvoid debug(const std::set<T> &st) {\n    std::cerr << '{';\n    for (const\
    \ T &ele : st) {\n        std::cerr << ' ';\n        debug(ele);\n    }\n    std::cerr\
    \ << \" }\";\n}\n\ntemplate <typename T>\nvoid debug(std::queue<T> que) {\n  \
    \  std::cerr << '[';\n    while (!que.empty()) {\n        T ele = que.front();\n\
    \        que.pop();\n        debug(ele);\n        if (!que.empty()) {\n      \
    \      std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate\
    \ <typename T>\nvoid debug(const std::vector<T> &v) {\n    std::cerr << '[';\n\
    \    for (std::size_t i = 0; i < v.size(); ++i) {\n        debug(v[i]);\n    \
    \    if (i + 1 != v.size()) {\n            std::cerr << \", \";\n        }\n \
    \   }\n    std::cerr << ']';\n}\n\ntemplate <typename T, typename Container, typename\
    \ Comp>\nvoid debug(std::priority_queue<T, Container, Comp> que) {\n    std::cerr\
    \ << '[';\n    while (!que.empty()) {\n        T ele = que.top();\n        que.pop();\n\
    \        debug(ele);\n        if (!que.empty()) {\n            std::cerr << '\
    \ ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid\
    \ debug(std::stack<T> sta) {\n    std::cerr << '[';\n    while (!sta.empty())\
    \ {\n        T ele = sta.top();\n        sta.pop();\n        debug(ele);\n   \
    \     if (!sta.empty()) {\n            std::cerr << ' ';\n        }\n    }\n \
    \   std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid debug(std::deque<T> dq)\
    \ {\n    std::cerr << '[';\n    while (!dq.empty()) {\n        T ele = dq.front();\n\
    \        dq.pop_front();\n        debug(ele);\n        if (!dq.empty()) {\n  \
    \          std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\n#define\
    \ DBG(x)                   \\\n    do {                         \\\n        std::cerr\
    \ << #x << \": \"; \\\n        debug(x);                \\\n        std::cerr\
    \ << std::endl;  \\\n    } while (false)"
  dependsOn:
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2023-05-04 19:50:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: template/debug.hpp
---
