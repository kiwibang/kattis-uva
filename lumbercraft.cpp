#include <bits/stdc++.h>
using namespace std;

bool cmp(int x1, int y1, int x2, int y2, int cx, int cy) {
    float d1 = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)), d2 = sqrt((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy));
    // int d1 = abs(x1 - cx) + abs(y1 - cy), d2 = abs(x2 - cx) + abs(y2 - cy);
    if (d1 == d2) { // tie
        // take the most eastern
        // case where tie on the y-coordinates. 
        if (y1 == y2) {
            // take the southernmost
            return x1 > x2;
        }
        // else, just take the most eastern tree
        return y1 > y2;
    }
    // no tie in distance, return the smallest one
    return d1 < d2;
}

int main() {
    int n, h, w, cn = 0;;
    // read in each testcase
    while (true) {
        cin >> n >> h >> w;
        // break condition
        if (!(n | h | w )) break;
        if (cn++) cout << endl;
        // read in the grid
        vector<string> grid(h);
        vector<char> players;
        vector<pair<int, int> > playercoords(26);
        vector<double> playerscore(26, 0.0);
        vector<pair<int, int> > trees;
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
            for (int j = 0; j < w; ++j) {
                if (isalpha(grid[i][j])) {
                    players.push_back(grid[i][j]);
                    playercoords[grid[i][j] - 'A'] = pair<int, int>(i, j);
                } else if (grid[i][j] == '!') {
                    trees.push_back(pair<int, int>(i, j));
                }
            }
        }
        // vector<bool> chopped(trees.size(), false);
        sort(players.begin(), players.end());
        // simulate the rounds
        while (n--) {
            if (trees.size() == 0) break;
            // make a map of tree coords to players
            map<pair<int, int>, vector<char> > treem;
            // loop over the players
            for (int i = 0; i < players.size(); ++i) {
                char cp = players[i];
                // get the coords of the current player's mill
                int px = playercoords[cp - 'A'].first, py = playercoords[cp - 'A'].second;
                // find the best tree
                pair<int, int> besttree = pair<int, int>(-1, -1);
                int chidx = -1;
                for (int j = 0; j < trees.size(); ++j) {
                    pair<int, int> tree = trees[j];
                    int tx = tree.first, ty = tree.second;
                    if (besttree.first == -1 || cmp(tx, ty, besttree.first, besttree.second, px, py)) { 
                        besttree = pair<int, int>(tree.first, tree.second);
                        chidx = j;
                    }
                }
                // add to map
                if (besttree.first != -1) {
                    if (treem.find(besttree) == treem.end()) {
                        treem[besttree] = vector<char>();
                    }
                    treem[besttree].push_back(cp);
                }
            }
            // update the player scores for the current round
            for (auto& p : treem) {
                pair<int, int> coords = p.first;
                trees.erase(remove(trees.begin(), trees.end(), coords), trees.end());
                vector<char> pa = p.second;
                double score = 1.0 / pa.size();
                for (char plyr : pa) {
                    playerscore[plyr - 'A'] += score;
                }
                // make into stump
                grid[coords.first][coords.second] = '.';
            }
        }
        // print the results
        for (string s : grid) {
            cout << s << endl;
        }
        for (char plyr : players) {
            cout << plyr << " " << fixed << setprecision(6) << playerscore[plyr - 'A'] << endl;
        }
    }
    return 0;
}
