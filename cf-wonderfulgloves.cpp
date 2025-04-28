#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, pcnt = 0; 
        cin >> n >> k;
        vector<long long> l(n), r(n), mn(n);
        for (int i = 0; i < n; ++i) cin >> l[i];
        for (int i = 0; i < n; ++i) cin >> r[i];
        long long mxsum = 0;
        for (int i = 0; i < n; ++i) {
            mn[i] = min(l[i], r[i]);
            mxsum += max(l[i], r[i]);
        } 
        sort(mn.begin(), mn.end(), greater<int>());
        for (int i = 1; i < n; ++i) mn[i] += mn[i - 1];
        cout << (k - 2 < 0 ? mxsum + 1 : mxsum + mn[k - 2] + 1) << '\n'; 
    }
    return 0;
}

