#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, count = 0;
    double l, w, d, wt;
    cin >> t;
    while (t--) {
        cin >> l >> w >> d >> wt;
        if ((l <= 56 && w <= 45 && d <= 25 && wt <= 7) || (l + w + d <= 125 && wt <= 7)) {
            cout << 1 << endl;
            ++count;
        } else {
            cout << 0 << endl;
        }
    }
    cout << count << endl;
    return 0;
}
