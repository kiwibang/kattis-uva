#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> g(n, vector<string>(m, ""));
    // read in the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char cc;
            cin >> cc;
            g[i][j] += cc;
        }
    }
    // mark tree ring 1 first, and add to queue
    queue<pair<int, int> > q;
    set<pair<int, int> > vs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == "T" && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                g[i][j] = "1";
                q.push({i, j});
                vs.insert({i, j});
                continue;
            }
            if (g[i][j] == ".") {
                vs.insert({i, j});
                continue;
            }
            // check 4 cardinal directions
            if (i > 0 && g[i - 1][j] == ".") {
                g[i][j] = "1";
                q.push({i, j});
                vs.insert({i, j});
                continue;
            }
            if (i < n - 1 && g[i + 1][j] == ".") {
                g[i][j] = "1";
                q.push({i, j});
                vs.insert({i, j});
                continue;
            }
            if (j > 0 && g[i][j - 1] == ".") {
                g[i][j] = "1";
                q.push({i, j});
                vs.insert({i, j});
                continue;
            }
            if (j < m - 1 && g[i][j + 1] == ".") {
                g[i][j] = "1";
                q.push({i, j});
                vs.insert({i, j});
                continue;
            }
        }
    }
    int id = 1;
    while (!q.empty()) {
        int sz = q.size();
        ++id;
        for (int i = 0; i < sz; ++i) {
            pair<int, int> curr = q.front();
            int x = curr.first, y = curr.second;
            q.pop();
            // try the 4 cardinal directions
            if (x > 0 && vs.find({x - 1, y}) == vs.end()) {
                g[x - 1][y] = to_string(id);
                q.push({x - 1, y});
                vs.insert({x - 1, y});
            }
            if (x < n - 1 && vs.find({x + 1, y}) == vs.end()) {
                g[x + 1][y] = to_string(id);
                q.push({x + 1, y});
                vs.insert({x + 1, y});
            }
            if (y > 0 && vs.find({x, y - 1}) == vs.end()) {
                g[x][y - 1] = to_string(id);
                q.push({x, y - 1});
                vs.insert({x, y - 1});
            }
            if (y < m - 1 && vs.find({x, y + 1}) == vs.end()) {
                g[x][y + 1] = to_string(id);
                q.push({x, y + 1});
                vs.insert({x, y + 1});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (id >= 10) {
                while (g[i][j].size() < 3) g[i][j] = "." + g[i][j];
            } else {
                while (g[i][j].size() < 2) g[i][j] = "." + g[i][j];
            }
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}

