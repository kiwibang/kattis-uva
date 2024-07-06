#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, res = 0;
    while (true) {
        string eqn;
        cin >> eqn;
        if (cin.eof()) {
            break;
        }
        a = -1, b = -1, c = -1;
        bool ona = true, onb = false, wrong = false;
        char oper;
        for (int i = 0; i < eqn.size(); ++i) {
            if (eqn[i] == '+' || eqn[i] == '-') {
                oper = eqn[i];
                ona = false;
                onb = true;
                continue;
            }
            if (eqn[i] == '=') {
                onb = false;
            }
            if (eqn[i] == '?') {
                wrong = true;
                break;
            }
            if (isdigit(eqn[i])) {
                if (ona && !onb) {
                    a = a == -1 ? eqn[i] - '0' : a * 10 + (eqn[i] - '0');
                } else if (!ona && onb) {
                    b = b == -1 ? eqn[i] - '0' : b * 10 + (eqn[i] - '0');
                } else if (!ona && !onb) {
                    c = c == -1 ? eqn[i] - '0' : c * 10 + (eqn[i] - '0');
                }
            }
        }
        wrong = oper == '+' ? a + b != c : a - b != c;
        if (!wrong) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
