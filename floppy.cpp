// credits: https://github.com/RussellDash332/kattis/blob/main/src/Floppy%20Music/floppy.py
#include <bits/stdc++.h>
using namespace std;

int main() {
    int f;
    cin >> f;
    for (int i = 0; i < f; ++i) {
        int t, n;
        cin >> t >> n;
        vector<bool> can(t + 1, true);
        for (int j = 0; j < n; ++j) {
            vector<bool> temp(t + 1, false);
            int t1, t2;
            cin >> t1 >> t2;
            int diff = t2 - t1;
            for (int k = 0; k <= t; ++k) {
                if (can[k] && k >= diff) temp[k - diff] = true;
                if (can[k] && k <= t - diff) temp[k + diff] = true;
            }
            can = temp;
        }
        int sum = 0;
        for (int j = 0; j <= t; ++j) if (can[j]) ++sum;
        if (!sum) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}

