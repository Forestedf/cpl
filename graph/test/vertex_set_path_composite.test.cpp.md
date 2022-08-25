---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':question:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':question:'
    path: graph/heavy_light_decomposition.hpp
    title: graph/heavy_light_decomposition.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"graph/test/vertex_set_path_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#define\
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
    \ mod1000000007 = 1000000007;\n\n#line 2 \"graph/graph.hpp\"\n\n#line 7 \"graph/graph.hpp\"\
    \n\ntemplate <typename Edge>\nclass Graph {\n    std::vector<std::vector<Edge>>\
    \ edges;\n\npublic:\n    Graph() : edges() {}\n    Graph(int v) : edges(v) {\n\
    \        assert(v >= 0);\n    }\n    \n    std::vector<int> add_vertices(int n)\
    \ {\n        int v = (int) edges.size();\n        std::vector<int> idx(n);\n \
    \       std::iota(idx.begin(), idx.end(), v);\n        edges.resize(edges.size()\
    \ + n);\n        return idx;\n    }\n\n    template <typename... T>\n    void\
    \ add_directed_edge(int from, int to, T &&...val) {\n        assert(from >= 0\
    \ && from < (int) edges.size());\n        assert(to >= 0 && to < (int) edges.size());\n\
    \        edges[from].emplace_back(Edge(to, std::forward<T>(val)...));\n    }\n\
    \n    template <typename... T>\n    void add_undirected_edge(int u, int v, const\
    \ T &...val) {\n        assert(u >= 0 && u < (int) edges.size());\n        assert(v\
    \ >= 0 && v < (int) edges.size());\n        edges[u].emplace_back(Edge(v, val...));\n\
    \        edges[v].emplace_back(Edge(u, val...));\n    }\n\n    int size() const\
    \ {\n        return (int) edges.size();\n    }\n\n    const std::vector<Edge>\
    \ &operator[](int v) const {\n        assert(v >= 0 && v < (int) edges.size());\n\
    \        return edges[v];\n    }\n\n    std::vector<Edge> &operator[](int v) {\n\
    \        assert(v >= 0 && v < (int) edges.size());\n        return edges[v];\n\
    \    }\n};\n\nstruct UnweightedEdge {\n    int to;\n\n    UnweightedEdge(int t)\
    \ : to(t) {}\n    \n    explicit operator int() const {\n        return to;\n\
    \    }\n\n    using Weight = std::size_t;\n    Weight weight() const {\n     \
    \   return 1;\n    }\n};\n\ntemplate <typename T>\nstruct WeightedEdge {\n   \
    \ int to;\n    T wt;\n\n    WeightedEdge(int t, const T &w) : to(t), wt(w) {}\n\
    \n    explicit operator int() const {\n        return to;\n    }\n\n    using\
    \ Weight = T;\n    Weight weight() const {\n        return wt;\n    }\n};\n\n\
    #line 2 \"graph/heavy_light_decomposition.hpp\"\n\n#line 7 \"graph/heavy_light_decomposition.hpp\"\
    \n\nclass HeavyLightDecomposition {\n    std::vector<int> siz;\n    std::vector<int>\
    \ par;\n    std::vector<int> hea;\n    std::vector<int> in;\n    std::vector<int>\
    \ out;\n    std::vector<int> dep;\n    std::vector<int> rev;\n\n    template <typename\
    \ G>\n    void dfs1(G &g, int v) {\n        if (!g[v].empty() && (int) g[v][0]\
    \ == par[v]) {\n            std::swap(g[v][0], g[v].back());\n        }\n    \
    \    for (auto &e : g[v]) {\n            int u = (int)e;\n            if (u !=\
    \ par[v]) {\n                par[u] = v;\n                dfs1(g, u);\n      \
    \          siz[v] += siz[u];\n                if (siz[u] > siz[g[v][0]]) {\n \
    \                   std::swap(g[v][0], e);\n                }\n            }\n\
    \        }\n    }\n\n    template <typename G>\n    void dfs2(const G &g, int\
    \ v, int &time) {\n        in[v] = time;\n        rev[time++] = v;\n        for\
    \ (auto &e : g[v]) {\n            int u = (int)e;\n            if (u == par[v])\
    \ {\n                continue;\n            }\n            if (u == (int) g[v][0])\
    \ {\n                hea[u] = hea[v];\n            } else {\n                hea[u]\
    \ = u;\n            }\n            dep[u] = dep[v] + 1;\n            dfs2(g, u,\
    \ time);\n        }\n        out[v] = time;\n    }\n\npublic:\n    template <typename\
    \ G>\n    HeavyLightDecomposition(G &g, int root = 0) :\n        siz(g.size(),\
    \ 1),\n        par(g.size(), root),\n        hea(g.size(), root),\n        in(g.size(),\
    \ 0),\n        out(g.size(), 0),\n        dep(g.size(), 0),\n        rev(g.size(),\
    \ 0) {\n        assert(root >= 0 && root < (int) g.size());\n        dfs1(g, root);\n\
    \        int time = 0;\n        dfs2(g, root, time);\n    }\n\n    int subtree_size(int\
    \ v) const {\n        assert(v >= 0 && v < (int) siz.size());\n        return\
    \ siz[v];\n    }\n\n    int parent(int v) const {\n        assert(v >= 0 && v\
    \ < (int) par.size());\n        return par[v];\n    }\n\n    int in_time(int v)\
    \ const {\n        assert(v >= 0 && v < (int) in.size());\n        return in[v];\n\
    \    }\n\n    int out_time(int v) const {\n        assert(v >= 0 && v < (int)\
    \ out.size());\n        return out[v];\n    }\n\n    int depth(int v) const {\n\
    \        assert(v >= 0 && v < (int) dep.size());\n        return dep[v];\n   \
    \ }\n\n    int time_to_vertex(int t) const {\n        assert(t >= 0 && t < (int)\
    \ rev.size());\n        return rev[t];\n    }\n    \n    int la(int v, int k)\
    \ const {\n        assert(v >= 0 && v < (int) dep.size());\n        assert(k >=\
    \ 0);\n        if (k > dep[v]) {\n            return -1;\n        }\n        while\
    \ (true) {\n            int u = hea[v];\n            if (in[u] + k <= in[v]) {\n\
    \                return rev[in[v] - k];\n            }\n            k -= in[v]\
    \ - in[u] + 1;\n            v = par[u];\n        }\n        return 0;\n    }\n\
    \    \n    int forward(int v, int dst) const {\n        assert(v >= 0 && v < (int)\
    \ dep.size());\n        assert(dst >= 0 && dst < (int) dep.size());\n        assert(v\
    \ != dst);\n        int l = lca(v, dst);\n        if (l == v) {\n            return\
    \ la(dst, dist(v, dst) - 1);\n        } else {\n            return par[v];\n \
    \       }\n    }\n\n    int lca(int u, int v) const {\n        assert(u >= 0 &&\
    \ u < (int) dep.size());\n        assert(v >= 0 && v < (int) dep.size());\n  \
    \      while (u != v) {\n            if (in[u] > in[v]) {\n                std::swap(u,\
    \ v);\n            }\n            if (hea[u] == hea[v]) {\n                v =\
    \ u;\n            } else {\n                v = par[hea[v]];\n            }\n\
    \        }\n        return u;\n    }\n\n    int dist(int u, int v) const {\n \
    \       assert(u >= 0 && u < (int) dep.size());\n        assert(v >= 0 && v <\
    \ (int) dep.size());\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n \
    \   }\n\n    std::vector<std::pair<int, int>> path(int u, int v, bool edge) const\
    \ {\n        assert(u >= 0 && u < (int) dep.size());\n        assert(v >= 0 &&\
    \ v < (int) dep.size());\n        std::vector<std::pair<int, int>> fromu, fromv;\n\
    \        bool rev = false;\n        while (true) {\n            if (u == v &&\
    \ edge) {\n                break;\n            }\n            if (in[u] > in[v])\
    \ {\n                std::swap(u, v);\n                std::swap(fromu, fromv);\n\
    \                rev ^= true;\n            }\n            if (hea[u] == hea[v])\
    \ {\n                fromv.emplace_back(in[v], in[u] + (int)edge);\n         \
    \       v = u;\n                break;\n            } else {\n               \
    \ fromv.emplace_back(in[v], in[hea[v]]);\n                v = par[hea[v]];\n \
    \           }\n        }\n        if (rev) {\n            std::swap(fromu, fromv);\n\
    \        }\n        std::reverse(fromv.begin(), fromv.end());\n        fromu.reserve(fromv.size());\n\
    \        for (auto [x, y] : fromv) {\n            fromu.emplace_back(y, x);\n\
    \        }\n        return fromu;\n    }\n    \n    int jump(int u, int v, int\
    \ k) const {\n        assert(u >= 0 && u < (int) dep.size());\n        assert(v\
    \ >= 0 && v < (int) dep.size());\n        assert(k >= 0);\n        int l = lca(u,\
    \ v);\n        int dis = dep[u] + dep[v] - 2 * dep[l];\n        if (k > dis) {\n\
    \            return -1;\n        }\n        if (k <= dep[u] - dep[l]) {\n    \
    \        return la(u, k);\n        } else {\n            return la(v, dis - k);\n\
    \        }\n    }\n};\n\n#line 2 \"data_structure/segment_tree.hpp\"\n\n#line\
    \ 6 \"data_structure/segment_tree.hpp\"\n\n#line 2 \"data_structure/operations.hpp\"\
    \n\n#include <limits>\n#line 5 \"data_structure/operations.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Add {\n    using Value = T;\n    static Value id() {\n        return\
    \ T(0);\n    }\n    static Value op(const Value &lhs, const Value &rhs) {\n  \
    \      return lhs + rhs;\n    }\n    static Value inv(const Value &x) {\n    \
    \    return -x;\n    }\n};\n\ntemplate <typename T>\nstruct Mul {\n    using Value\
    \ = T;\n    static Value id() {\n        return Value(1);\n    }\n    static Value\
    \ op(const Value &lhs, const Value &rhs) {\n        return lhs * rhs;\n    }\n\
    \    static Value inv(const Value &x) {\n        return Value(1) / x;\n    }\n\
    };\n\ntemplate <typename T>\nstruct Min {\n    using Value = T;\n    static Value\
    \ id() {\n        return std::numeric_limits<T>::max();\n    }\n    static Value\
    \ op(const Value &lhs, const Value &rhs) {\n        return std::min(lhs, rhs);\n\
    \    }\n};\n\ntemplate <typename T>\nstruct Max {\n    using Value = T;\n    static\
    \ Value id() {\n        return std::numeric_limits<Value>::min();\n    }\n   \
    \ static Value op(const Value &lhs, const Value &rhs) {\n        return std::max(lhs,\
    \ rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Xor {\n    using Value = T;\n\
    \    static Value id() {\n        return T(0);\n    }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) {\n        return lhs ^ rhs;\n    }\n    static\
    \ Value inv(const Value &x) {\n        return x;\n    }\n};\n\ntemplate <typename\
    \ Monoid>\nstruct Reversible {\n    using Value = std::pair<typename Monoid::Value,\
    \ typename Monoid::Value>;\n    static Value id() {\n        return Value(Monoid::id(),\
    \ Monoid::id());\n    }\n    static Value op(const Value &v1, const Value &v2)\
    \ {\n        return Value(\n            Monoid::op(v1.first, v2.first),\n    \
    \        Monoid::op(v2.second, v1.second));\n    }\n};\n\n#line 8 \"data_structure/segment_tree.hpp\"\
    \n\ntemplate <typename Monoid>\nclass SegmentTree {\npublic:\n    using Value\
    \ = typename Monoid::Value;\n\nprivate:\n    int old_length;\n    int length;\n\
    \    std::vector<Value> node;\n\n    static int ceil2(int n) {\n        int l\
    \ = 1;\n        while (l < n) {\n            l <<= 1;\n        }\n        return\
    \ l;\n    }\n\npublic:\n    SegmentTree(int n) :\n        old_length(n),\n   \
    \     length(ceil2(old_length)),\n        node(length << 1, Monoid::id()) {\n\
    \        assert(n >= 0);\n    }\n\n    SegmentTree(const std::vector<Value> &v)\
    \ :\n        old_length((int) v.size()),\n        length(ceil2(old_length)),\n\
    \        node(length << 1, Monoid::id()) {\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = v[i];\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    template <typename F>\n    SegmentTree(int\
    \ n, const F &f) :\n        old_length(n), length(ceil2(n)), node(length << 1,\
    \ Monoid::id()) {\n        assert(n >= 0);\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = f(i);\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    const Value &operator[](int idx)\
    \ const {\n        assert(idx >= 0 && idx < old_length);\n        return node[idx\
    \ + length];\n    }\n\n    void update(int idx, Value val) {\n        assert(idx\
    \ >= 0 && idx < old_length);\n        idx += length;\n        node[idx] = std::move(val);\n\
    \        while (idx != 1) {\n            idx >>= 1;\n            node[idx] = Monoid::op(node[idx\
    \ << 1], node[idx << 1 | 1]);\n        }\n    }\n\n    Value prod(int l, int r)\
    \ const {\n        assert(l >= 0 && l <= r && r <= old_length);\n        Value\
    \ prodl = Monoid::id();\n        Value prodr = Monoid::id();\n        l += length;\n\
    \        r += length;\n        while (l != r) {\n            if (l & 1) {\n  \
    \              prodl = Monoid::op(prodl, node[l++]);\n            }\n        \
    \    if (r & 1) {\n                prodr = Monoid::op(node[--r], prodr);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(prodl, prodr);\n    }\n    \n    Value all_prod() const {\n     \
    \   return node[1];\n    }\n};\n\n#line 10 \"graph/test/vertex_set_path_composite.test.cpp\"\
    \n\nusing Mint = ModInt<mod998244353>;\n\nstruct Linear {\n    Mint a, b;\n  \
    \  Linear() : a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a),\
    \ b(_b) {}\n    Mint operator()(Mint x) const {\n        return a * x + b;\n \
    \   }\n};\n\nLinear composite(const Linear &f, const Linear &g) {\n    return\
    \ Linear(f.a * g.a, f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value = Linear;\n\
    \    static Value id() {\n        return Linear();\n    }\n    static Value op(const\
    \ Value &f, const Value &g) {\n        return composite(f, g);\n    }\n};\n\n\
    int main() {\n    i32 n, q;\n    cin >> n >> q;\n    Vec<Linear> fs(n);\n    REP(i,\
    \ n) {\n        cin >> fs[i].a >> fs[i].b;\n    }\n    Graph<i32> g(n);\n    REP(e,\
    \ n - 1) {\n        i32 u, v;\n        cin >> u >> v;\n        g.add_undirected_edge(u,\
    \ v);\n    }\n    HeavyLightDecomposition hld(g);\n    SegmentTree<Reversible<Ops>>\
    \ seg(n, [&](i32 i) -> typename Reversible<Ops>::Value {\n        Linear f = fs[hld.time_to_vertex(i)];\n\
    \        return pair<Linear, Linear>(f, f);\n    });\n    REP(qi, q) {\n     \
    \   i32 type;\n        cin >> type;\n        if (type == 0) {\n            i32\
    \ p;\n            Linear f;\n            cin >> p >> f.a >> f.b;\n           \
    \ seg.update(hld.in_time(p), pair<Linear, Linear>(f, f));\n        } else {\n\
    \            i32 u, v;\n            Mint x;\n            cin >> u >> v >> x;\n\
    \            Linear f;\n            for (auto [l, r] : hld.path(u, v, false))\
    \ {\n                if (l < r) {\n                    f = composite(seg.prod(l,\
    \ r + 1).second, f);\n                } else {\n                    f = composite(seg.prod(r,\
    \ l + 1).first, f);\n                }\n            }\n            cout << f(x)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../graph/graph.hpp\"\n#include \"../../graph/heavy_light_decomposition.hpp\"\
    \n#include \"../../data_structure/segment_tree.hpp\"\n\nusing Mint = ModInt<mod998244353>;\n\
    \nstruct Linear {\n    Mint a, b;\n    Linear() : a(Mint(1)), b(Mint(0)) {}\n\
    \    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n    Mint operator()(Mint x) const\
    \ {\n        return a * x + b;\n    }\n};\n\nLinear composite(const Linear &f,\
    \ const Linear &g) {\n    return Linear(f.a * g.a, f.a * g.b + f.b);\n}\n\nstruct\
    \ Ops {\n    using Value = Linear;\n    static Value id() {\n        return Linear();\n\
    \    }\n    static Value op(const Value &f, const Value &g) {\n        return\
    \ composite(f, g);\n    }\n};\n\nint main() {\n    i32 n, q;\n    cin >> n >>\
    \ q;\n    Vec<Linear> fs(n);\n    REP(i, n) {\n        cin >> fs[i].a >> fs[i].b;\n\
    \    }\n    Graph<i32> g(n);\n    REP(e, n - 1) {\n        i32 u, v;\n       \
    \ cin >> u >> v;\n        g.add_undirected_edge(u, v);\n    }\n    HeavyLightDecomposition\
    \ hld(g);\n    SegmentTree<Reversible<Ops>> seg(n, [&](i32 i) -> typename Reversible<Ops>::Value\
    \ {\n        Linear f = fs[hld.time_to_vertex(i)];\n        return pair<Linear,\
    \ Linear>(f, f);\n    });\n    REP(qi, q) {\n        i32 type;\n        cin >>\
    \ type;\n        if (type == 0) {\n            i32 p;\n            Linear f;\n\
    \            cin >> p >> f.a >> f.b;\n            seg.update(hld.in_time(p), pair<Linear,\
    \ Linear>(f, f));\n        } else {\n            i32 u, v;\n            Mint x;\n\
    \            cin >> u >> v >> x;\n            Linear f;\n            for (auto\
    \ [l, r] : hld.path(u, v, false)) {\n                if (l < r) {\n          \
    \          f = composite(seg.prod(l, r + 1).second, f);\n                } else\
    \ {\n                    f = composite(seg.prod(r, l + 1).first, f);\n       \
    \         }\n            }\n            cout << f(x) << '\\n';\n        }\n  \
    \  }\n}\n"
  dependsOn:
  - template/template.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - graph/graph.hpp
  - graph/heavy_light_decomposition.hpp
  - data_structure/segment_tree.hpp
  - data_structure/operations.hpp
  isVerificationFile: true
  path: graph/test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 19:58:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/graph/test/vertex_set_path_composite.test.cpp
- /verify/graph/test/vertex_set_path_composite.test.cpp.html
title: graph/test/vertex_set_path_composite.test.cpp
---
