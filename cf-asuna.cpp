#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false);cin.tie(nullptr);
    int t, n, numodd, num, mx;
    long long s;
    cin >> t;
    while (t--) {
        cin >> n;
        numodd = 0, s = 0, mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (num & 1) ++numodd;
            s += num, mx = max(mx, num);
        }
        cout << (numodd == n || !numodd ? mx : s - numodd + 1) << "\n";
    }
    return 0;
}

