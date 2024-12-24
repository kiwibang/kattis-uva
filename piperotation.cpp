#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the inputs
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<bool> fromtop(m, false);
    bool fromleft = false;
    for (int i = 0; i < n; ++i) cin >> grid[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char curr = grid[i][j];
            if (curr == 'A') {
                // case where need to connect from top or left
                if (fromtop[j] || fromleft) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                // else, dont need to connect from top or left => ok
                // we do not need to connect top nor left, so set respective booleans to false
                fromleft = false;
                fromtop[j] = false;
            } else if (curr == 'B') {
                // cant have both top or left, or none for just a straight pipe
                if ((fromtop[j] && fromleft) || (!fromtop[j] && !fromleft)) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                // else, it is either the case that we need to connect from top, or connect from left, but not both, do nothing because the booleans are set correctly already
            } else if (curr == 'C') {
                if (fromtop[j] && fromleft) { // both need to connect
                    fromtop[j] = false;
                    fromleft = false;
                } else if (!fromtop[j] && fromleft) { // only left
                    fromtop[j] = true;
                    fromleft = false;
                    // check if it is a bottom cell
                    if (i == n - 1) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                } else if (fromtop[j] && !fromleft) { // only top
                    fromtop[j] = false;
                    fromleft = true;
                    // check if it is a right cell
                    if (j == m - 1) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                } else { // neither need to connect
                    fromtop[j] = true;
                    fromleft = true;
                    // check if bottom or right cell
                    if (i == n - 1 || j == m - 1) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            } else if (curr == 'D') {
                // case where no need to connect top or connect left
                if (!fromtop[j] || !fromleft) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                // else, we need to connect top and left. booleans are already set correctly
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}

