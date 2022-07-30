#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Trie {
    std::vector<std::array<int, 26>> trie;
    std::vector<int> cnt;

public:
    static constexpr int none = -1;

private:
    int make_node() {
        int s = trie.size();
        trie.emplace_back(std::array<int, 26>());
        std::fill(trie[s].begin(), trie[s].end(), none);
        cnt.push_back(0);
        return s;
    }

public:
    Trie() : trie(), cnt() {
        make_node();
    }

    int size() const {
        return (int) trie.size();
    }

    const std::array<int, 26> &operator[](int i) const {
        return trie[i];
    }

    int insert(const std::string &s) {
        int cur = 0;
        for (char c : s) {
            if (trie[cur][c - 'a'] == none) {
                trie[cur][c - 'a'] = make_node();
            }
            cur = trie[cur][c - 'a'];
        }
        return cnt[cur]++;
    }
    
    int find(const std::string &s) const {
        int cur = 0;
        for (char c : s) {
            int nxt = trie[cur][c - 'a'];
            if (nxt == none) {
                return none;
            }
            cur = nxt;
        }
        return cur;
    }

    int count(const std::string &s) const {
        int node = find(s);
        if (node == none) {
            return 0;
        } else {
            return cnt[node];
        }
    }

    int cnt_node(int i) const {
        return cnt[i];
    }
};