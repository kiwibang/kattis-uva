#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> res(n, vector<int>(m));
        if (m % k) { // case where m is not a multiple of k
            int ck = 0;
            // simply lay the numbers 1 to k in the natural reading order
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    res[i][j] = (ck++ % k) + 1;
                }
            }
        } else { // case where m is a multiple of k
            int ck = 0;
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                    for (int j = 0; j < m; ++j) {
                        res[i][j] = (((j % k) + 1) % k) + 1;
                    }
                } else {
                    for (int j = 0; j < m; ++j) {
                        res[i][j] = (j % k) + 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << res[i][j] << " ";
            }
            cout << '\n';
        }
    }
}
