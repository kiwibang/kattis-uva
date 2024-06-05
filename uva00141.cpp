#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > rotate(vector<vector<int> >& b) {
    int n = b.size();
    vector<vector<int> > res = vector<vector<int> >(n, vector<int>(n, 0));
    // rows become cols
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[j][n - i - 1] = b[i][j];
        }
    }
    return res;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        vector<vector<int> > currboard = vector<vector<int> >(n, vector<int>(n, 0));
        set<vector<vector<int> > > seenboards;
        int winner = -1;
        int winningmove = 0;
        int player = 0;
        for (int i = 0; i < 2 * n; ++i) {
            int x, y;
            char move;
            cin >> x >> y >> move;
            if (winner != -1) {
                continue;
            }
            if (move == '+') {
                currboard[x - 1][y - 1] = 1;
            } else {
                currboard[x - 1][y - 1] = 0;
            }
            if (seenboards.find(currboard) != seenboards.end()) {
                winner = 1 - player;
                winningmove = i;
                continue;
            }
            vector<vector<int> > d90 = rotate(currboard);
            vector<vector<int> > d180 = rotate(d90);
            vector<vector<int> > d270 = rotate(d180);
            seenboards.insert(currboard);
            seenboards.insert(d90);
            seenboards.insert(d180);
            seenboards.insert(d270);
            player = 1 - player;
        }
        if (winner == -1) { 
            cout << "Draw" << endl;
        } else {
            cout << "Player " << winner + 1 << " wins on move " << winningmove + 1 << endl;
        }
    }
    return 0;
}

