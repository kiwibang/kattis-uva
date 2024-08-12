#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<string> instrs(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> instrs[i];
    }
    vector<vector<int> > dirs(4, vector<int>(2, 0));
    dirs[0][0] = 0;
    dirs[0][1] = 1;
    dirs[1][0] = 1;
    dirs[1][1] = 0;
    dirs[2][0] = 0;
    dirs[2][1] = -1;
    dirs[3][0] = -1;
    dirs[3][1] = 0;
    vector<string> possibleinstrs;
    possibleinstrs.push_back("Forward");
    possibleinstrs.push_back("Left");
    possibleinstrs.push_back("Right");
    // loop over the instrs, and assume each one is wrong
    for (int i = 0; i < n; ++i) {
        // replace the current instr with all other possible instrs and test if it leads to the goal
        for (int k = 0; k < 3; ++k) {
            // same instruction, skip. we assume that it is wrong in the first place
            if (possibleinstrs[k] == instrs[i]) {
                continue;
            }
            string temp = instrs[i];
            // sub the instr with the possible instruction
            instrs[i] = possibleinstrs[k];
            // track the coords of the robot as we simulate
            int cx = 0, cy = 0, face = 0;
            // loop over the instrs, simulate the movement of the robot
            for (int j = 0; j < n; ++j) {
                if (instrs[j] == "Left") {
                    --face;
                    if (face < 0) {
                        face = 3;
                    }
                } else if (instrs[j] == "Right") {
                    face = (face + 1) % 4;
                } else if (instrs[j] == "Forward") {
                    cx += dirs[face][0];
                    cy += dirs[face][1];
                }
            }
            // replace back
            instrs[i] = temp;
            // check if unique answer found
            if (cx == x && cy == y) {
                cout << (i + 1) << " " << possibleinstrs[k] << endl;
                return 0;
            }
        }
    }
    return 0;
}
