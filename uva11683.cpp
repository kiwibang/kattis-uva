#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int a, c;
        cin >> a >> c;
        if (a == 0) {
            return 0;
        }
        int count[c];
        for (int i = 0; i < c; ++i) {
            cin >> count[i];
        }
        int res = a - count[0];
        for (int i = 1; i < c; ++i) {
            res += max(0, count[i - 1] - count[i]);
        }
        cout << res << endl;
    }
    return 0;
}
