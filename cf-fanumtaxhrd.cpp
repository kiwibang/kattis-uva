#include <bits/stdc++.h>
using namespace std;

// binary search function
int getnext(int curr, vector<int>& minus, int target) {
    int l = 0, r = minus.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        // get the minus
        int cm = minus[m] - curr;
        if (cm >= target) { // try to find smaller one 
            r = m - 1;
        } else { // try to find a bigger one
            l = m + 1;
        }
    }
    if (l >= 0 && l < minus.size()) {
        int res = minus[l] - curr;
        return res < target ? INT_MIN : res;
    } else {
        return INT_MIN;
    }
    return l >= 0 && l < minus.size() ? curr - minus[l] : INT_MIN;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        sort(b.begin(), b.end()); // sort b in asc order
        int prev = min(a[0], b[0] - a[0]); // get minimum val of first element: smaller of first el or first el of b (smallest) - first el of a
        // process the array a from 1 to n - 1
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            // find the smallest element that is >= prev
            int possible = getnext(a[i], b, prev);
            // cout << possible << " " << a[i] << endl;
            int mn = min(possible, a[i]), mx = max(possible, a[i]);
            if (mx < prev) {
                ok = false;
                goto pr;
            }
            if (mn >= prev) {
                prev = mn;
            } else {
                prev = mx;
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

