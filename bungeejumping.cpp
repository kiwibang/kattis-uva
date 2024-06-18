#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        double k, l, s, w;
        cin >> k >> l >> s >> w;
        if (k == 0 && l == 0 && s == 0 && w == 0) {
            return 0;
        }
        // get delta l
        double deltal = max(0.00, s - l);
        if (2 * w * 9.81 * s <= k * deltal * deltal) {
            cout << "Stuck in the air." << endl;
        } else {
            if ((w * 9.81 * s - 0.5 * k * deltal * deltal) / w <= 50.00) {
                cout << "James Bond survives." << endl;
            } else {
                cout << "Killed by the impact." << endl;
            }
        }
    }
    return 0;
}
