#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            return 0;
        }
        int t1 = min(m, n);
        int t2 = max(m, n);
        if (t1 == 1) {
            cout << t2 << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        } else if (t1 == 2) {
            cout << 4 * (t2 / 4) + 2 * min(2, t2 % 4) << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        } else {
            cout << (t1 * t2 + 1) / 2 << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        }
    }
    return 0;
}
