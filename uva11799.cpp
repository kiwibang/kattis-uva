#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, curr;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        int mx = 0;
        for (int j = 0; j < n; ++j) {
            cin >> curr;
            mx = max(mx, curr);
        }
        cout << "Case " << i << ": " << mx << endl; 
    }
    return 0;
}
