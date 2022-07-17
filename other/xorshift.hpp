#pragma once

class XorShift64 {
    unsigned long long x;
    
public:
    XorShift64(unsigned long long seed) : x((seed + 14213124131ull) ^ 103920984124ull) {}
    
    unsigned long long operator()() {
        x = x ^ (x << 13);
        x = x ^ (x >> 7);
        x = x ^ (x << 17);
        return x;
    }
    
    template <typename T>
    T uniform(T mn, T mx) {
        return mn + (T) ((*this)() % (mx - mn + 1));
    }
    
    double as_f64() {
        return (double) (*this)() / ~0ull;
    }
};