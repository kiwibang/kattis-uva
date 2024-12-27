#include <bits/stdc++.h>
using namespace std;

bool inrange(int x, int y, int lx, int ly) {
    return 0 <= x && x < lx && 0 <= y && y < ly;
}

int main() {
    // read in the inputs
    int m, n;
    char cc;
    string temp;
    cin >> m >> n >> temp;
    cc = temp[1];
    vector<vector<char>> f1(m, vector<char>(n));
    vector<vector<char>> f2(m, vector<char>(n));
    int x1 = m, y1 = n, x2 = m, y2 = n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> f1[i][j];
            if (f1[i][j] == cc) x1 = min(x1, i), y1 = min(y1, j);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> f2[i][j];
            if (f2[i][j] == cc) x2 = min(x2, i), y2 = min(y2, j);
        }
    }
    // overlay the surroundings
    int dx = x2 - x1, dy = y2 - y1;
    vector<vector<char>> res(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f1[i][j] != cc && f2[i][j] != cc) {
                res[i][j] = f1[i][j];
            } else if (f1[i][j] != cc && f2[i][j] == cc) {
                res[i][j] = f1[i][j];
            } else if (f1[i][j] == cc && f2[i][j] != cc) {
                res[i][j] = f2[i][j];
            }
        }
    }
    // extrapolate the sillhouette in frame 2 into the result
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f2[i][j] != cc) continue;
            int nx = i + dx, ny = j + dy;
            if (inrange(nx, ny, m, n)) {
                res[nx][ny] = cc;
            }
        }
    }
    // print the result
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}

