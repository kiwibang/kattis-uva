#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string msg;
        cin >> msg;
        int w = (int) ceil(sqrt((double) msg.size()));
        vector<vector<char> > b(w, vector<char>(w, '*'));
        int idx = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                if (idx >= msg.size()) {
                    break;
                }
                b[i][j] = msg[idx++];
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int i = w - 1; i >= 0; --i) {
                if (b[i][j] == '*') {
                    continue;
                }
                cout << b[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
