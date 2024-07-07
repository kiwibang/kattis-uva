#include <bits/stdc++.h>
using namespace std;

bool isop(char cc) {
    return cc == '-' || cc == '+' || cc == '*' || cc == '/';
}

bool isopstr(string s) {
    return s == "-" || s == "+" || s == "*" || s == "/";
}

bool isvar(string s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isalpha);
}

bool isint(string s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

string operate(int op1, int op2, string oper) {
    int res;
    if (oper == "*") {
        res = op1 * op2;
    } else if (oper == "/") {
        res = op1 / op2;
    } else if (oper == "+") {
        res = op1 + op2;
    } else if (oper == "-") {
        res = op1 - op2;
    } else {
        return "-1";
    }
    return to_string(res);
}

// i hate this qn.
int main() {
    string eqn;
    int tc = 0;
    while (true) {
        // read in the current eqn 
        getline(cin, eqn);
        if (cin.eof()) {
            break;
        }
        if (tc++ > 0) {
            cout << endl;
        }
        vector<string> symbols;
        string curroper = "", num = "", var;
        // parse the input
        int idx = 0, n = eqn.size();
        while (idx < n) {
            // case if unary operator - either 0th char and + or -, or last symbol is already an operator
            if ((idx == 0 && (eqn[idx] == '-' || eqn[idx] == '+') || (symbols.size() > 0 && isopstr(symbols[symbols.size() - 1]) && (eqn[idx] == '-' || eqn[idx] == '+')))) {
                if (eqn[idx] == '-') {
                    num.push_back(eqn[idx]);
                }
                ++idx;
            } else if (isdigit(eqn[idx])) { // case where digit
                // get all the digit
                while (idx < n && isdigit(eqn[idx])) {
                    num.push_back(eqn[idx]);
                    ++idx;
                }
                symbols.push_back(num);
                // reset nums for the next number (if any)
                num = "";
            } else if (eqn[idx] == ' ' || eqn[idx] == '=') { // case where space or equals
                ++idx;
                continue; // skip
            } else if (isalpha(eqn[idx])) { // case where variable
                // get the variable via substr method, and exit
                var = eqn.substr(idx);
                break; // exit; we know that this is the last entity of the expression
            } else if (isop(eqn[idx])) { // case where operator
                curroper.push_back(eqn[idx++]);
                symbols.push_back(curroper);
                curroper = "";
            } else {
                cout << "lmao" << endl;
            }
        }
        // print the initial expression
        for (int i = 0; i < symbols.size(); ++i) {
            cout << symbols[i] << " ";
        }
        cout << "= " << var << endl;
        // print out the steps to evaluate the current expression
        while (symbols.size() > 1) {
            // look for the first multiplication/division operator, and the first add/subtract operator
            int firstmultordiv = -1, firstaddorminus = -1;
            for (int i = 0; i < symbols.size(); ++i) {
                if ((symbols[i] == "*" || symbols[i] == "/") && firstmultordiv == -1) {
                    firstmultordiv = i;
                } else if ((symbols[i] == "+" || symbols[i] == "-") && firstaddorminus == -1) {
                    firstaddorminus = i;
                }
            }
            vector<string> next;
            int op1, op2;
            string oper;
            // add up to the next operator
            if (firstmultordiv != -1) {
                for (int i = 0; i < firstmultordiv - 1; ++i) {
                    next.push_back(symbols[i]);
                }
                op1 = stoi(symbols[firstmultordiv - 1]), op2 = stoi(symbols[firstmultordiv + 1]);
                oper = symbols[firstmultordiv];
                string res = operate(op1, op2, oper);
                next.push_back(res);
                for (int i = firstmultordiv + 2; i < symbols.size(); ++i) {
                    next.push_back(symbols[i]);
                }
            } else if (firstaddorminus != -1) {
                for (int i = 0; i < firstaddorminus - 1; ++i) {
                    next.push_back(symbols[i]);
                }
                op1 = stoi(symbols[firstaddorminus - 1]), op2 = stoi(symbols[firstaddorminus + 1]);
                oper = symbols[firstaddorminus];
                string res = operate(op1, op2, oper);
                next.push_back(res);
                for (int i = firstaddorminus + 2; i < symbols.size(); ++i) {
                    next.push_back(symbols[i]);
                }
            } else {
                for (int i = 0; i < symbols.size(); ++i) {
                    next.push_back(symbols[i]);
                }
            }
            // update the symbols list
            symbols = next;
            for (int i = 0; i < symbols.size(); ++i) {
                cout << symbols[i] << " ";
            }
            cout << "= " << var << endl;
        }
    }
    return 0;
}
