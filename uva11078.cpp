#include <bits/stdc++.h>
using namespace std;

int main() {
    long t, n, curr, res;
    cin >> t;
    while (t--) {
        long mx;
        long res = -9999999999;
        cin >> n;
        cin >> mx;
        n--;
        while (n--) {
            cin >> curr;
            res = max(res, mx - curr);
            mx = max(mx, curr);
        }
        cout << res << endl;
    }
    return 0;
}
