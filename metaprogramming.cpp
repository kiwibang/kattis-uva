#include <bits/stdc++.h>
using namespace std;

int main() {
    string cmd, var1, var2;
    int num;
    char op; 
    bool res;
    unordered_map<string, int> vartonum;
    while (true) {
        cin >> cmd;
        if (cin.eof()) break;
        if (cmd == "define") {
            cin >> num >> var1;
            vartonum[var1] = num;
        } else if (cmd == "eval") {
            cin >> var1 >> op >> var2;
            if (vartonum.find(var1) == vartonum.end() || vartonum.find(var2) == vartonum.end()) {
                cout << "undefined" << endl;
                continue;
            }
            if (op == '=') {
                res = vartonum[var1] == vartonum[var2];
            } else if (op == '<') {
                res = vartonum[var1] < vartonum[var2];
            } else if (op == '>') {
                res = vartonum[var1] > vartonum[var2];
            }
            cout << (res ? "true" : "false") << endl;
        }
    }
    return 0;
}

