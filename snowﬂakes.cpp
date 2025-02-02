#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> snowflakes(n);
        unordered_map<int, int> f;
        for (int i = 0; i < n; ++i) cin >> snowflakes[i];
        int l = 0, r = 0, res = 1, dup;
        while (r < n) {
            // put as many snowflakes in the bag as possible
            while (r < n) {
                if (f.find(snowflakes[r]) == f.end()) {
                    f[snowflakes[r]] = 1;
                    res = max(res, r - l + 1);
                } else {
                    ++f[snowflakes[r]];
                    dup = r;
                    ++r;
                    break;
                }
                ++r;
            }
            while (l < r && f[snowflakes[dup]] > 1) {
                --f[snowflakes[l]];
                if (!f[snowflakes[l]]) {
                    f.erase(snowflakes[l]);
                }
                ++l;
            }
        }
        cout << res << endl;
    }
    return 0;
}

