#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <typename T>
class Matrix {
    std::vector<std::vector<T>> data;
    
public:
    Matrix(int n) : data(n, std::vector<T>(n, T(0))) {}
    Matrix(int h, int w) : data(h, std::vector<T>(w, T(0))) {}
    // must be rectangular
    Matrix(std::vector<std::vector<T>> a) : data(std::move(a)) {}
    
    int height() const {
        return data.size();
    }
    int width() const {
        return data.empty() ? 0 : data[0].size();
    }
    bool is_square() const {
        return height() == width();
    }
    
    const T &operator()(int i, int j) const {
        return data[i][j];
    }
    T &operator()(int i, int j) {
        return data[i][j];
    }
    
    Matrix<T> trans() const {
        const int h = height(), w = width();
        Matrix<T> ret(w, h);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ret.data[j][i] = data[i][j];
            }
        }
        return ret;
    }
    
    Matrix<T> operator+() const {
        return *this;
    }
    Matrix<T> operator-() const {
        const int h = height(), w = width();
        Matrix<T> ret = *this;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ret.data[i][j] = -ret.data[i][j];
            }
        }
        return ret;
    }
    
    Matrix<T> &operator+=(const Matrix<T> &rhs) {
        assert(height() == rhs.height() && width() == rhs.width());
        const int h = height(), w = width();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i][j] += rhs.data[i][j];
            }
        }
        return *this;
    }
    Matrix<T> &operator-=(const Matrix<T> &rhs) {
        assert(height() == rhs.height() && width() == rhs.width());
        const int h = height(), w = width();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i][j] -= rhs.data[i][j];
            }
        }
        return *this;
    }
    friend Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        return lhs += rhs;
    }
    friend Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        return lhs -= rhs;
    }
    
    friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        assert(lhs.width() == rhs.height());
        const int n = lhs.height(), m = rhs.height(), k = rhs.width();
        Matrix<T> ret(n, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < m; ++l) {
                    ret.data[i][j] += lhs.data[i][l] * rhs.data[l][j];
                }
            }
        }
        return ret;
    }
    Matrix<T> &operator*=(const Matrix<T> &rhs) {
        return *this = *this * rhs;
    }
    
    static Matrix<T> e(int n) {
        Matrix<T> mat(n);
        for (int i = 0; i < n; ++i) {
            mat.data[i][i] = T(1);
        }
        return mat;
    }
    
    Matrix<T> pow(unsigned long long t) {
        assert(height() == width());
        Matrix<T> ret = Matrix::e(height());
        Matrix<T> self = *this;
        while (t > 0) {
            if (t % 2 == 1) {
                ret = ret * self;
            }
            self = self * self;
            t /= 2;
        }
        return ret;
    }
    
    T det() const {
        assert(is_square());
        const int n = height();
        std::vector<std::vector<T>> a = data;
        T ans(1);
        for (int i = 0; i < n; ++i) {
            int nonzero = -1;
            for (int j = i; j < n; ++j) {
                if (a[j][i] != T(0)) {
                    nonzero = j;
                    break;
                }
            }
            if (nonzero == -1) {
                return T(0);
            }
            if (nonzero != i) {
                std::swap(a[i], a[nonzero]);
                ans = -ans;
            }
            ans *= a[i][i];
            {
                const T inv = T(1) / T(a[i][i]);
                for (int j = i; j < n; ++j) {
                    a[i][j] *= inv;
                }
            }
            for (int j = i + 1; j < n; ++j) {
                const T tmp = a[j][i];
                for (int k = i; k < n; ++k) {
                    a[j][k] -= tmp * a[i][k];
                }
            }
        }
        return ans;
    }
};