#include <bits/stdc++.h>
using namespace std;

void printboard(vector<vector<char> >& b) {
    cout << "********************" << endl;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
            cout << b[i][j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> t;
    getline(cin, line); // read in the blank line
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        getline(cin, line);
        istringstream iss(line);
        // read the number of years to run the simulation
        int yrs;
        iss >> yrs;
        // board
        vector<vector<char> > b(21, vector<char>(21, ' '));
        // read the initial locations of the living quarters
        while (true) {
            getline(cin, line);
            // if blank line, means end of the current testcase => break
            if (line.empty()) {
                break;
            }
            istringstream iss(line);
            int x, y;
            iss >> x >> y;
            b[x][y] = 'O';
        }
        // print the year 1 configuration
        int ye = 1;
        printboard(b);
        ++ye;
        // run the simulations
        while (ye <= yrs) {
            vector<vector<char> > te(21, vector<char>(21, ' '));
            // loop over the cells
            for (int i = 1; i <= 20; ++i) {
                for (int j = 1; j <= 20; ++j) {
                    te[i][j] = b[i][j];
                    // count the number of neighbours
                    int numn = 0;
                    if (i - 1 >= 1 && b[i - 1][j] == 'O') {
                        ++numn;
                    }
                    if (i + 1 <= 20 && b[i + 1][j] == 'O') {
                        ++numn;
                    }
                    if (j - 1 >= 1 && b[i][j - 1] == 'O') {
                        ++numn;
                    }
                    if (j + 1 <= 20 && b[i][j + 1] == 'O') {
                        ++numn;
                    }
                    if (i - 1 >= 1 && j - 1 >= 1 && b[i - 1][j - 1] == 'O') {
                        ++numn;
                    }          
                    if (i + 1 <= 20 && j - 1 >= 1 && b[i + 1][j - 1] == 'O') {
                        ++numn;
                    }
                    if (i - 1 >= 1 && j + 1 <= 20 && b[i - 1][j + 1] == 'O') {
                        ++numn;
                    }          
                    if (i + 1 <= 20 && j + 1 <= 20 && b[i + 1][j + 1] == 'O') {
                        ++numn;
                    }
                    // check rule 1
                    if (b[i][j] == 'O' && (numn >= 4 || numn <= 1)) {
                        te[i][j] = ' ';
                        continue;
                    }
                    if (b[i][j] == ' ' && numn == 3) {
                        te[i][j] = 'O';
                    }
                }
            }
            b = te;
            // print the board
            printboard(b);
            ++ye;
        }
        cout << "********************" << endl;
    }
    return 0;
}
