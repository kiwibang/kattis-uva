#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // read in input
        int r, c;
        cin >> r >> c;
        vector<string> g(r);
        for (int i = 0; i < r; ++i) cin >> g[i];
        // process input
        vector<vector<char>> res(r, vector<char>(c));
        vector<int> rf(r, 0);
        vector<int> cf(c, 0);
        bool impossible = false;
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (g[i][j] == '1') ++rf[i], ++cf[j];
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == '1') {
                    if (min(rf[i] - 1, cf[j] - 1) == 0) {
                        res[i][j] = 'P';
                    } else {
                        res[i][j] = 'I';
                    }
                } else {
                    if (rf[i] > 0 && cf[j] > 0) {
                        impossible = true;
                        goto pr;
                    }
                    res[i][j] = 'N';
                }
            }
        }
        pr:
        if (impossible) { // impossible case
            cout << "impossible" << endl;
        } else { // normal case
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << res[i][j];
                }
                cout << endl;
            }
        }
        cout << "----------" << endl;
    }
    return 0;
}

