---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/trie.hpp
    title: string/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.hpp\"\n#include <queue>\n\n#line 2 \"\
    string/trie.hpp\"\n#include <algorithm>\n#include <array>\n#include <string>\n\
    #include <vector>\n\nclass Trie {\n    std::vector<std::array<std::size_t, 26>>\
    \ trie;\n    std::vector<std::size_t> cnt;\n\npublic:\n    static constexpr std::size_t\
    \ none = (std::size_t)-1;\n\nprivate:\n    std::size_t make_node() {\n       \
    \ std::size_t s = trie.size();\n        trie.emplace_back(std::array<std::size_t,\
    \ 26>());\n        std::fill(trie[s].begin(), trie[s].end(), none);\n        cnt.push_back(0);\n\
    \        return s;\n    }\n\npublic:\n    Trie() : trie(), cnt() {\n        make_node();\n\
    \    }\n\n    std::size_t size() const {\n        return trie.size();\n    }\n\
    \n    const std::array<std::size_t, 26> &operator[](std::size_t i) const {\n \
    \       return trie[i];\n    }\n\n    std::size_t insert(const std::string &s)\
    \ {\n        std::size_t cur = 0;\n        for (char c : s) {\n            if\
    \ (trie[cur][c - 'a'] == none) {\n                trie[cur][c - 'a'] = make_node();\n\
    \            }\n            cur = trie[cur][c - 'a'];\n        }\n        return\
    \ cnt[cur]++;\n    }\n\n    std::size_t count(const std::string &s) const {\n\
    \        std::size_t cur = 0;\n        for (char c : s) {\n            std::size_t\
    \ nxt = trie[cur][c - 'a'];\n            if (nxt == none) {\n                return\
    \ 0;\n            }\n            cur = nxt;\n        }\n        return cnt[cur];\n\
    \    }\n\n    std::size_t cnt_node(std::size_t i) const {\n        return cnt[i];\n\
    \    }\n};\n#line 5 \"string/aho_corasick.hpp\"\n\nstd::vector<std::size_t> aho_corasick(const\
    \ Trie &trie) {\n    std::queue<std::size_t> que;\n    std::vector<std::size_t>\
    \ fail(trie.size(), 0);\n    for (std::size_t i = 0; i < 26; ++i) {\n        if\
    \ (trie[0][i] != Trie::none) {\n            fail[trie[0][i]] = 0;\n          \
    \  que.push(trie[0][i]);\n        }\n    }\n    while (!que.empty()) {\n     \
    \   std::size_t v = que.front();\n        que.pop();\n        for (std::size_t\
    \ i = 0; i < 26; ++i) {\n            if (trie[v][i] == Trie::none) {\n       \
    \         continue;\n            }\n            std::size_t cur = fail[v];\n \
    \           while (cur != 0 && trie[cur][i] == Trie::none) {\n               \
    \ cur = fail[cur];\n            }\n            if (trie[cur][i] == Trie::none)\
    \ {\n                fail[trie[v][i]] = 0;\n            } else {\n           \
    \     fail[trie[v][i]] = trie[cur][i];\n            }\n            que.push(trie[v][i]);\n\
    \        }\n    }\n    return fail;\n}\n"
  code: "#pragma once\n#include <queue>\n\n#include \"trie.hpp\"\n\nstd::vector<std::size_t>\
    \ aho_corasick(const Trie &trie) {\n    std::queue<std::size_t> que;\n    std::vector<std::size_t>\
    \ fail(trie.size(), 0);\n    for (std::size_t i = 0; i < 26; ++i) {\n        if\
    \ (trie[0][i] != Trie::none) {\n            fail[trie[0][i]] = 0;\n          \
    \  que.push(trie[0][i]);\n        }\n    }\n    while (!que.empty()) {\n     \
    \   std::size_t v = que.front();\n        que.pop();\n        for (std::size_t\
    \ i = 0; i < 26; ++i) {\n            if (trie[v][i] == Trie::none) {\n       \
    \         continue;\n            }\n            std::size_t cur = fail[v];\n \
    \           while (cur != 0 && trie[cur][i] == Trie::none) {\n               \
    \ cur = fail[cur];\n            }\n            if (trie[cur][i] == Trie::none)\
    \ {\n                fail[trie[v][i]] = 0;\n            } else {\n           \
    \     fail[trie[v][i]] = trie[cur][i];\n            }\n            que.push(trie[v][i]);\n\
    \        }\n    }\n    return fail;\n}"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/aho_corasick.hpp
layout: document
redirect_from:
- /library/string/aho_corasick.hpp
- /library/string/aho_corasick.hpp.html
title: string/aho_corasick.hpp
---
