#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr = "", prev = "";
    int n, player = 0, lost = 0, lostplayer;
    cin >> n;
    unordered_set<string> called;
    for (int i = 0; i < n; ++i) {
        prev = curr;
        cin >> curr;
        if (lost) continue;
        if (called.find(curr) != called.end() || (prev != "" && prev[prev.size() - 1] != curr[0])) {
            lost = 1, lostplayer = player;
        } 
        called.insert(curr);
        player ^= 1; 
    }
    pr:
    if (lost) {
            cout << "Player ";
            if (lostplayer) {
                cout << "2";
            } else {
                cout << "1";
            }
            cout << " lost" << endl;
    } else {
        cout << "Fair Game" << endl;
    }
    return 0;
}

