#pragma once

#include <array>
#include <vector>

#include "mod_int.hpp"

template <unsigned mod>
class NumberTheoreticTransform {
    static constexpr int calc_ex() {
        unsigned m = mod - 1;
        int ret = 0;
        while (!(m & 1)) {
            m >>= 1;
            ++ret;
        }
        return ret;
    }

    static constexpr int max_ex = calc_ex();

    std::array<ModInt<mod>, max_ex + 1> root;
    std::array<ModInt<mod>, max_ex + 1> inv_root;

    inline int ctz(int n) const {
        return __builtin_ctz(n);
    }

public:
    void dft(std::vector<ModInt<mod>> &a) const {
        int n = (int) a.size();
        int ex = ctz(n);
        int m = n;
        while (m > 1) {
            for (int s = 0; s < n; s += m) {
                auto z = ModInt<mod>::raw(1);
                for (int i = 0; i < m >> 1; ++i) {
                    auto x = a[s + i];
                    auto y = a[s + i + m / 2];
                    a[s + i] = x + y;
                    a[s + i + m / 2] = (x - y) * z;
                    z *= root[ex];
                }
            }
            m >>= 1;
            --ex;
        }
    }

    void idft(std::vector<ModInt<mod>> &a) const {
        int n = (int) a.size();
        int m = 2;
        int ex = 1;
        while (m <= n) {
            for (int s = 0; s < n; s += m) {
                auto z = ModInt<mod>::raw(1);
                for (int i = 0; i < m / 2; ++i) {
                    auto x = a[s + i];
                    auto y = a[s + i + m / 2] * z;
                    a[s + i] = x + y;
                    a[s + i + m / 2] = x - y;
                    z *= inv_root[ex];
                }
            }
            m <<= 1;
            ++ex;
        }
        ModInt<mod> inv = ModInt<mod>::raw((unsigned) a.size()).inv();
        for (ModInt<mod> &ele : a)
            ele *= inv;
    }

    constexpr NumberTheoreticTransform() : root(), inv_root() {
        ModInt<mod> g =
            ModInt<mod>::raw(primitive_root<mod>()).pow((mod - 1) >> max_ex);
        root[max_ex] = g;
        inv_root[max_ex] = g.inv();
        for (int i = max_ex; i > 0; --i) {
            root[i - 1] = root[i] * root[i];
            inv_root[i - 1] = inv_root[i] * inv_root[i];
        }
    }

    std::vector<ModInt<mod>> multiply(
        std::vector<ModInt<mod>> a,
        std::vector<ModInt<mod>> b) const {
        if (a.empty() || b.empty())
            return std::vector<ModInt<mod>>();
        int siz = 1;
        int ex = 0;
        int s = (int) (a.size() + b.size());
        while (siz < s) {
            siz <<= 1;
            ++ex;
        }
        a.resize(siz, ModInt<mod>());
        b.resize(siz, ModInt<mod>());
        dft(a);
        dft(b);
        for (int i = 0; i < siz; ++i) {
            a[i] *= b[i];
        }
        idft(a);
        a.resize(s - 1);
        return a;
    }
};

template <unsigned mod>
class NTTMul {
    static constexpr NumberTheoreticTransform<mod> ntt = NumberTheoreticTransform<mod>();

public:
    static void dft(std::vector<ModInt<mod>> &a) {
        ntt.dft(a);
    }

    static void idft(std::vector<ModInt<mod>> &a) {
        ntt.idft(a);
    }

    static std::vector<ModInt<mod>> mul(
        std::vector<ModInt<mod>> lhs,
        std::vector<ModInt<mod>> rhs) {
        return ntt.multiply(std::move(lhs), std::move(rhs));
    }
};

