#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the inputs
    vector<string> board;
    for (int i = 0; i < 8; ++i) {
        string line;
        cin >> line;
        board.push_back(line);
    }
    string moves;
    cin >> moves;

    // loop over the moves, and track the position and direction the turtle is in
    int x = 7;
    int y = 0;
    int dir = 2; // 0 - front, 1 - left, 2 - right, 3 - bottom
    bool noBug = true;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == 'F') {
            // move the turtle forward
            if (dir == 0) {
                --x;
            } else if (dir == 1) {
                --y;
            } else if (dir == 2) {
                ++y;
            } else if (dir == 3) {
                ++x;
            }
            // check out of bounds or on any castle
            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'I' || board[x][y] == 'C') {
                noBug = false;
                cout << "Bug!" << endl;
                break;
            }
        } else if (moves[i] == 'L') {
            // change the turtle's position
            if (dir == 0) {
                dir = 1;
            } else if (dir == 1) {
                dir = 3;
            } else if (dir == 2) {
                dir = 0;
            } else if (dir == 3) {
                dir = 2;
            }
        } else if (moves[i] == 'R') {
            // change the turtle's position
            if (dir == 0) {
                dir = 2;
            } else if (dir == 1) {
                dir = 0;
            } else if (dir == 2) {
                dir = 3;
            } else if (dir == 3) {
                dir = 1;
            }
        } else if (moves[i] == 'X') {
            // fire at adjacent tiles
            if (dir == 0) {
                if (x - 1 >= 0) {
                    if (board[x - 1][y] == '.' || board[x - 1][y] == 'C') {
                        noBug = false;
                        cout << "Bug!" << endl;
                        break;
                    } else {
                        board[x - 1][y] = '.';
                    }
                } else {
                    noBug = false;
                    cout << "Bug!" << endl;
                    break;
                }
            } else if (dir == 1) {
                if (y - 1 >= 0) {
                    if (board[x][y - 1] == '.' || board[x][y - 1] == 'C') {
                        noBug = false;
                        cout << "Bug!" << endl;
                        break;
                    } else {
                        board[x][y - 1] = '.';
                    }
                } else {
                    noBug = false;
                    cout << "Bug!" << endl;
                    break;
                }
            } else if (dir == 2) {
                if (y + 1 <= 7) {
                    if (board[x][y + 1] == '.' || board[x][y + 1] == 'C') {
                        noBug = false;
                        cout << "Bug!" << endl;
                        break;
                    } else {
                        board[x][y + 1] = '.';
                    }
                } else {
                    noBug = false;
                    cout << "Bug!" << endl;
                    break;
                }
            } else if (dir == 3) {
                if (x + 1 <= 7) {
                    if (board[x + 1][y] == '.' || board[x + 1][y] == 'C') {
                        noBug = false;
                        cout << "Bug!" << endl;
                        break;
                    } else {
                        board[x + 1][y] = '.';
                    }
                } else {
                    noBug = false;
                    cout << "Bug!" << endl;
                    break;
                }
            }
        }
    }
    if (noBug && board[x][y] != 'D') {
        cout << "Bug!" << endl;
        return 0;
    }
    if (noBug) {
        cout << "Diamond!" << endl;
    }
    return 0;
}
