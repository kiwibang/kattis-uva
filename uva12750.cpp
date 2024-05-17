#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        int n;
        cin >> n;
        int nwc = 0, lid = -1;
        for (int i = 1; i <= n; ++i) {
            char c;
            cin >> c;
            if (c == 'W') {
                nwc = 0;
            } else {
                ++nwc;
                if (lid == -1 && nwc >= 3) {
                    lid = i;
                }
            }
        }
        cout << "Case " << j << ": ";
        if (lid == -1) {
            cout << "Yay! Mighty Rafa persists!" << endl;
        } else {
            cout << lid << endl;
        }
    }
    return 0;
}
