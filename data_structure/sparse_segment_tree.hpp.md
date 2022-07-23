---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/other/sparse_segment_tree.test.cpp
    title: test/other/sparse_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_segment_tree.hpp\"\n\n#include <cassert>\n\
    \ntemplate <typename Monoid>\nclass SparseSegmentTree {\npublic:\n    using Value\
    \ = typename Monoid::Value;\n    using Index = long long;\n    \nprivate:\n  \
    \  struct Node {\n        Node *lft;\n        Node *rgt;\n        Value prod;\n\
    \        \n        Node(Value v) : lft(nullptr), rgt(nullptr), prod(v) {}\n  \
    \      \n#ifdef LOCAL\n        ~Node() {\n            if (lft) {\n           \
    \     delete lft;\n            }\n            if (rgt) {\n                delete\
    \ rgt;\n            }\n        }\n#endif\n        \n        void update_prod()\
    \ {\n            if (!lft && !rgt) {\n                prod = Monoid::id();\n \
    \           } else if (!lft) {\n                prod = rgt->prod;\n          \
    \  } else if (!rgt) {\n                prod = lft->prod;\n            } else {\n\
    \                prod = Monoid::op(lft->prod, rgt->prod);\n            }\n   \
    \     }\n    };\n    \n    static Node *update(Node *cur, Index curl, Index curr,\
    \ Index upd, Value v) {\n        if (!cur) {\n            cur = new Node(Monoid::id());\n\
    \        }\n        if (curr - curl == 1) {\n            cur->prod = v;\n    \
    \    } else {\n            Index curm = (curl + curr) / 2;\n            if (upd\
    \ < curm) {\n                cur->lft = update(cur->lft, curl, curm, upd, v);\n\
    \            } else {\n                cur->rgt = update(cur->rgt, curm, curr,\
    \ upd, v);\n            }\n            cur->update_prod();\n        }\n      \
    \  return cur;\n    }\n    \n    static Value prod(Node *cur, Index curl, Index\
    \ curr, Index qryl, Index qryr) {\n        if (!cur || curr <= qryl || qryr <=\
    \ curl) {\n            return Monoid::id();\n        }\n        if (qryl <= curl\
    \ && curr <= qryr) {\n            return cur->prod;\n        }\n        Index\
    \ curm = (curl + curr) / 2;\n        Value pl = prod(cur->lft, curl, curm, qryl,\
    \ qryr);\n        Value pr = prod(cur->rgt, curm, curr, qryl, qryr);\n       \
    \ return Monoid::op(pl, pr);\n    }\n    \n    Index lft;\n    Index rgt;\n  \
    \  Node *root;\n    \npublic:\n    SparseSegmentTree() : lft(0), rgt(1), root(nullptr)\
    \ {}\n    SparseSegmentTree(Index n) : lft(0), rgt(n), root(nullptr) {\n     \
    \   assert(n > 0);\n    }\n    SparseSegmentTree(Index l, Index r) : lft(l), rgt(r),\
    \ root(nullptr) {\n        assert(l < r);\n    }\n    \n    void update(Index\
    \ idx, Value v) {\n        root = update(root, lft, rgt, idx, v);\n    }\n   \
    \ \n    Value prod(Index l, Index r) const {\n        return prod(root, lft, rgt,\
    \ l, r);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n\ntemplate <typename Monoid>\nclass SparseSegmentTree\
    \ {\npublic:\n    using Value = typename Monoid::Value;\n    using Index = long\
    \ long;\n    \nprivate:\n    struct Node {\n        Node *lft;\n        Node *rgt;\n\
    \        Value prod;\n        \n        Node(Value v) : lft(nullptr), rgt(nullptr),\
    \ prod(v) {}\n        \n#ifdef LOCAL\n        ~Node() {\n            if (lft)\
    \ {\n                delete lft;\n            }\n            if (rgt) {\n    \
    \            delete rgt;\n            }\n        }\n#endif\n        \n       \
    \ void update_prod() {\n            if (!lft && !rgt) {\n                prod\
    \ = Monoid::id();\n            } else if (!lft) {\n                prod = rgt->prod;\n\
    \            } else if (!rgt) {\n                prod = lft->prod;\n         \
    \   } else {\n                prod = Monoid::op(lft->prod, rgt->prod);\n     \
    \       }\n        }\n    };\n    \n    static Node *update(Node *cur, Index curl,\
    \ Index curr, Index upd, Value v) {\n        if (!cur) {\n            cur = new\
    \ Node(Monoid::id());\n        }\n        if (curr - curl == 1) {\n          \
    \  cur->prod = v;\n        } else {\n            Index curm = (curl + curr) /\
    \ 2;\n            if (upd < curm) {\n                cur->lft = update(cur->lft,\
    \ curl, curm, upd, v);\n            } else {\n                cur->rgt = update(cur->rgt,\
    \ curm, curr, upd, v);\n            }\n            cur->update_prod();\n     \
    \   }\n        return cur;\n    }\n    \n    static Value prod(Node *cur, Index\
    \ curl, Index curr, Index qryl, Index qryr) {\n        if (!cur || curr <= qryl\
    \ || qryr <= curl) {\n            return Monoid::id();\n        }\n        if\
    \ (qryl <= curl && curr <= qryr) {\n            return cur->prod;\n        }\n\
    \        Index curm = (curl + curr) / 2;\n        Value pl = prod(cur->lft, curl,\
    \ curm, qryl, qryr);\n        Value pr = prod(cur->rgt, curm, curr, qryl, qryr);\n\
    \        return Monoid::op(pl, pr);\n    }\n    \n    Index lft;\n    Index rgt;\n\
    \    Node *root;\n    \npublic:\n    SparseSegmentTree() : lft(0), rgt(1), root(nullptr)\
    \ {}\n    SparseSegmentTree(Index n) : lft(0), rgt(n), root(nullptr) {\n     \
    \   assert(n > 0);\n    }\n    SparseSegmentTree(Index l, Index r) : lft(l), rgt(r),\
    \ root(nullptr) {\n        assert(l < r);\n    }\n    \n    void update(Index\
    \ idx, Value v) {\n        root = update(root, lft, rgt, idx, v);\n    }\n   \
    \ \n    Value prod(Index l, Index r) const {\n        return prod(root, lft, rgt,\
    \ l, r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-07-23 18:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/other/sparse_segment_tree.test.cpp
documentation_of: data_structure/sparse_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_segment_tree.hpp
- /library/data_structure/sparse_segment_tree.hpp.html
title: data_structure/sparse_segment_tree.hpp
---
