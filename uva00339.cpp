#include <bits/stdc++.h>
using namespace std;

int m, n;
int cnt;
bool vs[10][40];
vector<vector<int> > b;
const int moves[][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

bool isInRange(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void dfs(int x, int y) {
    ++cnt;
    vs[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (ny < b.size() && nx < b[ny].size() && !vs[ny][nx] && b[y][x] == b[ny][nx]) {
            dfs(nx, ny);
        } 
    }
}

int main() {
    int tc = 1; 
    while (true) {
        // read in the dimensions of the grid
        cin >> m >> n;
        if (m == 0 && n == 0) {
            return 0;
        }
        if (tc > 1) {
            cout << endl;
        }
        // get the actual board
        b.clear();
        b = vector<vector<int> >(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> b[j][i];
            }
        }
        // read in the sequence of moves, and simulate
        while (true) {
            int r, c;
            cin >> r >> c;
            if (r == 0 && c == 0) {
                break;
            }
            --r;
            --c;
            // if out of range
            if (!isInRange(r, c)) {
                continue;
            }
            cnt = 0;
            memset(vs, false, sizeof vs);
            dfs(r, c);
            if (cnt > 1) {
                for (int i = b.size() - 1; i >= 0; --i) {
                    for (int j = b[i].size() - 1; j >= 0; --j) {
                        if (vs[i][j]) {
                            b[i].erase(b[i].begin() + j);
                        }
                    }
                    if (b[i].size() == 0) {
                        b.erase(b.begin() + i);
                    }
                }
            }
        }
        cout << "Grid " << tc << "." << endl;
        if (b.size() == 0) {
            cout << "    Game Won" << endl;
        } else {
            for (int i = m - 1; i >= 0; --i) {
                cout << "   ";
                for (int j = 0; j < n; ++j) {
                    if (b.size() > j && b[j].size() > i) {
                        cout << " " << b[j][i];
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
        ++tc;
    }
    return 0;
}
