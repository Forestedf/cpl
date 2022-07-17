---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/aho_corasick.hpp
    title: string/aho_corasick.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <string>\n#include <vector>\n\nclass Trie {\n    std::vector<std::array<std::size_t,\
    \ 26>> trie;\n    std::vector<std::size_t> cnt;\n\npublic:\n    static constexpr\
    \ std::size_t none = (std::size_t)-1;\n\nprivate:\n    std::size_t make_node()\
    \ {\n        std::size_t s = trie.size();\n        trie.emplace_back(std::array<std::size_t,\
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
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <string>\n\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho_corasick.hpp
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
