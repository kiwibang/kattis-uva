#include <bits/stdc++.h>
using namespace std;

int main() {
    int id = 0;
    while (true) {
        int r, c;
        cin >> r >> c;
        if (r == 0 && c == 0) break;
        if (id++ > 0) cout << endl;
        vector<string> g(r);
        for (int i = 0; i < r; ++i) cin >> g[i];
        vector<string> words;
        for (int j = 0; j < c; ++j) {
            string curr = "";
            for (int i = 0; i < r; ++i) {
                curr += g[i][j];
            }
            words.push_back(curr);
        } 
        for (int i = r - 1; i >= 0; --i) {
            vector<int> f(26, 0);
            for (int j = c - 1; j >= 0; --j) {
                ++f[tolower(words[j][i]) - 'a'];
            }
            for (int j = 1; j < 26; ++j) {
                f[j] += f[j - 1];
            }
            vector<string> w(c);
            for (int j = c - 1; j >= 0; --j) {
                int idx = tolower(words[j][i]) - 'a';
                w[f[idx] - 1] = words[j];
                --f[idx];
            }
            words = w;
        }
        vector<vector<char> > res(r, vector<char>(c)); 
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = words[j][i];
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

