---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_det.test.cpp
    title: algebra/test/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_product.test.cpp
    title: algebra/test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix_det.test.cpp
    title: test/library_checker/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix_product.test.cpp
    title: test/library_checker/matrix_product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/matrix.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T>\nclass Matrix {\n    std::vector<std::vector<T>>\
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
    \          }\n            }\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T>\nclass Matrix {\n    std::vector<std::vector<T>> data;\n\
    \    \npublic:\n    Matrix(int n) : data(n, std::vector<T>(n, T(0))) {}\n    Matrix(int\
    \ h, int w) : data(h, std::vector<T>(w, T(0))) {}\n    // must be rectangular\n\
    \    Matrix(std::vector<std::vector<T>> a) : data(std::move(a)) {}\n    \n   \
    \ int height() const {\n        return data.size();\n    }\n    int width() const\
    \ {\n        return data.empty() ? 0 : data[0].size();\n    }\n    bool is_square()\
    \ const {\n        return height() == width();\n    }\n    \n    const T &operator()(int\
    \ i, int j) const {\n        return data[i][j];\n    }\n    T &operator()(int\
    \ i, int j) {\n        return data[i][j];\n    }\n    \n    Matrix<T> trans()\
    \ const {\n        const int h = height(), w = width();\n        Matrix<T> ret(w,\
    \ h);\n        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j <\
    \ w; ++j) {\n                ret.data[j][i] = data[i][j];\n            }\n   \
    \     }\n        return ret;\n    }\n    \n    Matrix<T> operator+() const {\n\
    \        return *this;\n    }\n    Matrix<T> operator-() const {\n        const\
    \ int h = height(), w = width();\n        Matrix<T> ret = *this;\n        for\
    \ (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n     \
    \           ret.data[i][j] = -ret.data[i][j];\n            }\n        }\n    \
    \    return ret;\n    }\n    \n    Matrix<T> &operator+=(const Matrix<T> &rhs)\
    \ {\n        assert(height() == rhs.height() && width() == rhs.width());\n   \
    \     const int h = height(), w = width();\n        for (int i = 0; i < h; ++i)\
    \ {\n            for (int j = 0; j < w; ++j) {\n                data[i][j] +=\
    \ rhs.data[i][j];\n            }\n        }\n        return *this;\n    }\n  \
    \  Matrix<T> &operator-=(const Matrix<T> &rhs) {\n        assert(height() == rhs.height()\
    \ && width() == rhs.width());\n        const int h = height(), w = width();\n\
    \        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j)\
    \ {\n                data[i][j] -= rhs.data[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    friend Matrix<T> operator+(const Matrix<T>\
    \ &lhs, const Matrix<T> &rhs) {\n        return lhs += rhs;\n    }\n    friend\
    \ Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {\n        return\
    \ lhs -= rhs;\n    }\n    \n    friend Matrix<T> operator*(const Matrix<T> &lhs,\
    \ const Matrix<T> &rhs) {\n        assert(lhs.width() == rhs.height());\n    \
    \    const int n = lhs.height(), m = rhs.height(), k = rhs.width();\n        Matrix<T>\
    \ ret(n, k);\n        for (int i = 0; i < n; ++i) {\n            for (int j =\
    \ 0; j < k; ++j) {\n                for (int l = 0; l < m; ++l) {\n          \
    \          ret.data[i][j] += lhs.data[i][l] * rhs.data[l][j];\n              \
    \  }\n            }\n        }\n        return ret;\n    }\n    Matrix<T> &operator*=(const\
    \ Matrix<T> &rhs) {\n        return *this = *this * rhs;\n    }\n    \n    static\
    \ Matrix<T> e(int n) {\n        Matrix<T> mat(n);\n        for (int i = 0; i <\
    \ n; ++i) {\n            mat.data[i][i] = T(1);\n        }\n        return mat;\n\
    \    }\n    \n    Matrix<T> pow(unsigned long long t) {\n        assert(height()\
    \ == width());\n        Matrix<T> ret = Matrix::e(height());\n        Matrix<T>\
    \ self = *this;\n        while (t > 0) {\n            if (t % 2 == 1) {\n    \
    \            ret = ret * self;\n            }\n            self = self * self;\n\
    \            t /= 2;\n        }\n        return ret;\n    }\n    \n    T det()\
    \ const {\n        assert(is_square());\n        const int n = height();\n   \
    \     std::vector<std::vector<T>> a = data;\n        T ans(1);\n        for (int\
    \ i = 0; i < n; ++i) {\n            int nonzero = -1;\n            for (int j\
    \ = i; j < n; ++j) {\n                if (a[j][i] != T(0)) {\n               \
    \     nonzero = j;\n                    break;\n                }\n          \
    \  }\n            if (nonzero == -1) {\n                return T(0);\n       \
    \     }\n            if (nonzero != i) {\n                std::swap(a[i], a[nonzero]);\n\
    \                ans = -ans;\n            }\n            ans *= a[i][i];\n   \
    \         {\n                const T inv = T(1) / T(a[i][i]);\n              \
    \  for (int j = i; j < n; ++j) {\n                    a[i][j] *= inv;\n      \
    \          }\n            }\n            for (int j = i + 1; j < n; ++j) {\n \
    \               const T tmp = a[j][i];\n                for (int k = i; k < n;\
    \ ++k) {\n                    a[j][k] -= tmp * a[i][k];\n                }\n \
    \           }\n        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/matrix.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/matrix_product.test.cpp
  - algebra/test/matrix_det.test.cpp
  - test/library_checker/matrix_product.test.cpp
  - test/library_checker/matrix_det.test.cpp
documentation_of: algebra/matrix.hpp
layout: document
redirect_from:
- /library/algebra/matrix.hpp
- /library/algebra/matrix.hpp.html
title: algebra/matrix.hpp
---
