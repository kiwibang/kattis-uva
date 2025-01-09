#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, idx = 0;
    string dirs = "";
    cin >> h; 
    if (cin.eof()) {
        goto pr;
    }
    cin >> dirs;
    for (int i = 0; i < dirs.size(); ++i) {
        if (dirs[i] == 'L') {
            idx = (idx << 1) + 1;
        } else {
            idx = (idx << 1) + 2;
        }
    }
    pr:
    cout << (1 << (h + 1)) - 1 - idx << endl;
    return 0;
}

