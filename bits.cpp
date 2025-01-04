#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string curr;
        int cpow = 0, temp = 0, res = 0;
        cin >> curr;
        for (int i = 0; i < curr.size(); ++i) {
            temp = (temp * 10) + (curr[i] - '0');
            res = max(res, __builtin_popcount(temp));
        }
        cout << res << endl;
    }
    return 0;
}

