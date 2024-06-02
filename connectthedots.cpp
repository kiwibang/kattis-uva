#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 1;
    while (true) {
        if (cin.eof()) {
            return 0;
        }
        // read the input
        string line;
        vector<string> board;
        map<char, pair<int, int> > mp;
        for (int r = 0; ; ++r) {
            getline(cin, line);
            if (line.empty()) {
                break;
            }
            for (int c = 0; c < line.size(); ++c) {
                if (line[c] != '.') {
                    mp[line[c]] = pair<int, int>(r, c);
                }
            }
            board.push_back(line);
        }
        // connect the dots
        char prevDot = '0';
        for (int dot = 1; dot < 62; ++dot) {
            // get coordinates of previous dot
            int prevx = mp[prevDot].first;
            int prevy = mp[prevDot].second;
            // get coordinates of current dot
            char currDot = dot <= 9 ? dot + '0' : dot <= 35 ? dot + 'a' - 10 : dot + 'A' - 36;
            if (mp.find(currDot) == mp.end()) {
                break;
            }
            int currx = mp[currDot].first;
            int curry = mp[currDot].second;
            // connect the dots
            if (prevx == currx) {
                for (int j = min(prevy, curry) + 1; j < max(prevy, curry); ++j) {
                    board[prevx][j] = board[prevx][j] == '|' ? '+' : board[prevx][j] != '.' ? board[prevx][j] : '-'; 
                }
            } else {
                for (int j = min(prevx, currx) + 1; j < max(prevx, currx); ++j) {
                    board[j][prevy] = board[j][prevy] == '-' ? '+' : board[j][prevy] != '.' ? board[j][prevy] : '|';
                }
            }
            prevDot = currDot;
        }
        // print out the result
        if (i > 1) {
            cout << endl;
        }
        for (int r = 0; r < board.size(); ++r) {
            cout << board[r] << endl;
        }
        ++i;
    }
    return 0;
}
