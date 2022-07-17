#pragma once

#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point st;
    
public:
    Timer() : st(std::chrono::high_resolution_clock::now()) {}
    
    void reset() {
        st = std::chrono::high_resolution_clock::now();
    }
    
    int elapsed() {
        auto ed = std::chrono::high_resolution_clock::now();
        return (int) std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count();
    }
};