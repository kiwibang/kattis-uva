#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int b, n;
        cin >> b >> n;
        if (b == 0 && n == 0) {
            return 0;
        }
        int reserves[b];
        // read in the initial reserves
        for (int id = 0; id < b; ++id) {
            cin >> reserves[id];
        }
        // then read in the debentures
        for (int i = 0; i < n; ++i) {
            int d, c, v;
            cin >> d >> c >> v;
            reserves[d - 1] -= v;
            reserves[c - 1] += v;
        }
        // then check if need bailout or not
        bool canPay = true;
        for (int id = 0; id < b; ++id) {
            if (reserves[id] < 0) {
                canPay = false;
                break;
            }
        }
        if (canPay) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
