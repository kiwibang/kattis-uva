#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int w, h, n;
        cin >> w >> h >> n;
        // player one
        int shipsCount[2] = {0, 0};
        char boards[2][30][30];
        for (int p = 0; p < 2; ++p) {
            for (int y = h - 1; y >= 0; --y) {
                string curr;
                cin >> curr;
                for (int x = 0; x < w; ++x) {
                    boards[p][x][y] = curr[x];
                    if (curr[x] == '#') {
                        ++shipsCount[p];
                    }
                }
            }
        }

        // go over the shot orders, assuming player 1 starts shooting first
        int turn = 0; // 1 - player 1 turn, 2 - player 2 turn
        bool hasEnded = false;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (hasEnded) {
                continue;
            }
            if (boards[1 - turn][x][y] == '#') {
                boards[1 - turn][x][y] = ' ';
                --shipsCount[1 - turn];
                if (shipsCount[1 - turn] == 0) {
                    turn = 1 - turn;
                    if (turn == 0) {
                        hasEnded = true;
                    }
                }
            } else {
                turn = 1 - turn;
                if (turn == 0 && shipsCount[0] == 0 && shipsCount[1] == 0) {
                    hasEnded = true;
                }
            }
        }
        // if draw
        if ((shipsCount[0] == 0 && shipsCount[1] == 0) || (shipsCount[0] > 0 && shipsCount[1] > 0)) {
            cout << "draw" << endl;
        } else if (shipsCount[0] > 0 && shipsCount[1] == 0) {
            cout << "player one wins" << endl;
        } else if (shipsCount[0] == 0 && shipsCount[1] > 0) {
            cout << "player two wins" << endl;
        }
    }
    return 0;
}
