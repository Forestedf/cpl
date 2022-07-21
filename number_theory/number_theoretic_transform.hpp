#pragma once

#include <array>
#include <vector>

#include "mod_int.hpp"
#include "../template/bitop.hpp"

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
    std::array<ModInt<mod>, max_ex + 2> inc;
    std::array<ModInt<mod>, max_ex + 2> inv_inc;

public:
    void dft(std::vector<ModInt<mod>> &a) const {
        int n = (int) a.size();
        int ex = ctz(n);
        for (int i = 0; i < ex; ++i) {
            int pr = 1 << (ex - 1 - i);
            int len = 1 << i;
            ModInt<mod> zeta(1);
            for (int j = 0; j < len; ++j) {
                int offset = j << (ex - i);
                for (int k = 0; k < pr; ++k) {
                    ModInt<mod> l = a[offset + k];
                    ModInt<mod> r = a[offset + k + pr] * zeta;
                    a[offset + k] = l + r;
                    a[offset + k + pr] = l - r;
                }
                zeta *= inc[ctz(~j)];
            }
        }
    }

    void idft(std::vector<ModInt<mod>> &a) const {
        int n = (int) a.size();
        int ex = ctz(n);
        for (int i = ex - 1; i >= 0; --i) {
            int pr = 1 << (ex - 1 - i);
            int len = 1 << i;
            ModInt<mod> zeta(1);
            for (int j = 0; j < len; ++j) {
                int offset = j << (ex - i);
                for (int k = 0; k < pr; ++k) {
                    ModInt<mod> l = a[offset + k];
                    ModInt<mod> r = a[offset + k + pr];
                    a[offset + k] = l + r;
                    a[offset + k + pr] = (l - r) * zeta;
                }
                zeta *= inv_inc[ctz(~j)];
            }
        }
        ModInt<mod> inv = ModInt<mod>::raw((unsigned) a.size()).inv();
        for (ModInt<mod> &ele : a) {
            ele *= inv;
        }
    }

    constexpr NumberTheoreticTransform() : root(), inv_root() {
        ModInt<mod> g = ModInt<mod>::raw(primitive_root<mod>()).pow((mod - 1) >> max_ex);
        root[max_ex] = g;
        inv_root[max_ex] = g.inv();
        for (int i = max_ex; i > 0; --i) {
            root[i - 1] = root[i] * root[i];
            inv_root[i - 1] = inv_root[i] * inv_root[i];
        }
        ModInt<mod> prod(1);
        for (int i = 2; i <= max_ex; ++i) {
            inc[i - 2] = root[i] * prod;
            prod *= inv_root[i];
        }
        prod = ModInt<mod>(1);
        for (int i = 2; i <= max_ex; ++i) {
            inv_inc[i - 2] = inv_root[i] * prod;
            prod *= root[i];
        }
    }

    std::vector<ModInt<mod>> multiply(
        std::vector<ModInt<mod>> a,
        std::vector<ModInt<mod>> b) const {
        if (a.empty() || b.empty())
            return std::vector<ModInt<mod>>();
        int siz = 1;
        int s = (int) (a.size() + b.size());
        while (siz < s) {
            siz <<= 1;
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

