#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, res;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> k;
        res = 1;
        for (int i = 0; i < n; ++i) {
            res &= (k & 1);
            k >>= 1;
        }
        cout << "Case #" << tc << ": ";
        if (res) {
            cout << "ON" << endl;
        } else {
            cout << "OFF" << endl;
        }
    }
    return 0;    
}

