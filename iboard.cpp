#include <bits/stdc++.h>
using namespace std;

vector<int> getnum(int c) {
    vector<int> res(2, 0);
    for (int i = 0; i < 7; ++i) {
        ++res[c & 1];
        c >>= 1;
    }
    return res;
}

int main() {
    string curr;
    while (true) {
        getline(cin, curr);
        if (cin.eof()) break;
        int nz = 0, no = 0;
        vector<int> count;
        for (int i = 0; i < curr.size(); ++i) {
            count = getnum(curr[i]);
            nz += count[0], no += count[1];
        }
        if ((nz % 2) == 0 && (no % 2) == 0) {
            cout << "free" << endl;
        } else {
            cout << "trapped" << endl;
        }
    }
    return 0;
}

