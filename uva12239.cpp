#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, b;
        cin >> n >> b;
        if (n == 0 && b == 0) {
            return 0;
        }
        vector<bool> have(n + 1, false);
        vector<int> ballz;
        for (int i = 0; i < b; ++i) {
            int ball;
            cin >> ball;
            ballz.push_back(ball);
        }
        for (int i = 0; i < b; ++i) {
            for (int j = i; j < b; ++j) {
                have[abs(ballz[i] - ballz[j])] = true;
            }
        }
        bool ok = true;
        for (int i = 0; i <= n; ++i) {
            if (!have[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
