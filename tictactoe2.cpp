#include <bits/stdc++.h>
using namespace std;

// credits: https://github.com/mpfeifer1/Kattis/blob/master/tictactoe2.cpp (couldnt do it myself)
set<vector<string> > s;
bool checkWin(vector<string>& v) {
    if(v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != '.') {
        return true;
    }
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '.') {
        return true;
    }
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '.') {
        return true;
    }

    if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '.') {
        return true;
    }
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '.') {
        return true;
    }
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '.') {
        return true;
    }

    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.') {
        return true;
    }
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.') {
        return true;
    }

    return false;
}

void generateCombinations(vector<string>& v, char c) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(v[i][j] == '.') {
                // Add char
                v[i][j] = c;

                // Add to set
                s.insert(v);

                // If no win, keep going
                if(!checkWin(v)) {
                    if(c == 'X') {
                        generateCombinations(v, 'O');
                    }
                    else {
                        generateCombinations(v, 'X');
                    }
                }

                // Remove char
                v[i][j] = '.';
            }

        }
    }
}
int main() {
    // generate all possible valid combinations of the tictactoe board
    vector<string> base;
    base.push_back("...");
    base.push_back("...");
    base.push_back("...");
    s.insert(base);
    generateCombinations(base, 'X');

    int t;
    cin >> t;
    while (t--) {
        // then, read in the current board
        vector<string> board;
        for (int i = 0; i < 3; ++i) {
            string line;
            cin >> line;
            board.push_back(line);
        }
        // check validity - valid iff inside the set of valid tictactoe boards
        if (s.count(board) > 0) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
