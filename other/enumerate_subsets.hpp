#pragma once

struct EnumerateSubset {
    struct Iterator {
        unsigned st;
        unsigned cur;
        Iterator &operator++() {
            if (cur == 0) {
                cur = ~(0u);
            } else {
                cur = (cur - 1) & st;
            }
            return *this;
        }
        unsigned operator*() const {
            return cur;
            //return st ^ cur;
        }
        friend bool operator!=(const EnumerateSubset::Iterator &lhs, const EnumerateSubset::Iterator &rhs) {
            return lhs.cur != rhs.cur;
        }
    };
    
    unsigned st;
    EnumerateSubset(unsigned s) : st(s) {}
    
    Iterator begin() const {
        return Iterator{st, st};
    }
    Iterator end() const {
        return Iterator{st, ~(0u)};
    }
};