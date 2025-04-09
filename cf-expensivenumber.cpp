#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(), nonz = 0, res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') res = min(res, nonz + n - i - 1), ++nonz;
        }
        cout << res << endl;
    }
    return 0;
}

