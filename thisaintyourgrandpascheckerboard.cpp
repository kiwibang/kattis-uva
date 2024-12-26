#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];
    // check all rows
    for (int i = 0; i < n; ++i) {
        int nz = 0, no = 0, consec = 0;
        char prev = '.';
        for (int j = 0; j < n; ++j) {
            if (prev == '.') {
                prev = g[i][j];
                consec = 1;
            } else {
                if (prev != g[i][j]) {
                    consec = 1;
                    prev = g[i][j];
                } else {
                    ++consec;
                    if (consec == 3) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            if (g[i][j] == 'W') {
                ++nz;
            } else {
                ++no;
            }
        }
        if (nz != no) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int j = 0; j < n; ++j) {
        int nz = 0, no = 0, consec = 0;
        char prev = '.';
        for (int i = 0; i < n; ++i) {
            if (prev == '.') {
                prev = g[i][j];
                consec = 1;
            } else {
                if (prev != g[i][j]) {
                    consec = 1;
                    prev = g[i][j];
                } else {
                    ++consec;
                    if (consec == 3) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            if (g[i][j] == 'W') {
                ++nz;
            } else {
                ++no;
            }
        }
        if (nz != no) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
