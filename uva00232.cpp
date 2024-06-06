#include <bits/stdc++.h>
using namespace std;

// checks if the given white cell is eligible based on qn definition
bool isEligible(vector<string>& cw, int r, int c) {
    // left or above square is a black square => eligible 
    if ((c - 1 >= 0 && cw[r][c - 1] == '*') || (r - 1 >= 0  && cw[r - 1][c] == '*')) {
        return true;
    }
    // no square to the left or no squares above => eligible
    if (c == 0 || r == 0) {
        return true;
    }
    return false;
}

int main() {
    int tc = 1;
    while (true) {
        // get the dimensions of the crossword
        int r, c;
        cin >> r;
        if (r == 0) {
            return 0;
        }
        cin >> c;
        if (tc > 1) {
            cout << endl;
        }
        // get the actual crossword board
        vector<string> cw;
        for (int i = 0; i < r; ++i) {
            string curr;
            cin >> curr;
            cw.push_back(curr);
        }
        // get the list of across and down words
        vector<pair<int, string> > across, down;
        vector<bool> aok(r, true);
        vector<bool> dok(c, true); 
        int wordID = 1;
        // loop over the board, and find the eligible squares
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (cw[i][j] == '*') {
                    aok[i] = true;
                    dok[j] = true;
                    continue;
                }
                // case where the current cell is eligible
                if (isEligible(cw, i, j)) {
                    // get across (if any)
                    if (aok[i]) {
                        // we cannot form another word in the same row unless there is a black square
                        aok[i] = false;
                        // form the current across word
                        string curr = "";
                        int k = j;
                        while (k < c) {
                            if (cw[i][k] == '*') {
                                break;
                            }
                            curr.push_back(cw[i][k]);
                            ++k;
                        }
                        // add the current across word with its corresponding word id
                        across.push_back(pair<int, string>(wordID, curr));
                    }
                    // get down (if any)
                    if (dok[j]) {
                        // we cannot form a word in the same col unless there is a black square down the line
                        dok[j] = false;
                        // form the current down word
                        string curr = "";
                        int k = i;
                        while (k < r) {
                            if (cw[k][j] == '*') {
                                break;
                            }
                            curr.push_back(cw[k][j]);
                            ++k;
                        }
                        down.push_back(pair<int, string>(wordID, curr));
                    }
                    // update the wordID
                    ++wordID;
                }
            }
        }
        // print out the results
        cout << "puzzle #" << tc << ":" << endl;
        cout << "Across" << endl;
        for (int i = 0; i < across.size(); ++i) {
            cout << setw(3) << across[i].first << "." << across[i].second << endl;
        }
        cout << "Down" << endl;
        for (int i = 0; i < down.size(); ++i) {
            cout << setw(3) << down[i].first << "." << down[i].second << endl;
        }
        ++tc;
    }
    return 0;
}
