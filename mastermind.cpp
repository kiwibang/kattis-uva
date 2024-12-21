#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r = 0, s = 0;
    cin >> n;
    string code, guess;
    cin >> code >> guess;
    vector<int> cf(26, 0), gf(26, 0);
    for (int i = 0; i < n; ++i) {
        if (code[i] == guess[i]) {
            ++r;
            continue;
        }
        ++cf[code[i] - 'A'], ++gf[guess[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i) s += min(cf[i], gf[i]);
    cout << r << " " << s << endl;
    return 0;
}

