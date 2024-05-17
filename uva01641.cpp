#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> h >> w;
        char g[h][w];
        for (int i = 0; i < h; ++i) {
            cin >> g[i];
        }
        cin.ignore();
        double res = 0;
        for (int i = 0; i < h; ++i) {
            bool inP = false;
            for (int j = 0; j < w; ++j) {
                if (g[i][j] == '/' || g[i][j] == '\\') {
                    inP = !inP;
                    res += 0.5;
                } else if (inP) {
                    ++res;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
