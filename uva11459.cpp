#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> mp(101, 0);
        for (int j = 0; j < b; ++j) {
            // get the start and end of the teleporter (snake or ladder)
            // start is either snake mouth or bottom ladder
            // end is either snake tail or top ladder
            int start, end;
            cin >> start >> end;
            mp[start] = end;
        }
        vector<int> poss = vector<int>(a, 1);
        bool hasEnded = false;
        for (int j = 0; j < c; ++j) {
            // get current dice roll
            int dice;
            cin >> dice;
            // case where player reached end already
            if (hasEnded) {
                continue; 
            }
            int turn = j % a;
            // update current player position
            poss[turn] += dice;
            // check if new position is at snake mouth or ladder bottom
            if (mp[poss[turn]]) {
                // shift player position to snake tail or ladder top
                poss[turn] = mp[poss[turn]];
            }
            // game end check
            if (poss[turn] >= 100) {
                hasEnded = true;
                poss[turn] = 100;
            }
        }
        // then, print the positions of the players at the end of the game
        for (int j = 0; j < a; ++j) {
            cout << "Position of player " << j + 1 << " is " << poss[j] << "." << endl;
        }
    }
    return 0;
}
