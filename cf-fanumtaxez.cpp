#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        int prev = min(a[0], b[0] - a[0]);
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            int currmn = min(a[i], b[0] - a[i]), currmx = max(a[i], b[0] - a[i]);
            if (currmx < prev) {
                ok = false;
                goto pr;
            }
            // currmax >= prev
            if (currmn < prev) {
                prev = currmx;
            } else { // currmin >= prev && currmax >= prev
                prev = currmn;
            }
        }
        pr:
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

