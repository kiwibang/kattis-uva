#include <bits/stdc++.h>
using namespace std;

bool lose(char a, char b) {
    if (a == b) {
        return false;
    }
    if (a == 'R' && b == 'P') {
        return true;
    } 
    if (a == 'P' && b == 'S') {
        return true;
    }
    if (a == 'S' && b == 'R') {
        return true;
    }
    return false;
}

vector<string> fightwar(vector<string>& b) {
    vector<string> res = b;
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            // up 
            vector<char> cmp;
            if (i - 1 >= 0) {
                cmp.push_back(b[i - 1][j]);
            }
            // down
            if (i + 1 < b.size()) {
                cmp.push_back(b[i + 1][j]);
            }
            // left
            if (j - 1 >= 0) {
                cmp.push_back(b[i][j - 1]);
            }
            // right
            if (j + 1 < b[0].size()) {
                cmp.push_back(b[i][j + 1]);
            }
            int w = b[i][j];
            for (auto cm : cmp) {
                if (lose(b[i][j], cm)) {
                    w = cm;
                }
            }
            res[i][j] = w;
        }
    }
    return res;
}

int main() {
    // read the number of testcases
    int t;
    cin >> t;
    // loop over the testcases
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        // read the dimensions of the board and the number of days
        int r, c, n;
        cin >> r >> c >> n;
        // read in the board
        vector<string> b;
        for (int i = 0; i < r; ++i) {
            string row;
            cin >> row;
            b.push_back(row);
        }
        // process the board
        for (int i = 1; i <= n; ++i) {
            b = fightwar(b);
        }
        // print the board
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << b[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
