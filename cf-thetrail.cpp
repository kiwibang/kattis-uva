#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> rs(n, 0ll), cs(m, 0ll);
        vector<vector<long long>> g(n, vector<long long>(m));
        string path;
        cin >> path;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
                rs[i] += g[i][j], cs[j] += g[i][j];
            }
        }
        // i represents the direction
        int x = 0, y = 0;
        for (int i = 0; i < path.size(); ++i) {
            // get the value for the current cell in the path
            if (path[i] == 'D') { // down
                                  // use row sum
                g[x][y] = -rs[x];
                rs[x] += g[x][y];
                cs[y] += g[x][y];
                // update coords
                ++x;
            } else { // right
                     // use col sum
                g[x][y] = -cs[y];
                rs[x] += g[x][y];
                cs[y] += g[x][y];
                // update coords
                ++y;
            }
        }
        g[x][y] = -rs[x];
        for (auto& r : g) {
            for (long long num : r) {
                cout << num << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}

