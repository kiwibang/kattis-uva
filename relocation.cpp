#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, cmd, c, x, a, b;
    cin >> n >> q;
    map<int, int> loc;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        loc[i] = x;
    }
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> c >> x;
            loc[c] = x;
        } else if (cmd == 2) {
            cin >> a >> b;
            cout << abs(loc[a] - loc[b]) << endl;
        }
    }
    return 0;
}

