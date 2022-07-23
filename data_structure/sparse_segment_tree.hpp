#pragma once

#include <cassert>

template <typename Monoid>
class SparseSegmentTree {
public:
    using Value = typename Monoid::Value;
    using Index = long long;
    
private:
    struct Node {
        Node *lft;
        Node *rgt;
        Value prod;
        
        Node(Value v) : lft(nullptr), rgt(nullptr), prod(v) {}
        
#ifdef LOCAL
        ~Node() {
            if (lft) {
                delete lft;
            }
            if (rgt) {
                delete rgt;
            }
        }
#endif
        
        void update_prod() {
            if (!lft && !rgt) {
                prod = Monoid::id();
            } else if (!lft) {
                prod = rgt->prod;
            } else if (!rgt) {
                prod = lft->prod;
            } else {
                prod = Monoid::op(lft->prod, rgt->prod);
            }
        }
    };
    
    static Node *update(Node *cur, Index curl, Index curr, Index upd, Value v) {
        if (!cur) {
            cur = new Node(Monoid::id());
        }
        if (curr - curl == 1) {
            cur->prod = v;
        } else {
            Index curm = (curl + curr) / 2;
            if (upd < curm) {
                cur->lft = update(cur->lft, curl, curm, upd, v);
            } else {
                cur->rgt = update(cur->rgt, curm, curr, upd, v);
            }
            cur->update_prod();
        }
        return cur;
    }
    
    static Value prod(Node *cur, Index curl, Index curr, Index qryl, Index qryr) {
        if (!cur || curr <= qryl || qryr <= curl) {
            return Monoid::id();
        }
        if (qryl <= curl && curr <= qryr) {
            return cur->prod;
        }
        Index curm = (curl + curr) / 2;
        Value pl = prod(cur->lft, curl, curm, qryl, qryr);
        Value pr = prod(cur->rgt, curm, curr, qryl, qryr);
        return Monoid::op(pl, pr);
    }
    
    Index lft;
    Index rgt;
    Node *root;
    
public:
    SparseSegmentTree() : lft(0), rgt(1), root(nullptr) {}
    SparseSegmentTree(Index n) : lft(0), rgt(n), root(nullptr) {
        assert(n > 0);
    }
    SparseSegmentTree(Index l, Index r) : lft(l), rgt(r), root(nullptr) {
        assert(l < r);
    }
    
    void update(Index idx, Value v) {
        root = update(root, lft, rgt, idx, v);
    }
    
    Value prod(Index l, Index r) const {
        return prod(root, lft, rgt, l, r);
    }
};