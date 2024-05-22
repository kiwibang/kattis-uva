#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 0;
    while (true) {
        int n, m, c;
        cin >> n >> m >> c;
        if (n == 0 && m == 0 && c == 0) {
            return 0;
        }
        vector<int> consumption;
        for (int i = 0; i < n; ++i) {
            int cn;
            cin >> cn;
            consumption.push_back(cn);
        }
        int totalPower = 0;
        int res = 0;
        bool blown = false;
        vector<bool> states(n, false);
        for (int i = 0; i < m; ++i) {
            int op;
            cin >> op;
            if (blown) {
                continue;
            }
            states[op - 1] = !states[op - 1];
            totalPower = states[op - 1] ? totalPower + consumption[op - 1] : max(0, totalPower - consumption[op - 1]);
            res = max(res, totalPower);
            if (totalPower > c) {
                blown = true;
            }
        }
        ++i;
        if (i > 1) {
            cout << endl;
        }
        cout << "Sequence " << i << endl;
        if (blown) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << res << " amperes." << endl;
        }
    }
    return 0;
}
