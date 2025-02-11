#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, long long>& a, pair<int, long long>& b) {
    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> arrs(n, vector<long long>(m));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arrs[i][j];
        // get the sum
        vector<pair<int, long long>> idxnsum(n);
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += arrs[i][j];
            }
            idxnsum[i] = {i, sum};
        }
        sort(idxnsum.begin(), idxnsum.end(), cmp);
        // process
        long long mult = n * m;
        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int rowidx = idxnsum[i].first;
            for (int j = 0; j < m; ++j) {
                res += mult-- * arrs[rowidx][j];
            }
        }
        cout << res << endl;
    }
    return 0;
}

