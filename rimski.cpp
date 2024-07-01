#include <bits/stdc++.h>
using namespace std;

string toroman(int num) {
    const char rcode[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
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

bool issame(string a, string b) {
    vector<int> f1(26, 0);
    vector<int> f2(26, 0);
    for (int i = 0; i < a.size(); ++i) {
        ++f1[a[i] - 'A'];
    }
    for (int i = 0; i < b.size(); ++i) {
        ++f2[b[i] - 'A'];
    }
    return f1 == f2;
}
int main() {
    vector<string> valmap(101, "");
    for (int i = 1; i <= 100; ++i) {
        valmap[i] = toroman(i);
    }
    string romannum;
    cin >> romannum;
    for (int i = 1; i <= 100; ++i) {
        if (issame(romannum, valmap[i])) {
            cout << valmap[i] << endl;
            break;
        }
    }
    return 0;
}
