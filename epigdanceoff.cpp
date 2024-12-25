#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    for (int j = 0; j < m; ++j) {
        bool allb = true;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] != '_') {
                allb = false;
                break;
            }
        }
        if (allb) ++res;
    }
    cout << (res + 1) << endl;
    return 0;
}

