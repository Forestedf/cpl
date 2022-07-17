#pragma once

#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

template <typename T, typename Mul>
class Polynomial {
    std::vector<T> coeff;
    
public:
    using This = Polynomial<T, Mul>;
    
    Polynomial() : coeff() {}
    Polynomial(int n) : coeff(n, T(0)) {}
    Polynomial(std::vector<T> c) : coeff(std::move(c)) {}
    
    const std::vector<T> &vec() const {
        return coeff;
    }
    
    int size() const {
        return (int) coeff.size();
    }
    
    const T &operator[](int idx) const {
        return coeff[idx];
    }
    T &operator[](int idx) {
        return coeff[idx];
    }
    
    T at(int idx) const {
        if (idx < size()) {
            return coeff[idx];
        } else {
            return T(0);
        }
    }
    
    void pre_(int n) {
        assert(n >= 0);
        coeff.resize(n, T(0));
    }
    This pre(int n) const {
        This tmp(*this);
        tmp.pre_(n);
        return tmp;
    }
    
    T operator()(const T &x) const {
        T p(1), sum(0);
        for (const T &ele : coeff) {
            sum += p * ele;
            p *= x;
        }
        return sum;
    }
    
    This &operator+=(const This &rhs) {
        if (coeff.size() < rhs.coeff.size()) {
            coeff.resize(rhs.coeff.size(), T(0));
        }
        for (int i = 0; i < (int) rhs.coeff.size(); ++i) {
            coeff[i] += rhs.coeff[i];
        }
        return *this;
    }
    friend This operator+(This lhs, const This &rhs) {
        lhs += rhs;
        return lhs;
    }
    This &operator-=(const This &rhs) {
        if (coeff.size() < rhs.coeff.size()) {
            coeff.resize(rhs.coeff.size(), T(0));
        }
        for (int i = 0; i < (int) rhs.coeff.size(); ++i) {
            coeff[i] -= rhs.coeff[i];
        }
        return *this;
    }
    friend This operator-(This lhs, const This &rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    This &operator*=(This rhs) {
        coeff = Mul::mul(std::move(coeff), std::move(rhs.coeff));
        return *this;
    }
    friend This operator*(This lhs, This rhs) {
        return This(Mul::mul(std::move(lhs.coeff), std::move(rhs.coeff)));
    }
    
    This diff() const {
        if (coeff.empty()) {
            return This();
        }
        std::vector<T> c(coeff.size() - 1);
        for (int i = 0; i < (int) c.size(); ++i) {
            c[i] = T(i + 1) * coeff[i + 1];
        }
        return This(c);
    }
    This integ() const {
        std::vector<T> c(coeff.size() + 1, T(0));
        for (int i = 0; i < (int) coeff.size(); ++i) {
            c[i + 1] = coeff[i] / T(i + 1);
        }
        return This(c);
    }
};