#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        int n;
        cin >> n;
        // read the mines
        vector<string> mineBoard;
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            mineBoard.push_back(row);
        }
        // read the moves
        bool touchedMine = false;
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < n; ++j) {
                // if have been touched and a mine
                if (row[j] == 'x' && mineBoard[i][j] == '*') {
                    touchedMine = true;
                    continue;
                }
                // if have been touched
                if (row[j] == 'x') {
                    // count the number of surrounding mines
                    int minesCount = 0;
                    // 4 cardinal directions
                    if (i - 1 >= 0 && mineBoard[i - 1][j] == '*') {
                        ++minesCount;
                    }
                    if (i + 1 < n && mineBoard[i + 1][j] == '*') {
                        ++minesCount;
                    }
                    if (j - 1 >= 0 && mineBoard[i][j - 1] == '*') {
                        ++minesCount;
                    }
                    if (j + 1 < n && mineBoard[i][j + 1] == '*') {
                        ++minesCount;
                    }
                    // 4 diagonal directions
                    if (i - 1 >= 0 && j - 1 >= 0 && mineBoard[i - 1][j - 1] == '*') {
                        ++minesCount;
                    }
                    if (i - 1 >= 0 && j + 1 < n && mineBoard[i - 1][j + 1] == '*') {
                        ++minesCount;
                    }
                    if (i + 1 < n && j - 1 >= 0 && mineBoard[i + 1][j - 1] == '*') {
                        ++minesCount;
                    }
                    if (i + 1 < n && j + 1 < n && mineBoard[i + 1][j + 1] == '*') {
                        ++minesCount;
                    }
                    row[j] = minesCount + '0';
                }
            }
            res.push_back(row);
        }

        if (touchedMine) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mineBoard[i][j] == '*') {
                        res[i][j] = '*';
                    }
                }
            }
        }
        // print the final board
        for (int i = 0; i < n; ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
