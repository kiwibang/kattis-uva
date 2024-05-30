#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    while (true) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
            return 0;
        }
        // same curr pos and target pos
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            continue;
        }
        int xdelta = abs(x1 - x2);
        int ydelta = abs(y1 - y2);
        // if can reach in 1 move (either diagonally or vertically or horizontally)
        if (xdelta == ydelta || x1 == x2 || y1 == y2) {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}
