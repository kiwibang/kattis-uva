#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // get the input
        vector<string> rows;
        string line;
        getline(cin, line);
        size_t pos = 0;
        while ((pos = line.find("/")) != string::npos) {
            rows.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        rows.push_back(line.substr(0, pos));
        if (cin.eof()) {
            return 0;
        }
        vector<vector<char> > board(8, vector<char>(8, '0'));
        vector<vector<int> > isAttacked(8, vector<int>(8, 0));
        for (int i = 0; i < 8; ++i) {
            string currRow = rows[i];
            int rowIdx = 0;
            for (int j = 0; j < currRow.size(); ++j) {
                if (isdigit(currRow[j])) {
                    rowIdx += (currRow[j] - '0');
                } else {
                    board[i][rowIdx++] = currRow[j];
                }
            }
        }

        // loop over the board
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == '0') {
                    continue;
                }
                ++isAttacked[i][j];
                char ch = tolower(board[i][j]);
                int r, c;
                switch (ch) {
                    case 'r':
                        for (int k = i - 1; k >= 0; --k) {
                            ++isAttacked[k][j];
                            if (board[k][j] != '0') {
                                break;
                            }
                        }
                        for (int k = i + 1; k <= 7; ++k) {
                            ++isAttacked[k][j];
                            if (board[k][j] != '0') {
                                break;
                            }
                        }
                        for (int k = j - 1; k >= 0; --k) {
                            ++isAttacked[i][k];
                            if (board[i][k] != '0') {
                                break;
                            }
                        }
                        for (int k = j + 1; k <= 7; ++k) {
                            ++isAttacked[i][k];
                            if (board[i][k] != '0') {
                                break;
                            }
                        }
                        break;
                    case 'n':
                        // top left
                        if (i - 1 >= 0 && j - 2 >= 0) {
                            ++isAttacked[i - 1][j - 2];
                        }
                        if (i - 2 >= 0 && j - 1 >= 0) {
                            ++isAttacked[i - 2][j - 1];
                        }
                        // top right
                        if (i - 1 >= 0 && j + 2 <= 7) {
                            ++isAttacked[i - 1][j + 2];
                        }
                        if (i - 2 >= 0 && j + 1 <= 7) {
                            ++isAttacked[i - 2][j + 1];
                        }
                        // bottom left
                        if (i + 1 <= 7 && j - 2 >= 0) {
                            ++isAttacked[i + 1][j - 2];
                        }
                        if (i + 2 <= 7 && j - 1 >= 0) {
                            ++isAttacked[i + 2][j - 1];
                        }
                        // bottom right
                        if (i + 1 <= 7 && j + 2 <= 7) {
                            ++isAttacked[i + 1][j + 2];
                        }
                        if (i + 2 <= 7 && j + 1 <= 7) {
                            ++isAttacked[i + 2][j + 1];
                        }
                        break;
                    case 'b':
                        r = i - 1;
                        c = j - 1;
                        // go upper left
                        while (r >= 0 && c >= 0) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            --r;
                            --c;
                        }
                        r = i - 1;
                        c = j + 1;
                        // go upper right
                        while (r >= 0 && c <= 7) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            --r;
                            ++c;
                        }
                        r = i + 1;
                        c = j - 1;
                        // go bottom left
                        while (r <= 7 && c >= 0) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            ++r;
                            --c;
                        }
                        r = i + 1;
                        c = j + 1;
                        // go bottom right
                        while (r <= 7 && c <= 7) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            ++r;
                            ++c;
                        }
                        break;
                    case 'q':
                        for (int k = i - 1; k >= 0; --k) {
                            ++isAttacked[k][j];
                            if (board[k][j] != '0') {
                                break;
                            }
                        }
                        for (int k = i + 1; k <= 7; ++k) {
                            ++isAttacked[k][j];
                            if (board[k][j] != '0') {
                                break;
                            }
                        }
                        for (int k = j - 1; k >= 0; --k) {
                            ++isAttacked[i][k];
                            if (board[i][k] != '0') {
                                break;
                            }
                        }
                        for (int k = j + 1; k <= 7; ++k) {
                            ++isAttacked[i][k];
                            if (board[i][k] != '0') {
                                break;
                            }
                        }
                        r = i - 1;
                        c = j - 1;
                        // go upper left
                        while (r >= 0 && c >= 0) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            --r;
                            --c;
                        }
                        r = i - 1;
                        c = j + 1;
                        // go upper right
                        while (r >= 0 && c <= 7) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            --r;
                            ++c;
                        }
                        r = i + 1;
                        c = j - 1;
                        // go bottom left
                        while (r <= 7 && c >= 0) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            ++r;
                            --c;
                        }
                        r = i + 1;
                        c = j + 1;
                        // go bottom right
                        while (r <= 7 && c <= 7) {
                            ++isAttacked[r][c];
                            if (board[r][c] != '0') {
                                break;
                            }
                            ++r;
                            ++c;
                        }
                        break;
                    case 'k':
                        // 4 cardinal directions
                        if (i - 1 >= 0) {
                            ++isAttacked[i - 1][j];
                        }
                        if (i + 1 <= 7) {
                            ++isAttacked[i + 1][j];
                        }
                        if (j - 1 >= 0) {
                            ++isAttacked[i][j - 1];
                        }
                        if (j + 1 <= 7) {
                            ++isAttacked[i][j + 1];
                        }
                        // diagonal
                        if (i - 1 >= 0 && j - 1 >= 0) {
                            ++isAttacked[i - 1][j - 1];
                        }
                        if (i - 1 >= 0 && j + 1 <= 7) {
                            ++isAttacked[i - 1][j + 1];
                        }
                        if (i + 1 <= 7 && j - 1 >= 0) {
                            ++isAttacked[i + 1][j - 1];
                        }
                        if (i + 1 <= 7 && j + 1 <= 7) {
                            ++isAttacked[i + 1][j + 1];
                        }
                        break;
                    case 'p':
                        if (board[i][j] == 'p') {
                            if (i + 1 <= 7 && j + 1 <= 7) {
                                ++isAttacked[i + 1][j + 1];
                            }
                            if (i + 1 <= 7 && j - 1 >= 0) {
                                ++isAttacked[i + 1][j - 1];
                            }
                        } else {
                            if (i - 1 >= 0 && j + 1 <= 7) {
                                ++isAttacked[i - 1][j + 1];
                            }
                            if (i - 1 >= 0 && j - 1 >= 0) {
                                ++isAttacked[i - 1][j - 1];
                            }
                        }
                        break;
                }
            }
        }

        // for (int i = 0; i < 8; ++i) {
        //     for (int j = 0; j < 8; ++j) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // count the number of unattacked spots
        int res = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (isAttacked[i][j] == 0) {
                    ++res;
                }
            }
        }
        // print the res
        cout << res << endl;
    }
    return 0;
}
