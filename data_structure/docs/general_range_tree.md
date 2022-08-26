---
title: 一般の領域木
documentation_of: //data_structure/general_range_tree.hpp
---

2 次元平面上の点を与えると、長方形領域に対するクエリをうまく処理するための前処理を良い感じに行ってくれる。

具体的には、$n$ 個の点 $(x_0, y_0), (x_1, y_1), \ldots, (x_{n-1}, y_{n-1})$ を与えると、長さ $O(n \log n)$ で各要素が $0$ 以上 $n-1$ 以下の配列 $p = (p_0, p_1, \ldots, p_{m-1})$ を作成する。`rectangle(xl, xr, yl, yr)` を呼ぶと、$O(\log n)$ 個の区間 $[l_0, r_0), [l_1, r_1), \ldots, [l_{k-1}, r_{k-1})$ が返される。$S := \lbrace i \mid x_l \leq x_i \lt x_r, y_l \leq y_i \lt y_r \rbrace$ として、$p[l_0, r_0), p[l_1, r_1), \ldots, p[l_{k-1}, r_{k-1})$ を結合した列を $q$ とすると、$q$ の要素は互いに異なり、さらに $q$ を集合として見ると $S$ と一致する。

## 計算量

コンストラクタで与えられる点の数を $n$ とする。

### コンストラクタ

$O(n \log n)$ 時間

### `rectangle(xl, xr, yl, yr)`

$O\left( (\log n)^2 \right)$ 時間