#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";
        double res = 0;
        int curr;
        cin >> curr;
        curr -= 180000;
        if (curr <= 0) {
            cout << 0 << endl;
            continue;
        }
        res += (min(curr, 300000) * 0.10);
        curr -= 300000;
        if (curr <= 0) {
            cout << max((int) ceil(res), 2000) << endl;
            continue;
        }
        res += (min(curr, 400000) * 0.15);
        curr -= 400000;
        if (curr <= 0) {
            cout << max((int) ceil(res), 2000) << endl;
            continue;
        }
        res += (min(curr, 300000) * 0.20);
        curr -= 300000;
        if (curr <= 0) {
            cout << max((int) ceil(res), 2000) << endl;
            continue;
        }
        res += (curr * 0.25);
        cout << (int) ceil(res) << endl;
    }
    return 0;
}
