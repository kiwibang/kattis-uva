#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string curr;
        cin >> curr;
        bool have = false;
        for (int i = 1; i < curr.size(); ++i) {
            if (curr[i - 1] == curr[i]) {
                have = true;
                goto pr;
            }
        }
        pr:
        if (have) {
            cout << 1 << endl;
        } else {
            cout << curr.size() << endl;
        }
    }
    return 0;
}

