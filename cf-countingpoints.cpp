#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> xs(n), rs(n);
        for (int i = 0; i < n; ++i) cin >> xs[i];
        for (int i = 0; i < n; ++i) cin >> rs[i];
        // track max y for each x
        unordered_map<long long, long long> xtoy;
        for (int i = 0; i < n; ++i) {
            // get 
            long long x = xs[i], r = rs[i];
            for (long long dx = -r; dx <= r; ++dx) {
                // calculate y
                 long long cx = x + dx, sq = r * r - dx * dx, y = (long long) floor(sqrt((long double) sq));
                if (xtoy.find(cx) == xtoy.end()) xtoy[cx] = 0;
                xtoy[cx] = max(xtoy[cx], y);
            }
        }   
        long long res = 0;
        for (auto& p : xtoy) {
            res += ((p.second << 1) + 1);
        }
        cout << res << "\n";
    }
    return 0;
}

