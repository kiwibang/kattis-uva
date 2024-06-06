#include <bits/stdc++.h>
using namespace std;

vector<string> getLegalMoves(vector<string>& b, int r, int c, char player) {
    vector<string> res;
    if (b[r][c] != '-') {
        return res;
    }
    char oppPlayer = player == 'W' ? 'B' : 'W';
    // check vertical
    // down
    if (r + 1 < 8 && b[r + 1][c] == oppPlayer) {
        for (int i = r + 2; i < 8; ++i) {
            if (b[i][c] == '-') {
                break;
            }
            if (b[i][c] == player) {
                res.push_back("DV");
                break;
            }
        }
    }
    // up
    if (r - 1 >= 0 && b[r - 1][c] == oppPlayer) {
        for (int i = r - 2; i >= 0; --i) {
            if (b[i][c] == '-') {
                break;
            }
            if (b[i][c] == player) {
                res.push_back("UV");
                break;
            }
        }
    }
    // check horizontal
    // right
    if (c + 1 < 8 && b[r][c + 1] == oppPlayer) {
        for (int j = c + 2; j < 8; ++j) {
            if (b[r][j] == '-') {
                break;
            }
            if (b[r][j] == player) {
                res.push_back("RH");
                break;
            }
        }
    }
    // left
    if (c - 1 >= 0 && b[r][c - 1] == oppPlayer) {
        for (int j = c - 2; j >= 0; --j) {
            if (b[r][j] == '-') {
                break;
            }
            if (b[r][j] == player) {
                res.push_back("LH");
                break;
            }
        }
    }
    // check diagonal
    // top left
    if (r - 1 >= 0 && c - 1 >= 0 && b[r - 1][c - 1] == oppPlayer) {
        int i = r - 2;
        int j = c - 2;
        while (i >= 0 && j >= 0) {
            if (b[i][j] == '-') {
                break;
            }
            if (b[i][j] == player) {
                res.push_back("TLD");
                break;
            }
            --i;
            --j;
        }
    }
    // top right
    if (r - 1 >= 0 && c + 1 < 8 && b[r - 1][c + 1] == oppPlayer) {
        int i = r - 2;
        int j = c + 2;
        while (i >= 0 && j < 8) {
            if (b[i][j] == '-') {
                break;
            }
            if (b[i][j] == player) {
                res.push_back("TRD");
                break;
            }
            --i;
            ++j;
        }
    }
    // bottom left
    if (r + 1 < 8 && c - 1 >= 0 && b[r + 1][c - 1] == oppPlayer) {
        int i = r + 2;
        int j = c - 2;
        while (i < 8 && j >= 0) {
            if (b[i][j] == '-') {
                break;
            }
            if (b[i][j] == player) {
                res.push_back("BLD");
                break;
            }
            ++i;
            --j;
        }
    }
    // bottom right
    if (r + 1 < 8 && c + 1 < 8 && b[r + 1][c + 1] == oppPlayer) {
        int i = r + 2;
        int j = c + 2;
        while (i < 8 && j < 8) {
            if (b[i][j] == '-') {
                break;
            }
            if (b[i][j] == player) {
                res.push_back("BRD");
                break;
            }
            ++i;
            ++j;
        }
    }
    return res;
}

void makeMove(vector<string>& b, int r, int c, vector<string>& moves, char player) {
    b[r][c] = player;
    // loop over the moves
    for (int k = 0; k < moves.size(); ++k) {
        string move = moves[k];
        if (move == "DV") {
            int i = r + 1;
            while (i < 8 && b[i][c] != player) {
                b[i][c] = player;
                ++i;
            }
        } else if (move == "UV") {
            int i = r - 1;
            while (i >= 0 && b[i][c] != player) {
                b[i][c] = player;
                --i;
            }
        } else if (move == "RH") {
            int j = c + 1;
            while (j < 8 && b[r][j] != player) {
                b[r][j] = player;
                ++j;
            }
        } else if (move == "LH") {
            int j = c - 1;
            while (j >= 0 && b[r][j] != player) {
                b[r][j] = player;
                --j;
            }
        } else if (move == "TLD") {
            int i = r - 1;
            int j = c - 1;
            while (i >= 0 && j >= 0 && b[i][j] != player) {
                b[i][j] = player;
                --i;
                --j;
            }
        } else if (move == "TRD") {
            int i = r - 1;
            int j = c + 1;
            while (i >= 0 && j < 8 && b[i][j] != player) {
                b[i][j] = player;
                --i;
                ++j;
            }
        } else if (move == "BLD") {
            int i = r + 1;
            int j = c - 1;
            while (i < 8 && j >= 0 && b[i][j] != player) {
                b[i][j] = player;
                ++i;
                --j;
            }
        } else if (move == "BRD") {
            int i = r + 1;
            int j = c + 1;
            while (i < 8 && j < 8 && b[i][j] != player) {
                b[i][j] = player;
                ++i;
                ++j;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        // read the current board
        vector<string> b; 
        for (int i = 0; i < 8; ++i) {
            string curr;
            cin >> curr;
            b.push_back(curr);
        }
        char player;
        cin >> player;
        string cmd;
        while (true) {
            cin >> cmd;
            if (cmd == "Q") {
                for (int i = 0; i < 8; ++i) {
                    cout << b[i] << endl;
                }
                break;
            }
            if (cmd == "L") {
                vector<string> poss;
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (b[i][j] == '-' && getLegalMoves(b, i, j, player).size() > 0) {
                            string curr = "";
                            curr.push_back('(');
                            curr.push_back(i + 1 + '0');
                            curr.push_back(',');
                            curr.push_back(j + 1 + '0');
                            curr.push_back(')');
                            poss.push_back(curr);
                        }
                    }
                }
                if (poss.size() == 0) {
                    cout << "No legal move." << endl;
                } else {
                    for (int i = 0; i < poss.size(); ++i) {
                        cout << poss[i];
                        if (i < poss.size() - 1) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            } else if (cmd[0] == 'M') {
                int r = cmd[1] - '0' - 1;
                int c = cmd[2] - '0' - 1;
                vector<string> moves = getLegalMoves(b, r, c, player);
                if (moves.size() == 0) {
                    player = player == 'W' ? 'B' : 'W';
                    moves = getLegalMoves(b, r, c, player);
                }
                makeMove(b, r, c, moves, player);
                int wc = 0, bc = 0;
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (b[i][j] == 'W') {
                            ++wc;
                        } else if (b[i][j] == 'B') {
                            ++bc;
                        }
                    }
                }
                player = player == 'W' ? 'B' : 'W';
                printf("Black - %2d White - %2d\n", bc, wc);
            }
        }
    }
    return 0;
}
