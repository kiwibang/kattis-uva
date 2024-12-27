#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for (int i = 0; i < r; ++i) cin >> g[i];
    for (int j = 0; j < c; ++j) {
        int dest = r - 1;
        bool metp = false;
        for (int i = r - 1; i >= 0; --i) {
            if (g[i][j] == '.') {
                if (!metp) dest = i;
                metp = true;
                continue;
            }
            if (g[i][j] == '#') {
                dest = i - 1;
                metp = false;
                continue;
            }
            // current is apple
            g[dest][j] = 'a';
            if (dest != i) g[i][j] = '.';
            --dest; // destination moves up by 1
            metp = true;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cout << g[i][j];
        cout << endl;
    }
    return 0;
}

