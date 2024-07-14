#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    string curr;
    for (int i = 0; i < r; ++i) {
        cin >> curr;
        vector<string> res(zr, "");
        if (cin.eof()) {
            break;
        }
        for (int j = 0; j < c; ++j) {
            string temp(zc, curr[j]);
            for (int k = 0; k < zr; ++k) {
                res[k] += temp;
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
