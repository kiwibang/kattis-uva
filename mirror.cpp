#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int r, c;
        cin >> r >> c;
        vector<string> in(r);
        for (int i = 0; i < r; ++i) {
            cin >> in[i];
        }
        cout << "Test " << tc << endl;
        // start from the bottom row
        for (int i = r - 1; i >= 0; --i) {
            // start from the last char of the col
            for (int j = c - 1; j >= 0; --j) {
                cout << in[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
