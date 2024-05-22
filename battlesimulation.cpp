#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> sm;
    sm.insert("RBL");
    sm.insert("RLB");
    sm.insert("LRB");
    sm.insert("LBR");
    sm.insert("BLR");
    sm.insert("BRL");
    string moves;
    cin >> moves;
    int n = moves.length();
    for (int i = 0; i < n; ++i) {
        // check special move
        if (i + 2 < n && sm.find(moves.substr(i, 3)) != sm.end()) {
            cout << 'C';
            // shift i to next pos
            i += 2;
            continue;
        }
        if (moves[i] == 'R') {
            cout << 'S';
        } else if (moves[i] == 'B') {
            cout << 'K';
        } else if (moves[i] == 'L') {
            cout << 'H';
        }
    }
    cout << endl;
    return 0;
}
