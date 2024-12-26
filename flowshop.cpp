#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int add = 0;
            if (i > 0) add = grid[i - 1][j];
            if (j > 0) add = max(grid[i][j - 1], add);
            grid[i][j] += add;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << grid[i][m - 1];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

