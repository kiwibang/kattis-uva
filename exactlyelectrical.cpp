#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, t;
    cin >> a >> b;
    cin >> c >> d;
    cin >> t;
    // compute charge needed to reach
    int chargeNeeded = abs(a - c) + abs(b - d);
    // if not enough charge to reach destination
    if (chargeNeeded > t) {
        cout << "N" << endl;
    } else { // can reach
        // compute the remaining fuel left after reaching dest
        int diff = t - chargeNeeded;
        // case where cannot end with 0 charge
        if ((diff & 1) == 1) {
            cout << "N" << endl;
        } else { // case where can
            cout << "Y" << endl;
        }
    }
    return 0;
}
