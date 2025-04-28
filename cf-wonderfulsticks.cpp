#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int gtcount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '<') ++gtcount;
        }
        vector<int> res(n);
        res[0] = gtcount + 1;
        int mx = res[0];
        // calculate for i = 1 to i = n - 1 (0-indexed)
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == '<') {
                res[i] = gtcount;
                --gtcount;
            } else {
                res[i] = mx + 1;
            }
            mx = max(mx, res[i]);
        }
        for (int num : res) cout << num << " ";
        cout << '\n';
    }
    return 0;
}

