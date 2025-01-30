#include <bits/stdc++.h>
using namespace std;

bool isnum(string str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }   
    return true;
}

int main() {
    string curr, temp;
    unordered_map<string, int> vartoint;
    while (true) {
        getline(cin, curr);
        if (curr == "0") break;
        istringstream iss(curr);
        string var;
        char op;
        int num;
        vector<string> vars;
        int sum = 0;
        while (true) {
            iss >> var;
            if (isnum(var)) {
                sum += stoi(var);
            } else {
                if (vartoint.find(var) == vartoint.end()) {
                    vars.push_back(var);
                } else {
                    sum += vartoint[var];
                }
            }
            iss >> op;
            if (iss.eof()) break; 
            if (op == '=') {
                iss >> num;
                vartoint[var] = num;
                goto cont; // assign and continue
            }
        }
        if (sum == 0 && vars.size() == 0) {
            cout << 0 << endl;
            goto cont;
        } else if (sum != 0 && vars.size() != 0) {
            cout << sum << " + ";
        } else if (sum != 0 && vars.size() == 0) {
            cout << sum << endl;
            goto cont;
        } else { // sum == 0 and vars.size() > 0
        }
        for (int i = 0; i < vars.size(); ++i) {
            cout << vars[i];
            if (i < vars.size() - 1) cout << " + "; 
        }
        cout << endl;
        cont:
    }
    return 0;
}

