#pragma once

#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <cassert>

template <int SIGMA = 26>
class Eertree {
    std::vector<int> seq;
    std::vector<std::pair<int, int>> range;
    std::vector<int> suf_link;
    std::vector<std::array<int, SIGMA>> ext;
    std::vector<int> freq;
    int longest_suffix;
    
public:
    Eertree() : seq(), range(2), suf_link(2), ext(2), freq(2), longest_suffix(1) {
        range[0] = std::pair<int, int>(0, -1);
        suf_link[0] = -1;
        std::fill(ext[0].begin(), ext[0].end(), -1);
        freq[0] = 0;
        range[1] = std::pair<int, int>(0, 0);
        suf_link[1] = 0;
        std::fill(ext[1].begin(), ext[1].end(), -1);
        freq[1] = 0;
    }
    
    void reserve(int n) {
        seq.reserve(n);
    }
    
    // amortized O(SIGMA)
    bool push(int c) {
        assert(c < SIGMA);
        seq.push_back(c);
        int cur = longest_suffix;
        while (true) {
            bool is_palindrome = false;
            {
                int len = range[cur].second - range[cur].first;
                is_palindrome = ((int) seq.size() >= len + 2 && seq[(int) seq.size() - len - 2] == c);
            }
            if (is_palindrome) {
                if (ext[cur][c] != -1) {
                    ++freq[ext[cur][c]];
                    longest_suffix = ext[cur][c];
                    return false;
                }
                break;
            }
            cur = suf_link[cur];
        }
        int this_node = (int) range.size();
        ext[cur][c] = this_node;
        {
            int len = range[cur].second - range[cur].first + 2;
            range.emplace_back((int) seq.size() - len, (int) seq.size());
        }
        ext.emplace_back(std::array<int, SIGMA>());
        std::fill(ext.back().begin(), ext.back().end(), -1);
        freq.push_back(1);
        longest_suffix = this_node;
        if (range[this_node].second - range[this_node].first == 1) {
            suf_link.push_back(1);
            return true;
        }
        cur = suf_link[cur];
        while (true) {
            bool is_palindrome = false;
            {
                int len = range[cur].second - range[cur].first;
                is_palindrome = ((int) seq.size() >= len + 2 && seq[(int) seq.size() - len - 2] == c);
            }
            if (is_palindrome && ext[cur][c] != -1) {
                suf_link.push_back(ext[cur][c]);
                return true;
            }
            cur = suf_link[cur];
        }
        assert(false);
    }
    
    int num_palindromes() const {
        return (int) range.size() - 2;
    }
    
    const std::pair<int, int> &operator[](int i) const {
        return range[i + 2];
    }
    
    std::vector<std::pair<int, int>> palindromes() const {
        return std::vector<std::pair<int, int>>(range.begin() + 2, range.end());
    }
    
    int suffix_link(int i) const {
        return suf_link[i + 2] - 2;
    }
    
    // O(|S|)
    std::vector<int> frequencies() const {
        std::vector<int> ret(freq.size() - 2, 0);
        for (int i = (int) freq.size() - 1; i >= 2; --i) {
            ret[i - 2] += freq[i];
            if (suf_link[i] >= 2) {
                ret[suf_link[i] - 2] += ret[i - 2];
            }
        }
        return ret;
    }
};