#include <bits/stdc++.h>
using namespace std;

bool checkWinner(vector<vector<int> >& bingo) {
    // check rows
    for (int j = 0; j < 5; ++j) {
        bool allZeroes = true;
        for (int i = 0; i < 5; ++i) {
            if (bingo[i][j] != 0) {
                allZeroes = false;
                break;
            }
        }
        if (allZeroes) {
            return true;
        }
    }
    // check cols
    for (int i = 0; i < 5; ++i) {
        bool allZeroes = true;
        for (int j = 0; j < 5; ++j) {
            if (bingo[i][j] != 0) {
                allZeroes = false;
                break;
            }
        }
        if (allZeroes) {
            return true;
        }
    }
    // check diagonal
    return (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) || (bingo[4][0] == 0 && bingo[3][1] == 0 && bingo[1][3] == 0 && bingo[0][4] == 0);
}

int main() {
    int n;
    cin >> n;
    for (int tc = 0; tc < n; ++tc) {
        vector<vector<int> > bingo = vector<vector<int> >(5, vector<int>(5, 0));
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == 2 && j == 2) {
                    continue;
                }
                cin >> bingo[i][j];
            }
        }
        int w = -1;
        for (int i = 1; i <= 75; ++i) {
            int num;
            cin >> num;
            if (w != -1) {
                continue;
            }
            if (1 <= num && num <= 15) {
                for (int r = 0; r < 5; ++r) {
                    if (bingo[r][0] == num) {
                        bingo[r][0] = 0;
                        break;
                    }
                }
            } else if (16 <= num && num <= 30) {
                for (int r = 0; r < 5; ++r) {
                    if (bingo[r][1] == num) {
                        bingo[r][1] = 0;
                        break;
                    }
                }
            } else if (31 <= num && num <= 45) {
                for (int r = 0; r < 5; ++r) {
                    if (bingo[r][2] == num) {
                        bingo[r][2] = 0;
                        break;
                    }
                }
            } else if (46 <= num && num <= 60) {
                for (int r = 0; r < 5; ++r) {
                    if (bingo[r][3] == num) {
                        bingo[r][3] = 0;
                        break;
                    }
                }
            } else if (61 <= num && num <= 75) {
                for (int r = 0; r < 5; ++r) {
                    if (bingo[r][4] == num) {
                        bingo[r][4] = 0;
                        break;
                    }
                }
            }
            if (checkWinner(bingo)) {
                w = i;
            }
        }
        cout << "BINGO after " << w << " numbers announced" << endl;
    }
    return 0;
}
