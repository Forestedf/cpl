#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#define FAST_IO

#include "../../template/template.hpp"
#include "../../string/z_algorithm.hpp"

int main() {
    string s;
    cin >> s;
    Vec<i32> z = z_algorithm(s);
    REP(i, s.size()) {
        cout << z[i] << " \n"[i + 1 == s.size()];
    }
}