#include <bits/stdc++.h>
using namespace std;

int getdir(int dir, char mirror) {
    if (mirror == '/') {
        if (dir == 0) {
            dir = 3;
        } else if (dir == 1) {
            dir = 2;
        } else if (dir == 2) {
            dir = 1;
        } else if (dir == 3) {
            dir = 0;
        }
    } else { // mirror is
        if (dir == 0) {
            dir = 2;
        } else if (dir == 1) {
            dir = 3;
        } else if (dir == 2) {
            dir = 0;
        } else if (dir == 3) {
            dir = 1;
        }
    }
    return dir;
}
int main() {
    int id = 1;
    while (true) {
        int w, l, cx, cy;
        cin >> w >> l;
        if (w == 0 && l == 0) break;
        vector<vector<char> > g(w, vector<char>(l));
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> g[i][j];
                if (g[i][j] == '*') cx = i, cy = j;
            }
        }
        // get initial directions
        int dir = cx == w - 1 ? 0 : cx == 0 ? 1 : cy == l - 1 ? 2 : 3;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // simulate
        bool reflected = false;
        while (true) {
            cx += dirs[dir][0], cy += dirs[dir][1];
            if (g[cx][cy] == 'x') {
                g[cx][cy] = '&';
                break;
            }
            // change dir
            if (g[cx][cy] == '/' || g[cx][cy] == '\\') {
                dir = getdir(dir, g[cx][cy]);
            }
        }
        // print
        cout << "HOUSE " << id++ << endl;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

