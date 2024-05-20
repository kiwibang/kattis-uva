#include <bits/stdc++.h>
using namespace std;

const int nc = 5;
const int c[nc] = {10000, 1000, 100, 10, 1}; 

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (cin.eof()) {
            return 0;
        }
        // track the res for the current testcase
        long long res = 0;
        // loop over the rounds
        while (m--) {
            // get the budget, then loop over the rounds
            long long b;    
            cin >> b;

            int d;
            cin >> d;
            for (int j = 1; j < n; ++j) {
                int card;
                cin >> card;
                b -= card;
            }
            if (d > b) {
                d = 0;
            }

            int mx = 0;
            for (int i = 0; i < nc; ++i) {
                if (c[i] <= b) {
                    mx = c[i];
                    break;
                }
            }
            res += mx - d;
        }
        // print the res after all the rounds have finished
        cout << res << endl;
    }
    return 0;
}
