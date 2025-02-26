#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        int mn = ceil((float) abs(k) / p);
        if (mn > n) {
            cout << -1 << endl;
        } else {
            cout << mn << endl;
        }
    }
    return 0;
}

