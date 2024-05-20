#include <bits/stdc++.h>
using namespace std;

// cases:
// have compilance => choose the one with the lowest price
// partial compliance => choose the one with the highest compliance
int main() {
    int n, p;
    string line;
    int c = 0;
    while (cin >> n >> p, n || p) {
        ++c;

        double pr = DBL_MAX, cpr;
        int reqMet = -1, rm;
        string name, naem;
        for (int i = 0; i < n; ++i) {
            cin.ignore();
            getline(cin, line);
        }

        while (p--) {
            getline(cin, naem);
            scanf("%lf %d\n", &cpr, &rm);
            if (rm > reqMet) {
                reqMet = rm;
                name = naem;
                pr = cpr;
            } else if (rm == reqMet && cpr < pr) {
                reqMet = rm;
                name = naem;
                pr = cpr;
            }
            for (int i = 0; i < rm; ++i) {
                getline(cin, line);
            }
        }
        if (c > 1) {
            cout << endl;
        }
        cout << "RFP #" << c << endl;
        cout << name << endl;
    }
    return 0;
}
