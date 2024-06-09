#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, double> m;
    m['W'] = 1.0;
    m['H'] = 0.5;
    m['Q'] = 0.25;
    m['E'] = 0.125;
    m['S'] = 0.0625;
    m['T'] = 0.03125;
    m['X'] = 0.015625;
    string comp;
    while (true) {
        cin >> comp;
        if (comp == "*") {
            return 0;
        }
        double total;
        int res = 0;
        for (int i = 0; i < comp.size(); ++i) {
            if (comp[i] == '/') {
                if (total == 1.0) {
                    ++res;
                }
                total = 0;
                continue;
            }
            total += m[comp[i]];
        }
        cout << res << endl;
    }
    return 0;
}
