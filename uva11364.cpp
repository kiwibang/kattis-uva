#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, curr, mn = 100, mx = -1;
    cin >> t;
    while (t--) {
        cin >> n;
        mn = 100;
        mx = -1;
        while (n--) {
            cin >> curr;
            mn = min(mn, curr);
            mx = max(mx, curr);
        }
        cout << (mx - mn) * 2 << endl;
    }
    return 0;
}
