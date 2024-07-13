#include <bits/stdc++.h>
using namespace std;

void cc(int x, int y, vector<vector<char> >& b, vector<vector<char> >& r, vector<vector<bool> >& vs) {
    if (x < 0 || x >= b.size() || y < 0 || y >= b[0].size() || vs[x][y]) {
        return;
    }
    r[x][y] = b[x][y];
}

void dfs(int x, int y, int& moves, vector<vector<char> >& b, vector<vector<char> >& r, vector<vector<bool> >& vs) {
    ++moves;
    vs[x][y] = true;
    // north
    if (x - 1 >= 0) {
        r[x - 1][y] = b[x - 1][y];
        if (b[x - 1][y] == '0' && !vs[x - 1][y]) {
            dfs(x - 1, y, moves, b, r, vs);
            goto x;
        }
    }
    // east 
    if (y + 1 < b[0].size()) {
        r[x][y + 1] = b[x][y + 1];
        if (b[x][y + 1] == '0' && !vs[x][y + 1]) {
            dfs(x, y + 1, moves, b, r, vs);
            goto x;
        }
    }
    // south
    if (x + 1 < b.size()) {
        r[x + 1][y] = b[x + 1][y];
        if (b[x + 1][y] == '0' && !vs[x + 1][y]) {
            dfs(x + 1, y, moves, b, r, vs);
            goto x;
        }
    }
    // west
    if (y - 1 >= 0) {
        r[x][y - 1] = b[x][y - 1];
        if (b[x][y - 1] == '0' && !vs[x][y - 1]) {
            dfs(x, y - 1, moves, b, r, vs);
            goto x;
        }
    }
    x:
    cc(x - 1, y, b, r, vs);
    cc(x + 1, y, b, r, vs);
    cc(x, y - 1, b, r, vs);
    cc(x, y + 1, b, r, vs);
} 

void printl(int m) {
    for (int i = 0; i < m; ++i) {
        cout << "|---";
    }
    cout << "|" << endl;
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int x, y;
        cin >> x >> y;
        vector<vector<char> > b(n, vector<char>(m, '\0'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }
        vector<vector<char> > roboview(n, vector<char>(m, '?'));
        vector<vector<bool> > vs(n, vector<bool>(m, false));
        int moves = 0;
        roboview[x - 1][y - 1] = '0';
        dfs(x - 1, y - 1, moves, b, roboview, vs);
        cout << endl;
        printl(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "| " << roboview[i][j] << " ";
            }
            cout << "|" << endl;
            printl(m);
        }
        cout << endl;
        cout << "NUMBER OF MOVEMENTS: " << moves - 1 << endl;
    }
    return 0;
}
