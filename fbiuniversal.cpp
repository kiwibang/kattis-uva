#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> m;
    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['A'] = 10;
    m['B'] = 8;
    m['C'] = 11;
    m['D'] = 12;
    m['E'] = 13;
    m['F'] = 14;
    m['G'] = 11;
    m['H'] = 15;
    m['I'] = 1;
    m['J'] = 16;
    m['K'] = 17;
    m['L'] = 18;
    m['M'] = 19;
    m['N'] = 20;
    m['O'] = 0;
    m['P'] = 21;
    m['Q'] = 0;
    m['R'] = 22;
    m['S'] = 5;
    m['T'] = 23;
    m['U'] = 24;
    m['V'] = 24;
    m['W'] = 25;
    m['X'] = 26;
    m['Y'] = 24;
    m['Z'] = 2;
    int multiplier[] = {2, 4, 5, 7, 8, 10, 11, 13};
    int p;
    cin >> p;
    while (p--) {
        int id;
        string ucn;
        cin >> id >> ucn;
        int checksum = 0;
        long long sum = 0;
        for (int i = 0; i < 8; ++i) {
            checksum += (multiplier[i] * m[ucn[i]]);
            sum = (sum * 27) + m[ucn[i]];
        }
        cout << id << " ";
        if ((checksum % 27) == m[ucn[8]]) {
            cout << sum;
        } else {
            cout << "Invalid";
        }
        cout << endl;
    }
    return 0;
}
