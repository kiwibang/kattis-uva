#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    string line;
    // collect grid data
    cin >> r >> c;
    cin.ignore();
    char g[r][c];
    for (int i = 0; i < r; ++i) {
        getline(cin, line);
        for (int j = 0; j < c; ++j) {
            g[i][j] = line[j];
        }
    }
    // simulate - start from first row and first col
    int x = 0;
    int y = 0;
    int count = 0;
    while (true) {
        // check out of bounds
        if (x < 0 || x >= r || y < 0 || y >= c) {
            cout << "Out." << endl;
            return 0;
        }
        // check lost
        if (count > r * c * 2) {
            cout << "Lost." << endl;
            return 0;
        }
        // check treasure
        if (g[x][y] == 'T') {
            cout << count << endl;
            return 0;
        }
        // update coords
        char curr = g[x][y];
        x = curr == 'N' ? x - 1 : curr == 'S' ? x + 1 : x;
        y = curr == 'E' ? y + 1 : curr == 'W' ? y - 1 : y;
        ++count;
    }
    return 0;
}
