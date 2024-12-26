#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y) {
    return 0 <= x && x < 5 && 0 < y && y < 5;
}
int main() {
    vector<string> grid(5);
    int numk = 0;
    for (int i = 0; i < 5; ++i) cin >> grid[i];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (grid[i][j] == '.') continue;
            ++numk;
            // try all 8 directions
            int cx = i - 1, cy = j - 2;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i - 2, cy = j - 1;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i - 2, cy = j + 1;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i - 1, cy = j + 2;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i + 1, cy = j + 2;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i + 2, cy = j + 1;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i + 2, cy = j - 1;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            cx = i + 1, cy = j - 2;
            if (isvalid(cx, cy)) {
                if (grid[cx][cy] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
        }
    }
    if (numk != 9) {
        cout << "invalid" << endl;
        return 0;
    }
    cout << "valid" << endl;
    return 0;
}

