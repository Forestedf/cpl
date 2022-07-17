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
  bundledCode: "#line 2 \"other/convolution_many_times.hpp\"\n\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <cassert>\n\ntemplate <typename\
    \ Seq, typename Conv>\nSeq convolution_many_times(std::vector<Seq> seqs, Conv\
    \ conv) {\n    assert(!seqs.empty());\n    std::queue<Seq> que;\n    for (int\
    \ i = 0; i < (int) seqs.size(); ++i) {\n        que.emplace(std::move(seqs[i]));\n\
    \    }\n    while (que.size() >= 2) {\n        Seq s0 = que.front();\n       \
    \ que.pop();\n        Seq s1 = que.front();\n        que.pop();\n        que.emplace(conv(std::move(s0),\
    \ std::move(s1)));\n    }\n    return que.front();\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <utility>\n\
    #include <cassert>\n\ntemplate <typename Seq, typename Conv>\nSeq convolution_many_times(std::vector<Seq>\
    \ seqs, Conv conv) {\n    assert(!seqs.empty());\n    std::queue<Seq> que;\n \
    \   for (int i = 0; i < (int) seqs.size(); ++i) {\n        que.emplace(std::move(seqs[i]));\n\
    \    }\n    while (que.size() >= 2) {\n        Seq s0 = que.front();\n       \
    \ que.pop();\n        Seq s1 = que.front();\n        que.pop();\n        que.emplace(conv(std::move(s0),\
    \ std::move(s1)));\n    }\n    return que.front();\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/convolution_many_times.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/convolution_many_times.hpp
layout: document
redirect_from:
- /library/other/convolution_many_times.hpp
- /library/other/convolution_many_times.hpp.html
title: other/convolution_many_times.hpp
---
