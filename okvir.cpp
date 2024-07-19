#include <bits/stdc++.h>
using namespace std;

int main() {
        int m, n, u, l, r, d;
        cin >> m >> n >> u >> l >> r >> d;
        vector<string> in(m);
        for (int i = 0; i < m; ++i) {
            cin >> in[i];
        }
        // determine the dimensions of the final output
        int resr = u + d + m, resc = l + r + n;
        vector<vector<char> > toprint(resr, vector<char>(resc));
        // fill with chessboard configuration
        for (int i = 0; i < resr; ++i) {
            for (int j = 0; j < resc; ++j) {
                if ((j % 2) == 0) {
                    if ((i % 2) == 0) {
                        toprint[i][j] = '#';
                    } else {
                        toprint[i][j] = '.';
                    }
                } else {
                    if ((i % 2) == 0) {
                        toprint[i][j] = '.';
                    } else {
                        toprint[i][j] = '#';
                    }
                }
            }
        }
        // fill with the word
        for (int i = u; i < u + m; ++i) {
            for (int j = l; j < l + n; ++j) {
                toprint[i][j] = in[i - u][j - l];
            }
        }
        for (int i = 0; i < resr; ++i) {
            for (int j = 0; j < resc; ++j) {
                cout << toprint[i][j];
            }
            cout << endl;
        }
        return 0;
}
