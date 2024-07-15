#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> toprnt;
    int mx = 0;
    while (true) {
        string curr;
        getline(cin, curr);
        if (cin.eof()) {
            break;
        }
        mx = max(mx, (int) curr.size());
        toprnt.push_back(curr);
    }
    for (int j = 0; j < mx; ++j) {
        for (int i = toprnt.size() - 1; i >= 0; --i) {
            if (toprnt[i].size() > j) {
                cout << toprnt[i][j];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
