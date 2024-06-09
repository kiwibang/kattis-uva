#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double l, d, h, v;
        cin >> l >> d >> h >> v;
        // get the time taken to reach the ground
        double time = sqrt((2 * h) / 9810);
        // get the position of the person
        double pos = v * time;
        // print based on position of the person (note: person might be dead)
        if ((d - 500 <= pos && pos <= d + 500) || (d + l - 500 <= pos && pos <= d + l + 500)) { // case where the dude dies but almost survived (too bad)
            cout << "EDGE" << endl;
        } else if (pos < d - 500 || pos > d + l + 500) { // case where the dude dies
            cout << "FLOOR" << endl;
        } else if ((d + 500) < pos && pos < d + l - 500) { // case where the dude falls into the poolz (lfg bois)
            cout << "POOL" << endl;
        }
    }
    return 0;
}
