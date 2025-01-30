#include <bits/stdc++.h>
using namespace std;

int main() {
    string cl;
    unordered_map<string, int> vti;
    unordered_map<int, string> itv;
    while (true) {
        getline(cin, cl);
        if (cin.eof()) break;
        istringstream iss(cl);
        string cmd, cvar;
        int val; 
        char op;
        iss >> cmd;
        if (cmd == "def") {
            iss >> cvar >> val;
            if (vti.find(cvar) != vti.end() && itv.find(vti[cvar]) != itv.end()) {
                itv.erase(vti[cvar]);
            }
            vti[cvar] = val;
            itv[val] = cvar;
        } else if (cmd == "calc") {
            string eqn = cl.substr(cl.find(' ') + 1);
            int sign = 1, sum = 0;
            while (true) {
                iss >> cvar;
                if (cvar == "-" || cvar == "+") {
                    sign = cvar == "+" ? 1 : -1;
                    iss >> cvar;
                }
                if (vti.find(cvar) == vti.end()) {
                    sum = INT_MIN;
                    break;
                }
                sum += sign * vti[cvar];
                iss >> op;
                sign = op == '+' || op == '=' ? 1 : -1;
                if (op == '=') break;
                if (iss.eof()) break;
            }
            cout << eqn << " ";
            if (sum == INT_MIN || itv.find(sum) == itv.end()) {
                cout << "unknown" << endl;
            } else { 
                cout << itv[sum] << endl;
            }
        } else if (cmd == "clear") {
            vti.clear();
            itv.clear();
        }
    }
    return 0;
}

