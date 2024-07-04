#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> mp;
    mp['0'] = 'O';
    mp['1'] = 'I';
    mp['2'] = 'Z';
    mp['3'] = 'E';
    mp['4'] = 'A';
    mp['5'] = 'S';
    mp['6'] = 'G';
    mp['7'] = 'T';
    mp['8'] = 'B';
    mp['9'] = 'P';
    int tc;
    cin >> tc;
    cin.ignore();
    for (int t = 0; t < tc; ++t) {
        if (t > 0) {
            cout << endl;
        }
        string curr;
        while (true) {
            getline(cin, curr);
            if (curr.empty()) {
                break;
            }
            for (int i = 0; i < curr.length(); ++i) {
                if (mp.find(curr[i]) != mp.end()) {
                    cout << mp[curr[i]];
                    continue;
                }
                cout << curr[i];
            }
            cout << endl;
        }
    }
    return 0;
}
