#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // get the input
        int k, q, t;
        cin >> k >> q >> t;
        if (cin.eof()) {
            return 0;
        }

        // check illegal state
        if (k == q) {
            cout << "Illegal state" << endl;
            continue;
        }

        // check illegal move
        // get target coords
        int tx = t / 8;
        int ty = t % 8;
        int qx = q / 8;
        int qy = q % 8;
        int kx = k / 8;
        int ky = k % 8;
        // if move diagonally or target is where the queen is (nvr move) or target is where the king is
        if ((tx != qx && ty != qy) || q == t) {
            cout << "Illegal move" << endl;
            continue;
        }

        if ((kx == qx && kx == tx) || ((ky == qy && ky == ty))) {
            // if need to cross the king to reach the target
            if (min(q, t) <= k && k <= max(q, t)) {
                cout << "Illegal move" << endl;
                continue;
            }
        }

        // get traversal distance from king to target
        int traverseDist = max(k, t) - min(k, t);
        // check if end up at a position the king can move to 
        // traverseDist == 8 means move up or down 8 units
        // traverseDist == 1 AND target pos same row as king means target adj to king => illegal
        if (traverseDist == 8 || (traverseDist == 1 && tx == kx)) {
            cout << "Move not allowed" << endl;
            continue;
        }
        // check whether king is locked in
        if ((k == 0 && t == 9) || (k == 7 && t == 14) || (k == 56 && t == 49) || (k == 63 && t == 54))  {
            cout << "Stop" << endl;
            continue;
        }
        cout << "Continue" << endl;
    }
}
