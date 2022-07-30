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
    #include <string>\n#include <vector>\n\nclass Trie {\n    std::vector<std::array<int,\
    \ 26>> trie;\n    std::vector<int> cnt;\n\npublic:\n    static constexpr int none\
    \ = -1;\n\nprivate:\n    int make_node() {\n        int s = trie.size();\n   \
    \     trie.emplace_back(std::array<int, 26>());\n        std::fill(trie[s].begin(),\
    \ trie[s].end(), none);\n        cnt.push_back(0);\n        return s;\n    }\n\
    \npublic:\n    Trie() : trie(), cnt() {\n        make_node();\n    }\n\n    int\
    \ size() const {\n        return (int) trie.size();\n    }\n\n    const std::array<int,\
    \ 26> &operator[](int i) const {\n        return trie[i];\n    }\n\n    int insert(const\
    \ std::string &s) {\n        int cur = 0;\n        for (char c : s) {\n      \
    \      if (trie[cur][c - 'a'] == none) {\n                trie[cur][c - 'a'] =\
    \ make_node();\n            }\n            cur = trie[cur][c - 'a'];\n       \
    \ }\n        return cnt[cur]++;\n    }\n    \n    int find(const std::string &s)\
    \ const {\n        int cur = 0;\n        for (char c : s) {\n            int nxt\
    \ = trie[cur][c - 'a'];\n            if (nxt == none) {\n                return\
    \ none;\n            }\n            cur = nxt;\n        }\n        return cur;\n\
    \    }\n\n    int count(const std::string &s) const {\n        int node = find(s);\n\
    \        if (node == none) {\n            return 0;\n        } else {\n      \
    \      return cnt[node];\n        }\n    }\n\n    int cnt_node(int i) const {\n\
    \        return cnt[i];\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <string>\n\
    #include <vector>\n\nclass Trie {\n    std::vector<std::array<int, 26>> trie;\n\
    \    std::vector<int> cnt;\n\npublic:\n    static constexpr int none = -1;\n\n\
    private:\n    int make_node() {\n        int s = trie.size();\n        trie.emplace_back(std::array<int,\
    \ 26>());\n        std::fill(trie[s].begin(), trie[s].end(), none);\n        cnt.push_back(0);\n\
    \        return s;\n    }\n\npublic:\n    Trie() : trie(), cnt() {\n        make_node();\n\
    \    }\n\n    int size() const {\n        return (int) trie.size();\n    }\n\n\
    \    const std::array<int, 26> &operator[](int i) const {\n        return trie[i];\n\
    \    }\n\n    int insert(const std::string &s) {\n        int cur = 0;\n     \
    \   for (char c : s) {\n            if (trie[cur][c - 'a'] == none) {\n      \
    \          trie[cur][c - 'a'] = make_node();\n            }\n            cur =\
    \ trie[cur][c - 'a'];\n        }\n        return cnt[cur]++;\n    }\n    \n  \
    \  int find(const std::string &s) const {\n        int cur = 0;\n        for (char\
    \ c : s) {\n            int nxt = trie[cur][c - 'a'];\n            if (nxt ==\
    \ none) {\n                return none;\n            }\n            cur = nxt;\n\
    \        }\n        return cur;\n    }\n\n    int count(const std::string &s)\
    \ const {\n        int node = find(s);\n        if (node == none) {\n        \
    \    return 0;\n        } else {\n            return cnt[node];\n        }\n \
    \   }\n\n    int cnt_node(int i) const {\n        return cnt[i];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho_corasick.hpp
  timestamp: '2022-07-30 11:55:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
