---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: polynomial/test/exp_of_formal_power_series_acl.test.cpp
    title: polynomial/test/exp_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/inv_of_formal_power_series_acl.test.cpp
    title: polynomial/test/inv_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/log_of_formal_power_series_acl.test.cpp
    title: polynomial/test/log_of_formal_power_series_acl.test.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/test/pow_of_formal_power_series_acl.test.cpp
    title: polynomial/test/pow_of_formal_power_series_acl.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/with_acl.hpp\"\n\n#include <atcoder/convolution>\n\
    \ntemplate <int mod>\nclass ACLNTT {\npublic:\n    using Mint = atcoder::static_modint<mod>;\n\
    \    \n    static void dft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly(a);\n\
    \    }\n    static void idft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly_inv(a);\n\
    \        Mint inv = Mint::raw(a.size()).inv();\n        for (Mint &ele : a) {\n\
    \            ele *= inv;\n        }\n    }\n    static std::vector<Mint> mul(std::vector<Mint>\
    \ a, std::vector<Mint> b) {\n        return atcoder::convolution(a, b);\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <atcoder/convolution>\n\ntemplate <int mod>\nclass\
    \ ACLNTT {\npublic:\n    using Mint = atcoder::static_modint<mod>;\n    \n   \
    \ static void dft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly(a);\n\
    \    }\n    static void idft(std::vector<Mint> &a) {\n        atcoder::internal::butterfly_inv(a);\n\
    \        Mint inv = Mint::raw(a.size()).inv();\n        for (Mint &ele : a) {\n\
    \            ele *= inv;\n        }\n    }\n    static std::vector<Mint> mul(std::vector<Mint>\
    \ a, std::vector<Mint> b) {\n        return atcoder::convolution(a, b);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/with_acl.hpp
  requiredBy: []
  timestamp: '2022-07-17 14:27:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - polynomial/test/exp_of_formal_power_series_acl.test.cpp
  - polynomial/test/pow_of_formal_power_series_acl.test.cpp
  - polynomial/test/log_of_formal_power_series_acl.test.cpp
  - polynomial/test/inv_of_formal_power_series_acl.test.cpp
documentation_of: polynomial/with_acl.hpp
layout: document
redirect_from:
- /library/polynomial/with_acl.hpp
- /library/polynomial/with_acl.hpp.html
title: polynomial/with_acl.hpp
---
