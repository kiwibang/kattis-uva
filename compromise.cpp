#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) cin >> grid[i];
        string res = "";
        for (int j = 0; j < m; ++j) {
            int nz = 0, no = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == '0') {
                    ++nz;
                } else {
                    ++no;
                }
            }
            if (nz >= no) {
                res += '0';
            } else {
                res += '1';
            }
        }
        cout << res << endl;
    }
    return 0;
}

