#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string msg;
        int idx = 0;
        cin >> msg;
        int l = msg.size();
        vector<vector<char> > b((int) sqrt(l), vector<char>((int) sqrt(l), '\0'));
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                b[i][j] = msg[idx++];
            }
        }
        for (int j = b.size() - 1; j >= 0; --j) {
            for (int i = 0; i < b.size(); ++i) {
                cout << b[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
