#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long mn = LLONG_MAX, mx = LLONG_MIN, curr;
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            mn = min(mn, curr), mx = max(mx, curr);
        }
        cout << mx - mn << endl;
    }
    return 0;
}

