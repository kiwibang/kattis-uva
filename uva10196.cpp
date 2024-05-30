#include <bits/stdc++.h>
using namespace std;

int main() {
    int id = 1;
    while (true) {
        // get the input
        bool allDots = true;
        vector<vector<char> > board = vector<vector<char> >(8, vector<char>(8, '.'));
        for (int i = 0; i < 8; ++i) {
            string row;
            cin >> row;
            allDots = allDots && (row == "........");
            for (int j = 0; j < 8; ++j) {
                board[i][j] = row[j];
            }
        }
        if (allDots) {
            return 0;
        }
        // process the input
        vector<vector<int> > isAttacked = vector<vector<int> >(8, vector<int>(8, 0));
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                char cc = board[i][j];
                // diagonal attacks
                if (cc == 'p') {
                    if (i + 1 <= 7 && j - 1 >= 0 && board[i + 1][j - 1] != '.' && isupper(board[i + 1][j - 1])) {
                        ++isAttacked[i + 1][j - 1];
                    }
                    if (i + 1 <= 7 && j + 1 <= 7 && board[i + 1][j + 1] != '.' && isupper(board[i + 1][j + 1])) {
                        ++isAttacked[i + 1][j + 1];
                    }
                }
                if (cc == 'P') {
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != '.' && islower(board[i - 1][j - 1])) {
                        ++isAttacked[i - 1][j - 1];
                    }
                    if (i - 1 >= 0 && j + 1 <= 7 && board[i - 1][j + 1] != '.' && islower(board[i - 1][j + 1])) {
                        ++isAttacked[i - 1][j + 1];
                    }
                }
                // cross attacks
                if (cc == 'r' || cc == 'R' || cc == 'q' || cc == 'Q') {
                    // up 
                    int r = i - 1;
                    int c = j;
                    while (r >= 0) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        --r;
                    }
                    // down
                    r = i + 1;
                    c = j;
                    while (r <= 7) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        ++r;
                    }
                    // left
                    r = i;
                    c = j - 1;
                    while (c >= 0) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        --c;
                    }
                    // right
                    r = i;
                    c = j + 1;
                    while (c <= 7) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        ++c;
                    }
                }
                // diagonal attacks
                if (cc == 'b' || cc == 'B' || cc == 'r' || cc == 'R') {
                    int r = i - 1;
                    int c = j - 1;
                    while (r >= 0 && c >= 0) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        --r;
                        --c;
                    }
                    r = i - 1;
                    c = j + 1;
                    while (r >= 0 && c <= 7) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        --r;
                        ++c;
                    }
                    r = i + 1;
                    c = j - 1;
                    while (r <= 7 && c >= 0) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        ++r;
                        --c;
                    }
                    r = i + 1;
                    c = j + 1;
                    while (r <= 7 && c <= 7) {
                        // friendly fire
                        if (board[r][c] != '.' && ((islower(cc) && islower(board[r][c])) || (isupper(cc) && isupper(board[r][c])))) {
                            break;
                        }
                        ++isAttacked[r][c];
                        if (board[r][c] != '.') {
                            break;
                        }
                        ++r;
                        ++c;
                    }
                }
                if (cc == 'k' || cc == 'K') {
                    // cardinal direction
                    if (i - 1 >= 0 && board[i - 1][j] != '.' && ((islower(cc) && isupper(board[i - 1][j])) || (isupper(cc) && islower(board[i - 1][j])))) {
                        ++isAttacked[i - 1][j];
                    }
                    if (i + 1 <= 7 && board[i + 1][j] != '.' && ((islower(cc) && isupper(board[i + 1][j])) || (isupper(cc) && islower(board[i + 1][j])))) {
                        ++isAttacked[i + 1][j];
                    }
                    if (j - 1 >= 0 && board[i][j - 1] != '.' && ((islower(cc) && isupper(board[i][j - 1])) || (isupper(cc) && islower(board[i][j - 1])))) {
                        ++isAttacked[i][j - 1];
                    }
                    if (j + 1 <= 7 && board[i][j + 1] != '.' && ((islower(cc) && isupper(board[i][j + 1])) || (isupper(cc) && islower(board[i][j + 1])))) {
                        ++isAttacked[i][j + 1];
                    }
                    // diagonal direction
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != '.' && ((islower(cc) && isupper(board[i - 1][j - 1])) || (isupper(cc) && islower(board[i - 1][j - 1])))) {
                        ++isAttacked[i - 1][j - 1];
                    }
                    if (i - 1 >= 0 && j + 1 <= 7 && board[i - 1][j + 1] != '.' && ((islower(cc) && isupper(board[i - 1][j + 1])) || (isupper(cc) && islower(board[i - 1][j + 1])))) {
                        ++isAttacked[i - 1][j + 1];
                    }
                    if (i + 1 <= 7 && j - 1 >= 0 && board[i + 1][j - 1] != '.' && ((islower(cc) && isupper(board[i + 1][j - 1])) || (isupper(cc) && islower(board[i + 1][j - 1])))) {
                        ++isAttacked[i + 1][j - 1];
                    }
                    if (i + 1 <= 7 && j + 1 <= 7 && board[i + 1][j + 1] != '.' && ((islower(cc) && isupper(board[i + 1][j + 1])) || (isupper(cc) && islower(board[i + 1][j + 1])))) {
                        ++isAttacked[i + 1][j + 1];
                    }
                }
                if (cc == 'n' || cc == 'N') {
                    if (i - 2 >= 0 && j - 1 >= 0 && board[i - 2][j - 1] != '.' && ((islower(cc) && isupper(board[i - 2][j - 1])) || (isupper(cc) && islower(board[i - 2][j - 1])))) {
                        ++isAttacked[i - 2][j - 1];
                    }
                    if (i - 1 >= 0 && j - 2 >= 0 && board[i - 1][j - 2] != '.' && ((islower(cc) && isupper(board[i - 1][j - 2])) || (isupper(cc) && islower(board[i - 1][j - 2])))) {
                        ++isAttacked[i - 1][j - 2];
                    }
                    if (i - 2 >= 0 && j + 1 <= 7 && board[i - 2][j + 1] != '.' && ((islower(cc) && isupper(board[i - 2][j + 1])) || (isupper(cc) && islower(board[i - 2][j + 1])))) {
                        ++isAttacked[i - 2][j + 1];
                    }
                    if (i - 1 >= 0 && j + 2 <= 7 && board[i - 1][j + 2] != '.' && ((islower(cc) && isupper(board[i - 1][j + 2])) || (isupper(cc) && islower(board[i - 1][j + 2])))) {
                        ++isAttacked[i - 1][j + 2];
                    }
                    if (i + 2 <= 7 && j - 1 >= 0 && board[i + 2][j - 1] != '.' && ((islower(cc) && isupper(board[i + 2][j - 1])) || (isupper(cc) && islower(board[i + 2][j - 1])))) {
                        ++isAttacked[i + 2][j - 1];
                    }
                    if (i + 1 <= 7 && j - 2 >= 0 && board[i + 1][j - 2] != '.' && ((islower(cc) && isupper(board[i + 1][j - 2])) || (isupper(cc) && islower(board[i + 1][j - 2])))) {
                        ++isAttacked[i + 1][j - 2];
                    }
                    if (i + 2 <= 7 && j + 1 <= 7 && board[i + 2][j + 1] != '.' && ((islower(cc) && isupper(board[i + 2][j + 1])) || (isupper(cc) && islower(board[i + 2][j + 1])))) {
                        ++isAttacked[i + 2][j + 1];
                    }
                    if (i + 1 <= 7 && j + 2 <= 7 && board[i + 1][j + 2] != '.' && ((islower(cc) && isupper(board[i + 1][j + 2])) || (isupper(cc) && islower(board[i + 1][j + 2])))) {
                        ++isAttacked[i + 1][j + 2];
                    }
                }
            }
        }
        int check = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'k' && isAttacked[i][j] > 0) {
                    check = 1;
                } else if (board[i][j] == 'K' && isAttacked[i][j] > 0) {
                    check = -1;
                }
            }
        }
        cout << "Game #" << id << ": ";
        if (check == 1) {
            cout << "black";
        } else if (check == -1) {
            cout << "white";
        } else {
            cout << "no";
        }
        cout << " king is in check." << endl;
        ++id;
    }
    return 0;
}
