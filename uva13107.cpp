#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> mp;
    mp['2'] = '5';
    mp['6'] = '9';
    mp['5'] = '2';
    mp['9'] = '6';
    string curr;
    while (cin >> curr) {
        map<char, int> charmap;
        int currid = 1;
        string r = "";
        for (int i = 0; i < curr.size(); ++i) {
            if (charmap.find(curr[i]) == charmap.end()) {
                charmap[curr[i]] = currid++;
            }
            r += to_string(charmap[curr[i]]);
        }
        for (int i = 0; i < r.size(); ++i) {
            if (mp.find(r[i]) != mp.end()) {
                cout << mp[r[i]];
                continue;
            }
            cout << r[i];
        }
        cout << endl;
    }
    return 0;
}
