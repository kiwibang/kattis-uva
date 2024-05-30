#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int t, n;
        cin >> t >> n;
        for (int i = 0; i < t; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            // case where different colour
            if (((x1 + y1 + x2 + y2) & 1) == 1) {
                cout << "no move" << endl;
                continue;
            }
            // curr pos and target pos the same
            if (x1 == x2 && y1 == y2) {
                cout << 0 << endl;
                continue;
            }
            int xdelta = abs(x1 - x2);
            int ydelta = abs(y1 - y2);
            // 1 move
            if (xdelta == ydelta) {
                cout << 1 << endl;
                continue;
            }
            // 2 move
            if (((xdelta & 1) == 0 && (ydelta & 1) == 0) || ((xdelta & 1) == 1 && (ydelta & 1) == 1)) {
                cout << 2 << endl;
                continue;
            }
            cout << "no move" << endl;
        }
    }
    return 0;
}
