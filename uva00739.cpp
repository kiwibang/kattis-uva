#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> mp;
    mp['A'] = 0;
    mp['E'] = 0;
    mp['I'] = 0;
    mp['O'] = 0;
    mp['U'] = 0;
    mp['Y'] = 0;
    mp['W'] = 0;
    mp['H'] = 0;

    mp['B'] = 1;
    mp['P'] = 1;
    mp['F'] = 1;
    mp['V'] = 1;

    mp['C'] = 2;
    mp['S'] = 2;
    mp['K'] = 2;
    mp['G'] = 2;
    mp['J'] = 2;
    mp['Q'] = 2;
    mp['X'] = 2;
    mp['Z'] = 2;

    mp['D'] = 3;
    mp['T'] = 3;

    mp['L'] = 4;

    mp['M'] = 5;
    mp['N'] = 5;

    mp['R'] = 6;
    cout << "         NAME                     SOUNDEX CODE" << endl;
    string curr;
    while (true) {
        cin >> curr;
        if (cin.eof()) {
            break;
        }
        cout << "         ";
        // get soundex code
        string res = "";
        res.push_back(curr[0]);
        int prev = mp.find(curr[0]) == mp.end() ? -1 : mp[curr[0]];
        for (int i = 1; i < curr.size(); ++i) {
            if (mp[curr[i]] != prev && mp[curr[i]] != 0) {
                res += (mp[curr[i]] + '0');
                if (res.size() == 4) {
                    break;
                }
            }
            prev = mp[curr[i]];
        }
        while (res.size() < 4) {
            res.push_back('0');
        }
        cout << left << setw(25) << curr;
        cout << res << endl;               
    }
    cout << "                   END OF OUTPUT" << endl;
    return 0;
}
