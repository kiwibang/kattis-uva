#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, res;
    while (true) {
        cin >> n >> m;
        if (!n && !m) break;
        vector<int> jack(n), jill(m);
        for (int i = 0; i < n; ++i) cin >> jack[i];
        for (int i = 0; i < m; ++i) cin >> jill[i];
        res = 0;
        int idx1 = 0, idx2 = 0;
        while (idx1 < n && idx2 < m) {
            if (jack[idx1] == jill[idx2]) {
                ++res;
                ++idx1;
                ++idx2;
            } else if (jack[idx1] > jill[idx2]) {
                ++idx2;
            } else {
                ++idx1;
            }
        }
        cout << res << endl;
    }
    return 0;
}

