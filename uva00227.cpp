#include <bits/stdc++.h>
using namespace std;

void swap(vector<string>& b, int x1, int y1, int x2, int y2) {
    char t = b[x1][y1];
    b[x1][y1] = b[x2][y2];
    b[x2][y2] = t;
}

int main() {
    int tc = 1;
    while (true) {
        // read in the board
        vector<string> b;
        string curr;
        // line 1
        getline(cin, curr);
        if (curr[0] == 'Z') {
            return 0;
        }
        if (tc > 1) {
            cout << endl;
        }
        if (curr.size() == 4) {
            curr.push_back(' ');
        }
        b.push_back(curr);
        for (int i = 0; i < 4; ++i) {
            getline(cin, curr);
            if (curr.size() == 4) {
                curr.push_back(' ');
            }
            b.push_back(curr);
        }
        // look for the empty square
        int x = -1, y;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (b[i][j] == ' ') {
                    x = i;
                    y = j;
                    break;
                }
                if (b[i].length() == 4) {
                    x = i;
                    y = 4;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }
        // read in the moves
        vector<string> moves;
        string move;
        while (true) {
            getline(cin, move);
            moves.push_back(move);
            if (move[move.size() - 1] == '0') {
                break;
            }
        }
        // simulate the moves, if illegal move (i.e. square does not exist), then break
        bool isIllegal = false;
        for (int i = 0; i < moves.size(); ++i) {
            string currMove = moves[i];
            for (int j = 0; j < currMove.size(); ++j) {
                char move = currMove[j];
                if (move == 'A') {
                    if (x - 1 < 0) {
                        isIllegal = true;
                        break;
                    }
                    swap(b, x, y, x - 1, y);
                    --x;
                } else if (move == 'B') {
                    if (x + 1 > 4) {
                        isIllegal = true;
                        break;
                    }
                    swap(b, x, y, x + 1, y);
                    ++x;
                } else if (move == 'L') {
                    if (y - 1 < 0) {
                        isIllegal = true;
                        break;
                    }
                    swap(b, x, y, x, y - 1);
                    --y;
                } else if (move == 'R') {
                    if (y + 1 > 4) {
                        isIllegal = true;
                        break;
                    }
                    swap(b, x, y, x, y + 1);
                    ++y;
                }
            }
            if (isIllegal) {
                break;
            }
        }
        // print the res
        cout << "Puzzle #" << tc << ":" << endl;
        if (isIllegal) {
            cout << "This puzzle has no final configuration." << endl;
        } else {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    cout << b[i][j];
                    if (j < 4) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        // update the test case count
        ++tc;
    }
}