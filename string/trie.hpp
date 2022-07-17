#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Trie {
    std::vector<std::array<std::size_t, 26>> trie;
    std::vector<std::size_t> cnt;

public:
    static constexpr std::size_t none = (std::size_t)-1;

private:
    std::size_t make_node() {
        std::size_t s = trie.size();
        trie.emplace_back(std::array<std::size_t, 26>());
        std::fill(trie[s].begin(), trie[s].end(), none);
        cnt.push_back(0);
        return s;
    }

public:
    Trie() : trie(), cnt() {
        make_node();
    }

    std::size_t size() const {
        return trie.size();
    }

    const std::array<std::size_t, 26> &operator[](std::size_t i) const {
        return trie[i];
    }

    std::size_t insert(const std::string &s) {
        std::size_t cur = 0;
        for (char c : s) {
            if (trie[cur][c - 'a'] == none) {
                trie[cur][c - 'a'] = make_node();
            }
            cur = trie[cur][c - 'a'];
        }
        return cnt[cur]++;
    }

    std::size_t count(const std::string &s) const {
        std::size_t cur = 0;
        for (char c : s) {
            std::size_t nxt = trie[cur][c - 'a'];
            if (nxt == none) {
                return 0;
            }
            cur = nxt;
        }
        return cnt[cur];
    }

    std::size_t cnt_node(std::size_t i) const {
        return cnt[i];
    }
};