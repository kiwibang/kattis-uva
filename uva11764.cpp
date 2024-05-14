#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // get the number of walls
        int numWalls;
        cin >> numWalls;
        // get the first wall
        int currWall;
        cin >> currWall;
        // next wall; we need this variable later
        int nextWall;
        int lowJumps = 0;
        int highJumps = 0;
        // simulate jumping the walls; count high & low; start from wall 0
        for (int j = 0; j < numWalls - 1; ++j) {
            // get the next wall
            cin >> nextWall;
            // low jump
            if (currWall > nextWall) {
                ++lowJumps;
            } else if (currWall < nextWall) { // high jump
                ++highJumps;
            }
            // update the current wall
            currWall = nextWall;
        }
        // print the res
        cout << "Case " << i << ": " << highJumps << " " << lowJumps << endl;
    }
    return 0;
}
