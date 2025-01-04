#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j;
    string instr;
    while (true) {
        cin >> n;
        if (!n) break;
        string reg(32, '?');
        while (n--) {
            cin >> instr;
            if (instr == "CLEAR") {
                cin >> i;
                reg[i] = '0';
            } else if (instr == "SET") {
                cin >> i;
                reg[i] = '1';
            } else if (instr == "OR") {
                cin >> i >> j;
                if (reg[i] != '?' && reg[j] != '?') {
                    reg[i] = ((reg[i] - '0') | (reg[j] - '0')) + '0';
                } else if (reg[i] == '?') {
                    reg[i] = reg[j] == '1' ? reg[j] : '?';
                } else if (reg[j] == '?') {
                    reg[i] = reg[i] == '1' ? reg[i] : '?';
                } else {
                    reg[i] = '?';
                }
            } else if (instr == "AND") {
                cin >> i >> j;
                if (reg[i] != '?' && reg[j] != '?') {
                    reg[i] = ((reg[i] - '0') & (reg[j] - '0')) + '0';
                } else if (reg[i] == '?') {
                    reg[i] = reg[j] == '0' ? reg[j] : '?';
                } else if (reg[j] == '?') {
                    reg[i] = reg[i] == '0' ? reg[i] : '?';
                } else {
                    reg[i] = '?';
                }
            }
        }
        for (int i = 31; i >= 0; --i) {
            cout << reg[i];
        }
        cout << endl;
    }
    return 0;
}

