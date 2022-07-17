#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../graph/two_sat.hpp"

int main() {
    string dummy;
    cin >> dummy >> dummy;
    i32 n, m;
    cin >> n >> m;
    TwoSat sat;
    Vec<TwoSat::Variable> vars = sat.add_variables(n);
    REP(ci, m) {
        i32 a, b;
        cin >> a >> b >> dummy;
        TwoSat::Variable a_ = (a > 0 ? vars[a - 1] : !vars[-a - 1]);
        TwoSat::Variable b_ = (b > 0 ? vars[b - 1] : !vars[-b - 1]);
        sat.add_clause(a_, b_);
    }
    optional<Vec<bool>> ans = sat.solve();
    if (ans.has_value()) {
        cout << "s SATISFIABLE\n";
        cout << "v ";
        REP(i, n) {
            bool b = (*ans)[vars[i].index()];
            cout << (b ? i + 1 : -i - 1) << ' ';
        }
        cout << "0\n";
    } else {
        cout << "s UNSATISFIABLE\n";
    }
}
