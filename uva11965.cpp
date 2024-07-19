#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int lncnt;
        cin >> lncnt;
        cin.ignore();
        if (tc > 1) {
            cout << endl;
        }
        cout << "Case " << tc << ":" << endl;
        for (int j = 0; j < lncnt; ++j) {
            string line, tempres = "";
            getline(cin, line);
            for (int k = 0; k < line.size(); ++k) {
                if (line[k] == ' ') {
                    if (line[k] != line[k - 1]) {
                        tempres.push_back(' ');
                    }
                } else {
                    tempres.push_back(line[k]);
                }
            }
            cout << tempres << endl;
        }
    }
    return 0;
}
