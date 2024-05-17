#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> p;
    string w[16];
    w[0] = "Happy";
    w[1] = "birthday";
    w[2] = "to";
    w[3] = "you";
    w[4] = "Happy";
    w[5] = "birthday";
    w[6] = "to";
    w[7] = "you";
    w[8] = "Happy";
    w[9] = "birthday";
    w[10] = "to";
    w[11] = "Rujia";
    w[12] = "Happy";
    w[13] = "birthday";
    w[14] = "to";
    w[15] = "you";
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        p.push_back(temp);
    }
    int i = 0;
    int count = n > 16 ? (int) ceil((double) n / 16) : 1;
    int idx = 0;
    // sing the song count times
    while (i++ < count) {
        for (int j = 0; j < 16; j++) {
            cout << p[idx] << ": " << w[j] << endl;
            idx = (idx + 1) % n;
        }
    }
    return 0;
}
