#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 1;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        if (i > 1) {
            cout << endl;
        }
        string row;
        vector<vector<char> > b = vector<vector<char> >(n, vector<char>(m));
        for (int j = 0; j < n; ++j) {
            cin >> row;
            for (int k = 0; k < m; ++k) {
                if (row[k] == '*') {
                    b[j][k] = '*';
                    continue;
                } 
                b[j][k] = '0';
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (b[j][k] == '*') {
                    continue;
                }
                if (j - 1 >= 0 && k - 1 >= 0 && b[j - 1][k - 1] == '*') {
                    ++b[j][k];
                }
                if (j - 1 >= 0 && b[j - 1][k] == '*') {
                    ++b[j][k];
                }
                if (j - 1 >= 0 && k + 1 < m && b[j - 1][k + 1] == '*') {
                    ++b[j][k];
                }
                if (k - 1 >= 0 && b[j][k - 1] == '*') {
                    ++b[j][k];
                }
                if (k + 1 < m && b[j][k + 1] == '*') {
                    ++b[j][k];
                }
                if (j + 1 < n && k - 1 >= 0 && b[j + 1][k - 1] == '*') {
                    ++b[j][k];
                }
                if (j + 1 < n && b[j + 1][k] == '*') {
                    ++b[j][k];
                }
                if (j + 1 < n && k + 1 < m && b[j + 1][k + 1] == '*') {
                    ++b[j][k];
                }
            }
        }
        cout << "Field #" << i << ":" << endl;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cout << b[j][k];
            }
            cout << endl;
        }
        ++i;
    }
    return 0;
}
