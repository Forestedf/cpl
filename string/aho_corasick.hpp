#pragma once
#include <queue>

#include "trie.hpp"

std::vector<std::size_t> aho_corasick(const Trie &trie) {
    std::queue<std::size_t> que;
    std::vector<std::size_t> fail(trie.size(), 0);
    for (std::size_t i = 0; i < 26; ++i) {
        if (trie[0][i] != Trie::none) {
            fail[trie[0][i]] = 0;
            que.push(trie[0][i]);
        }
    }
    while (!que.empty()) {
        std::size_t v = que.front();
        que.pop();
        for (std::size_t i = 0; i < 26; ++i) {
            if (trie[v][i] == Trie::none) {
                continue;
            }
            std::size_t cur = fail[v];
            while (cur != 0 && trie[cur][i] == Trie::none) {
                cur = fail[cur];
            }
            if (trie[cur][i] == Trie::none) {
                fail[trie[v][i]] = 0;
            } else {
                fail[trie[v][i]] = trie[cur][i];
            }
            que.push(trie[v][i]);
        }
    }
    return fail;
}