#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the dice throws
    vector<int> throws;
    while (true) {
        int dice;
        cin >> dice;
        if (dice == 0) {
            break;
        }
        throws.push_back(dice);
    }
    while (true) {
        // read the number of players in the game
        int n; // 1 < n < 6
        cin >> n;
        if (n == 0) {
            return 0;
        }
        // read the start and end position of every chute and ladder
        map<int, int> lc;
        while (true) {
            int src, dst;
            cin >> src >> dst;
            if (src == 0 && dst == 0) {
                break;
            }
            lc[src] = dst;
        }
        // read in the lose-a-turn/extra turn squares
        map<int, int> le;
        while (true) {
            int curr;
            cin >> curr;
            if (curr == 0) {
                break;
            }
            // 0 if lose a turn, 1 if extra turn
            le[abs(curr)] = curr < 0 ? 0 : 1;
        }
        // simulate the game; players are 0-indexed
        vector<int> playerscores = vector<int>(n, 0);
        vector<bool> missturn = vector<bool>(n, false);
        // track who is currently playingd
        int turn = 0;
        // track the current dice roll
        int rollidx = 0;
        // flag to check whether have winner or not
        int winner = 0;
        while (true) {
            // check whether the current player misses a turn or not. if so, change turn to the next player
            if (missturn[turn]) {
                missturn[turn] = false;
                turn = (turn + 1) % n;
                continue;
            }
            // roll the dice
            int currroll = throws[rollidx++];
            // check whether current player wins
            if (currroll + playerscores[turn] == 100) {
                winner = turn;
                break;
            }
            // update the score of the current player
            playerscores[turn] += currroll;
            // check if square landed on is a chute or ladder
            if (lc.find(playerscores[turn]) != lc.end()) {
                // update player position to the end of the chute or ladder
                playerscores[turn] = lc[playerscores[turn]];
            } else if (le.find(playerscores[turn]) != le.end()) { // check if square landed on is a lose-a-turn or gain a turn
                // check if lose-a-turn
                if (le[playerscores[turn]] == 0) {
                    missturn[turn] = true;
                } else if (le[playerscores[turn]] == 1) { // if gain a turn
                    // continue to next iteration without moving to the next player
                    continue;
                }
            }
            // update the turn to the next player 
            turn = (turn + 1) % n;
        }
        // print the winner
        cout << winner + 1 << endl;
    }
    return 0;
}
