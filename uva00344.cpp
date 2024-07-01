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
    vector<string> valmap(101, "");
    for (int i = 1; i <= 100; ++i) {
        valmap[i] = toroman(i);
    }
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        map<char, int> fmap;
        fmap['i'] = 0;
        fmap['v'] = 0;
        fmap['x'] = 0;
        fmap['l'] = 0;
        fmap['c'] = 0;
        for (int i = 1; i <= num; ++i) {
            string romannum = valmap[i];
            for (int j = 0; j < romannum.size(); ++j) {
                ++fmap[romannum[j]];
            }
        }
        cout << num << ": ";
        cout << fmap['i'] << " i, ";
        cout << fmap['v'] << " v, ";
        cout << fmap['x'] << " x, ";
        cout << fmap['l'] << " l, ";
        cout << fmap['c'] << " c" << endl;
    }
    return 0;
}
