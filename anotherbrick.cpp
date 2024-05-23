#include <bits/stdc++.h>
using namespace std;

int main() {
    // read the inputs
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> bricks;
    for (int i = 0; i < n; ++i) {
        int brick;
        cin >> brick;
        bricks.push_back(brick);
    }
    // simulate the brick laying process
    int bidx = 0;
    for (int i = 1; i <= h; ++i) {
        int currW = 0;
        while (currW < w) {
            // edge case: no more bricks, or, 
            // edge case (no pun intended): current brick is the edge brick
            // but cannot complete the edge of the current layer
            if (bidx == n || currW + bricks[bidx] > w) {
                cout << "NO" << endl;
                return 0;
            }
            currW += bricks[bidx++];
        }
    }
    cout << "YES" << endl;
    return 0;
}
