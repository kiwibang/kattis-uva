#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        string curr, currarrow;
        cin >> curr;
        // i is index to string, res is length of longest arrow
        int i = 0, res = -1;
        while (i < curr.length()) {
            // if left arrow
            if (curr[i] == '<') {
                int l = 1;
                ++i;
                char cc = i < curr.length() ? curr[i] : '\0';
                while (i < curr.length() && cc == curr[i] && (curr[i] == '-' || curr[i] == '=')) {
                    ++i;
                    ++l;
                }
                res = max(res, l);
            } else if (curr[i] == '>') { // case where right arrow
                int l = 1, init = i;
                --i;
                char cc = i >= 0 ? curr[i] : '\0';
                while (i >= 0 && cc == curr[i] && (curr[i] == '-' || curr[i] == '=')) {
                    --i;
                    ++l;
                }
                res = max(res, l);
                i = init + 1;
            } else {
                ++i;
            }
        }
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}
