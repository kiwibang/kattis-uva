#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; ++tc) {
        string line;
        cin >> line;
        vector<int> temp(line.size() - 2, 0);
        for (int i = 0; i < 8; ++i) {
            char cc;
            cin >> cc;
            for (int j = 0; j < line.size() - 2; ++j) {
                cin >> cc;
                if (cc == '\\') {
                    temp[j] += (1 << i);
                }
            }
            cin >> cc;
        } 
        cin >> line;
        for (int i = 0; i < line.size() - 2; ++i) {
            cout << (char) temp[i];
        }
        cout << endl;
    }
    return 0;
}
