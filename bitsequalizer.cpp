#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // read in s and t, get its length
        string s, t;
        cin >> s >> t;
        int m = s.length();

        // count the number of 1s in s and t
        int f11 = 0;
        int f21 = 0;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                ++f11;
            }
            if (t[j] == '1') {
                ++f21;
            }
        }
        
        cout << "Case " << i << ": ";

        // if s has more 1s than t, there is no operation to remedy that, hence impossible
        if (f11 > f21) { 
            cout << -1 << endl;
        } else { // else, possible to remedy
            // count differences
            map<char, int> mp;
            mp['0'] = 0;
            mp['1'] = 0;
            mp['?'] = 0;
            for (int j = 0; j < m; ++j) {
                if (s[j] != t[j]) {
                    ++mp[s[j]];
                }
            }
            // avoid double-counting
            if (mp['0'] >= mp['1']) {
                mp['0'] -= mp['1'];
            } else {
                mp['1'] -= mp['0'];
            }
            cout << mp['0'] + mp['1'] + mp['?'] << endl;
        }
    }
    return 0;
}
