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

int main() {
    map<string, int> valmap;
    vector<string> inttoroman(4000, "");
    for (int i = 1; i < 4000; ++i) {
        string temp = toroman(i);
        valmap[temp] = i;
        inttoroman[i] = temp;
    }
    string number;
    int num;
    while (cin >> number) {
        if (isdigit(number[0])) {
            istringstream iss(number);
            iss >> num;
            cout << inttoroman[num] << endl;
            continue;
        }
        cout << valmap[number] << endl;
    }
    return 0;
}
