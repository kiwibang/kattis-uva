#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string str;
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        vector<int> f(26, 0);
        int cnt = 0, idx;
        for (char c : str) {
            if (!isalpha(c)) continue;
            idx = tolower(c) - 'a';
            if (!f[idx]) ++cnt;
            ++f[idx];
        }
        if (cnt == 26) {
            cout << "pangram" << endl;
        } else {
            cout << "missing ";
            for (int i = 0; i < 26; ++i) if (!f[i]) cout << (char) (i + 'a');
            cout << endl;
       }
    }
    return 0;
}

