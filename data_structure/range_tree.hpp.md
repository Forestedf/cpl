---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/rectangle_sum.test.cpp
    title: data_structure/test/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_tree.hpp\"\n\n#include <algorithm>\n\
    #include <tuple>\n\ntemplate <typename Coordinate, typename CommutativeGroup>\n\
    class RangeTree {\npublic:\n    using Value = typename CommutativeGroup::Value;\n\
    \    \nprivate:\n    struct Node {\n        std::vector<Coordinate> ys;\n    \
    \    std::vector<Value> cum;\n        \n        Value sum(Coordinate yl, Coordinate\
    \ yr) const {\n            int yli = (int) (std::lower_bound(ys.begin(), ys.end(),\
    \ yl) - ys.begin());\n            int yri = (int) (std::lower_bound(ys.begin(),\
    \ ys.end(), yr) - ys.begin());\n            return CommutativeGroup::op(CommutativeGroup::inv(cum[yli]),\
    \ cum[yri]);\n        }\n    };\n    \n    static void dedup(std::vector<Coordinate>\
    \ &xs) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n    static int index(const std::vector<Coordinate>\
    \ &xs, int x) {\n        return (int) (std::lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin());\n    }\n    \n    std::vector<Node> nodes;\n    std::vector<Coordinate>\
    \ xs;\n    \npublic:\n    RangeTree(const std::vector<std::tuple<Coordinate, Coordinate,\
    \ Value>> &pts) : nodes(), xs() {\n        xs.reserve(pts.size());\n        for\
    \ (const auto &[x, _y, _w] : pts) {\n            xs.push_back(x);\n        }\n\
    \        dedup(xs);\n        nodes.resize(xs.size());\n        for (const auto\
    \ &[x, y, _w] : pts) {\n            int xi = index(xs, x);\n            for (;\
    \ xi < (int) xs.size(); xi |= xi + 1) {\n                nodes[xi].ys.push_back(y);\n\
    \            }\n        }\n        for (Node &node : nodes) {\n            dedup(node.ys);\n\
    \            node.cum.resize(node.ys.size() + 1, CommutativeGroup::id());\n  \
    \      }\n        for (const auto &[x, y, w] : pts) {\n            int xi = index(xs,\
    \ x);\n            for (; xi < (int) xs.size(); xi |= xi + 1) {\n            \
    \    int yi = index(nodes[xi].ys, y);\n                nodes[xi].cum[yi + 1] =\
    \ CommutativeGroup::op(nodes[xi].cum[yi + 1], w);\n            }\n        }\n\
    \        for (Node &node : nodes) {\n            for (int i = 1; i < (int) node.cum.size();\
    \ ++i) {\n                node.cum[i] = CommutativeGroup::op(node.cum[i - 1],\
    \ node.cum[i]);\n            }\n        }\n    }\n    \n    Value sum(Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        int xri = index(xs, xr);\n\
    \        Value s = CommutativeGroup::id();\n        for (; xri > 0; xri &= xri\
    \ - 1) {\n            s = CommutativeGroup::op(s, nodes[xri - 1].sum(yl, yr));\n\
    \        }\n        return s;\n    }\n    \n    Value sum(Coordinate xl, Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        Value l = sum(xl, yl, yr),\
    \ r = sum(xr, yl, yr);\n        return CommutativeGroup::op(r, CommutativeGroup::inv(l));\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <tuple>\n\ntemplate <typename\
    \ Coordinate, typename CommutativeGroup>\nclass RangeTree {\npublic:\n    using\
    \ Value = typename CommutativeGroup::Value;\n    \nprivate:\n    struct Node {\n\
    \        std::vector<Coordinate> ys;\n        std::vector<Value> cum;\n      \
    \  \n        Value sum(Coordinate yl, Coordinate yr) const {\n            int\
    \ yli = (int) (std::lower_bound(ys.begin(), ys.end(), yl) - ys.begin());\n   \
    \         int yri = (int) (std::lower_bound(ys.begin(), ys.end(), yr) - ys.begin());\n\
    \            return CommutativeGroup::op(CommutativeGroup::inv(cum[yli]), cum[yri]);\n\
    \        }\n    };\n    \n    static void dedup(std::vector<Coordinate> &xs) {\n\
    \        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n    static int index(const std::vector<Coordinate>\
    \ &xs, int x) {\n        return (int) (std::lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin());\n    }\n    \n    std::vector<Node> nodes;\n    std::vector<Coordinate>\
    \ xs;\n    \npublic:\n    RangeTree(const std::vector<std::tuple<Coordinate, Coordinate,\
    \ Value>> &pts) : nodes(), xs() {\n        xs.reserve(pts.size());\n        for\
    \ (const auto &[x, _y, _w] : pts) {\n            xs.push_back(x);\n        }\n\
    \        dedup(xs);\n        nodes.resize(xs.size());\n        for (const auto\
    \ &[x, y, _w] : pts) {\n            int xi = index(xs, x);\n            for (;\
    \ xi < (int) xs.size(); xi |= xi + 1) {\n                nodes[xi].ys.push_back(y);\n\
    \            }\n        }\n        for (Node &node : nodes) {\n            dedup(node.ys);\n\
    \            node.cum.resize(node.ys.size() + 1, CommutativeGroup::id());\n  \
    \      }\n        for (const auto &[x, y, w] : pts) {\n            int xi = index(xs,\
    \ x);\n            for (; xi < (int) xs.size(); xi |= xi + 1) {\n            \
    \    int yi = index(nodes[xi].ys, y);\n                nodes[xi].cum[yi + 1] =\
    \ CommutativeGroup::op(nodes[xi].cum[yi + 1], w);\n            }\n        }\n\
    \        for (Node &node : nodes) {\n            for (int i = 1; i < (int) node.cum.size();\
    \ ++i) {\n                node.cum[i] = CommutativeGroup::op(node.cum[i - 1],\
    \ node.cum[i]);\n            }\n        }\n    }\n    \n    Value sum(Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        int xri = index(xs, xr);\n\
    \        Value s = CommutativeGroup::id();\n        for (; xri > 0; xri &= xri\
    \ - 1) {\n            s = CommutativeGroup::op(s, nodes[xri - 1].sum(yl, yr));\n\
    \        }\n        return s;\n    }\n    \n    Value sum(Coordinate xl, Coordinate\
    \ xr, Coordinate yl, Coordinate yr) const {\n        Value l = sum(xl, yl, yr),\
    \ r = sum(xr, yl, yr);\n        return CommutativeGroup::op(r, CommutativeGroup::inv(l));\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/range_tree.hpp
  requiredBy: []
  timestamp: '2022-07-31 17:23:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/rectangle_sum.test.cpp
documentation_of: data_structure/range_tree.hpp
layout: document
redirect_from:
- /library/data_structure/range_tree.hpp
- /library/data_structure/range_tree.hpp.html
title: data_structure/range_tree.hpp
---