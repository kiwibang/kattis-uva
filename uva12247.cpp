#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // get the inputs
        vector<int> princess;
        vector<bool> used(3, false);
        int x, y;
        for (int i = 0; i < 3; ++i) {
            int curr;
            cin >> curr;
            princess.push_back(curr);
        }
        cin >> x >> y;
        if (princess[0] == 0 && princess[1] == 0 && princess[2] == 0 && x == 0 && y == 0) {
            return 0;
        }
        sort(princess.begin(), princess.end());
        // count the number of times that prince cards can be beaten
        // if all 2 prince cards can be defeated => -1
        // look for card that can defeat x
        for (int i = 0; i < 3; ++i) {
            // use the minimum card that can defeat x
            if (!used[i] && princess[i] > x) {
                used[i] = true;
                break;
            }
        }
        // look for card that can defeat y
        for (int i = 0; i < 3; ++i) {
            // use the minimum card that can defeat y
            if (!used[i] && princess[i] > y) {
                used[i] = true;
                break;
            }
        }
        // count the number of distinct cards that can be used to defeat prince cards
        int count = 0;
        for (int i = 0; i < 3; ++i) {
            if (used[i]) {
                ++count;
            }
        }
        // impossible to guarantee a win
        if (count == 2) {
            cout << -1 << endl;
        } else if (count == 1) { // if 1 of the cards defeated
            // choose the biggest card for prince that can defeat the remaining princess cards
            int mx = 0;
            for (int i = 0; i < 3; ++i) {
                if (!used[i]) {
                    mx = max(mx, princess[i]);
                }
            }
            int res = mx + 1;
            while (res < 53 && (res == princess[0] || res == princess[1] || res == princess[2] || res == x || res == y)) {
                ++res;
            }
            if (res == 53) {
                cout << -1 << endl;
            } else {
                cout << res << endl;
            }
        } else { // if no cards defeated
            int res = 1;
            while (res < 53 && (res == princess[0] || res == princess[1] || res == princess[2] || res == x || res == y)) {
                ++res;
            }
            if (res == 53) {
                cout << -1 << endl;
            } else {
                cout << res << endl;
            }
        }
    }
    return 0;
}
