---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/eertree.hpp\"\n\n#include <vector>\n#include <array>\n\
    #include <algorithm>\n#include <utility>\n#include <cassert>\n\ntemplate <int\
    \ SIGMA = 26>\nclass Eertree {\n    std::vector<int> seq;\n    std::vector<std::pair<int,\
    \ int>> range;\n    std::vector<int> suf_link;\n    std::vector<std::array<int,\
    \ SIGMA>> ext;\n    std::vector<int> freq;\n    int longest_suffix;\n    \npublic:\n\
    \    Eertree() : seq(), range(2), suf_link(2), ext(2), freq(2), longest_suffix(1)\
    \ {\n        range[0] = std::pair<int, int>(0, -1);\n        suf_link[0] = -1;\n\
    \        std::fill(ext[0].begin(), ext[0].end(), -1);\n        freq[0] = 0;\n\
    \        range[1] = std::pair<int, int>(0, 0);\n        suf_link[1] = 0;\n   \
    \     std::fill(ext[1].begin(), ext[1].end(), -1);\n        freq[1] = 0;\n   \
    \ }\n    \n    void reserve(int n) {\n        seq.reserve(n);\n    }\n    \n \
    \   // amortized O(SIGMA)\n    bool push(int c) {\n        assert(c < SIGMA);\n\
    \        seq.push_back(c);\n        int cur = longest_suffix;\n        while (true)\
    \ {\n            bool is_palindrome = false;\n            {\n                int\
    \ len = range[cur].second - range[cur].first;\n                is_palindrome =\
    \ ((int) seq.size() >= len + 2 && seq[(int) seq.size() - len - 2] == c);\n   \
    \         }\n            if (is_palindrome) {\n                if (ext[cur][c]\
    \ != -1) {\n                    ++freq[ext[cur][c]];\n                    longest_suffix\
    \ = ext[cur][c];\n                    return false;\n                }\n     \
    \           break;\n            }\n            cur = suf_link[cur];\n        }\n\
    \        int this_node = (int) range.size();\n        ext[cur][c] = this_node;\n\
    \        {\n            int len = range[cur].second - range[cur].first + 2;\n\
    \            range.emplace_back((int) seq.size() - len, (int) seq.size());\n \
    \       }\n        ext.emplace_back(std::array<int, SIGMA>());\n        std::fill(ext.back().begin(),\
    \ ext.back().end(), -1);\n        freq.push_back(1);\n        longest_suffix =\
    \ this_node;\n        if (range[this_node].second - range[this_node].first ==\
    \ 1) {\n            suf_link.push_back(1);\n            return true;\n       \
    \ }\n        cur = suf_link[cur];\n        while (true) {\n            bool is_palindrome\
    \ = false;\n            {\n                int len = range[cur].second - range[cur].first;\n\
    \                is_palindrome = ((int) seq.size() >= len + 2 && seq[(int) seq.size()\
    \ - len - 2] == c);\n            }\n            if (is_palindrome && ext[cur][c]\
    \ != -1) {\n                suf_link.push_back(ext[cur][c]);\n               \
    \ return true;\n            }\n            cur = suf_link[cur];\n        }\n \
    \       assert(false);\n    }\n    \n    int num_palindromes() const {\n     \
    \   return (int) range.size() - 2;\n    }\n    \n    const std::pair<int, int>\
    \ &operator[](int i) const {\n        return range[i + 2];\n    }\n    \n    std::vector<std::pair<int,\
    \ int>> palindromes() const {\n        return std::vector<std::pair<int, int>>(range.begin()\
    \ + 2, range.end());\n    }\n    \n    int suffix_link(int i) const {\n      \
    \  return suf_link[i + 2] - 2;\n    }\n    \n    // O(|S|)\n    std::vector<int>\
    \ frequencies() const {\n        std::vector<int> ret(freq.size() - 2, 0);\n \
    \       for (int i = (int) freq.size() - 1; i >= 2; --i) {\n            ret[i\
    \ - 2] += freq[i];\n            if (suf_link[i] >= 2) {\n                ret[suf_link[i]\
    \ - 2] += ret[i - 2];\n            }\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <vector>\n#include <array>\n#include <algorithm>\n\
    #include <utility>\n#include <cassert>\n\ntemplate <int SIGMA = 26>\nclass Eertree\
    \ {\n    std::vector<int> seq;\n    std::vector<std::pair<int, int>> range;\n\
    \    std::vector<int> suf_link;\n    std::vector<std::array<int, SIGMA>> ext;\n\
    \    std::vector<int> freq;\n    int longest_suffix;\n    \npublic:\n    Eertree()\
    \ : seq(), range(2), suf_link(2), ext(2), freq(2), longest_suffix(1) {\n     \
    \   range[0] = std::pair<int, int>(0, -1);\n        suf_link[0] = -1;\n      \
    \  std::fill(ext[0].begin(), ext[0].end(), -1);\n        freq[0] = 0;\n      \
    \  range[1] = std::pair<int, int>(0, 0);\n        suf_link[1] = 0;\n        std::fill(ext[1].begin(),\
    \ ext[1].end(), -1);\n        freq[1] = 0;\n    }\n    \n    void reserve(int\
    \ n) {\n        seq.reserve(n);\n    }\n    \n    // amortized O(SIGMA)\n    bool\
    \ push(int c) {\n        assert(c < SIGMA);\n        seq.push_back(c);\n     \
    \   int cur = longest_suffix;\n        while (true) {\n            bool is_palindrome\
    \ = false;\n            {\n                int len = range[cur].second - range[cur].first;\n\
    \                is_palindrome = ((int) seq.size() >= len + 2 && seq[(int) seq.size()\
    \ - len - 2] == c);\n            }\n            if (is_palindrome) {\n       \
    \         if (ext[cur][c] != -1) {\n                    ++freq[ext[cur][c]];\n\
    \                    longest_suffix = ext[cur][c];\n                    return\
    \ false;\n                }\n                break;\n            }\n         \
    \   cur = suf_link[cur];\n        }\n        int this_node = (int) range.size();\n\
    \        ext[cur][c] = this_node;\n        {\n            int len = range[cur].second\
    \ - range[cur].first + 2;\n            range.emplace_back((int) seq.size() - len,\
    \ (int) seq.size());\n        }\n        ext.emplace_back(std::array<int, SIGMA>());\n\
    \        std::fill(ext.back().begin(), ext.back().end(), -1);\n        freq.push_back(1);\n\
    \        longest_suffix = this_node;\n        if (range[this_node].second - range[this_node].first\
    \ == 1) {\n            suf_link.push_back(1);\n            return true;\n    \
    \    }\n        cur = suf_link[cur];\n        while (true) {\n            bool\
    \ is_palindrome = false;\n            {\n                int len = range[cur].second\
    \ - range[cur].first;\n                is_palindrome = ((int) seq.size() >= len\
    \ + 2 && seq[(int) seq.size() - len - 2] == c);\n            }\n            if\
    \ (is_palindrome && ext[cur][c] != -1) {\n                suf_link.push_back(ext[cur][c]);\n\
    \                return true;\n            }\n            cur = suf_link[cur];\n\
    \        }\n        assert(false);\n    }\n    \n    int num_palindromes() const\
    \ {\n        return (int) range.size() - 2;\n    }\n    \n    const std::pair<int,\
    \ int> &operator[](int i) const {\n        return range[i + 2];\n    }\n    \n\
    \    std::vector<std::pair<int, int>> palindromes() const {\n        return std::vector<std::pair<int,\
    \ int>>(range.begin() + 2, range.end());\n    }\n    \n    int suffix_link(int\
    \ i) const {\n        return suf_link[i + 2] - 2;\n    }\n    \n    // O(|S|)\n\
    \    std::vector<int> frequencies() const {\n        std::vector<int> ret(freq.size()\
    \ - 2, 0);\n        for (int i = (int) freq.size() - 1; i >= 2; --i) {\n     \
    \       ret[i - 2] += freq[i];\n            if (suf_link[i] >= 2) {\n        \
    \        ret[suf_link[i] - 2] += ret[i - 2];\n            }\n        }\n     \
    \   return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/eertree.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/eertree.hpp
layout: document
redirect_from:
- /library/string/eertree.hpp
- /library/string/eertree.hpp.html
title: string/eertree.hpp
---
