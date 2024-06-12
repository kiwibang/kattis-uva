#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double r, b, m, ci;
        cin >> r >> b >> m;
        r /= 100;
        int monthselapsed = 0;
        while (monthselapsed <= 1200) {
            // wait for end of month
            ++monthselapsed;
            // get the interest
            ci = round(b * r * 100.0) / 100.0;
            // then add on the interest
            b += ci;
            b = round(b * 100.0) / 100.0;
            // then subtract the payments
            b -= m;
            // check if done paying off the debt
            if (b <= 0) {
                break;
            }
        }
        if (monthselapsed <= 1200) {
            cout << monthselapsed;
        } else {
            cout << "impossible";
        }
        cout << endl;
    }
    return 0;
}
