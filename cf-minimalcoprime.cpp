#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << (gcd(l, r) == 1 ? "1" : "0") << endl;
            continue;
        }
        cout << r - l << endl;
    }
    return 0;
}

