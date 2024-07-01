#include <bits/stdc++.h>
using namespace std;

string toroman(int num) {
    const char rcode[13][3] = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string res = "";
    int idx = 0;
    for (int i = 0; i < 13; ++i) {
        while (num >= val[i]) {
            num -= val[i];
            res.push_back(rcode[i][0]);
            if (rcode[i][1] != '\0') {
                res.push_back(rcode[i][1]);
            }
        }
    }
    return res;
}

int main() {
    vector<string> valmap(4000, "");
    for (int i = 1; i <= 3999; ++i) {
        valmap[i] = toroman(i);
    }
    map<char, int> matchesneeded;
    matchesneeded['i'] = 1;
    matchesneeded['v'] = 2;
    matchesneeded['x'] = 2;
    matchesneeded['l'] = 2;
    matchesneeded['c'] = 2;
    matchesneeded['d'] = 3;
    matchesneeded['m'] = 4;
    int num;
    while (cin >> num) {
        string romannumeral = valmap[num];
        long long res = 0;
        for (int i = 0; i < romannumeral.size(); ++i) {
            res += matchesneeded[romannumeral[i]];
        }
        cout << res << endl;
    }
    return 0;
}
