#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string cl;
        getline(cin, cl);
        // check size of string is a square number
        double sq = sqrt(cl.size());
        int w = sqrt(cl.size());
        if (sq != w) {
            cout << "INVALID" << endl;
            continue;
        }
        vector<vector<char> > b(w, vector<char>(w, '\0'));
        int idx = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                b[i][j] = cl[idx++];
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int i = 0; i < w; ++i) {
                cout << b[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
