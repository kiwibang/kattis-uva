#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int m, p, l, e, r, s, n;
    while (true) {
        cin >> m >> p >> l >> e >> r >> s >> n;
        if (cin.eof()) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            int t = m;
            m = p / s;
            p = l / r;
            l = t * e;
        }
        cout << m << endl;
    }
    return 0;
}
