#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int n;
    int i, j;
    int c = 0;
    while (true) {
        ++c;
        cin >> line;
        if (cin.eof()) {
            return 0;
        }
        cout << "Case " << c << ":" << endl;
        cin >> n;
        for (int k = 0; k < n; ++k) {
            cin >> i >> j;
            int l = min(i, j);
            int r = max(i, j);
            char firstChar = line[l];
            bool isSame = true;
            for (int u = l + 1; u <= r; ++u) {
                char curr = line[u];
                if (firstChar != curr) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
