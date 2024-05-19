#include <bits/stdc++.h>
using namespace std;

int main() {
    int dur, n;
    double down, loan, depP[101];
    while (true) {
        cin >> dur >> down >> loan >> n;
        if (dur < 0) {
            return 0;
        }

        int m;
        double p;
        while (n--) {
            cin >> m >> p;
            for (int i = m; i < 101; ++i) {
                depP[i] = p;
            }
        }

        int pr = 0;
        double pmt = loan / dur;
        double cv = (loan + down) * (1 - depP[0]);
        double cl = loan;
        while (cv < cl) {
            ++pr;
            cl -= pmt;
            cv *= (1 - depP[pr]);
        }
        cout << pr << " month";
        if (pr != 1) {
            cout << "s";
        }
        cout << endl;
    }
    return 0;
}
