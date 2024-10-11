#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in L and W
    int l, w;
    cin >> l >> w;
    // create a grid that will store the cars
    vector<vector<bool> > g(l + 1, vector<bool>(w, false));
    // store the interval and speed data for all l lines
    vector<int> intervals(l);
    vector<int> speeds(l);
    // then read in the L lines
    for (int i = 0; i < l; ++i) {
        int o, iv, s;
        cin >> o >> iv >> s;
        // fill up the data table for the current line
        intervals[i] = iv;
        speeds[i] = s;
        // fill up the grid with cars
        if ((i & 1)) { // odd lane => move left
            // start from the offset, then move inwards
            for (int j = w - 1 - o; j >= 0; j -= iv) {
                // fill the current cell with a car
                g[i][j] = true;
            }
        } else { // even lane => move right
            // start from the offset, then move inwards 
            for (int j = o; j < w; j += iv) {
                g[i][j] = true;
            }
        }
    }
    // get the start position and the string that represents froggie's movements
    int ip;
    string moves;
    cin >> ip >> moves;
    // set the initial coordinates of froggie
    int cx = l, cy = ip;
    // then start from the bottom, and simulate the moves
    for (int id = 0; id < moves.size(); ++id) {
        // update the coordinates of froggie
        if (moves[id] == 'U') { // up
            --cx;
            if (cx < -1) goto sq;
        } else if (moves[id] == 'D') { // down 
            ++cx;
            if (cx > l) goto sq;
        } else if (moves[id] == 'L') { // left
            --cy;
            if (cy < 0) goto sq;
        } else if (moves[id] == 'R') { // right
            ++cy;
            if (cy >= w) goto sq;
        }    
        //cout << cx << " " << cy << endl;
        // then update the grid move once, also check if there is collision with froggie
        for (int i = 0; i < l; ++i) {
            // going left row
            if ((i & 1)) {
                // find the index of the first car
                int idx = 0;
                while (!g[i][idx]) ++idx;
                // simulate the movement of the cars 1x, check if got collision
                if (speeds[i] > 0) {
                    // check if there is collision with froggie
                    // get the left bound of unsafe zone
                    int lb = ((((idx - 1)) % intervals[i]) + intervals[i]) % intervals[i];
                    // get the right bound
                    int rb = ((((idx - speeds[i])) % intervals[i]) + intervals[i]) % intervals[i];
                    int temp = lb;
                    lb = rb;
                    rb = temp;
                    // get the modulo of the position of the frog
                    int pos = cy % intervals[i];
                    // if inside these bounds, means collision
                    if (cx == i && lb <= pos && pos <= rb) {
                        goto sq;
                    }
                    // get the remainder required to place the cars on the new road 
                    idx = ((((idx - speeds[i])) % intervals[i]) + intervals[i]) % intervals[i];
                    // create a new lane with the new cars
                    vector<bool> newlane(w, false);
                    // place the cars on the new lane
                    for (int j = idx; j < w; j += intervals[i]) {
                        newlane[j] = true;
                    }
                    // update the current lane
                    g[i] = newlane;
                } else {
                    // just check if got collision
                    if (cx == i && cy >= 0 && cy < w && g[cx][cy]) {
                        goto sq;
                    }
                }
            } else { // going right row
                // find the index of the first car
                int idx = 0;
                while (!g[i][idx]) ++idx;
                if (speeds[i] > 0) {
                    // check if there is collision with froggie
                    // get the left bound of unsafe zone
                    int lb = (idx + 1) % intervals[i];
                    // get the right bound
                    int rb = (idx + speeds[i]) % intervals[i];
                    // get the modulo of the position of the frog
                    int pos = cy % intervals[i];
                    // if inside these bounds, means collision
                    if (cx == i && lb <= pos && pos <= rb) {
                        goto sq;
                    }
                    // get the remainder required to place the cars on the new road 
                    idx = (idx + speeds[i]) % intervals[i];
                    // create a new lane with the new cars
                    vector<bool> newlane(w, false);
                    // place the cars on the new lane
                    for (int j = idx; j < w; j += intervals[i]) {
                        newlane[j] = true;
                    }
                    // update the current lane
                    g[i] = newlane;
                } else {
                    // just check if got collision with the stationary cars
                    if (cx == i && cy >= 0 && cy < w && g[cx][cy]) {
                        goto sq;
                    }
                }
            }
        }
    }
    // case where never reach
    if (cx != -1) {
        sq: cout << "squish" << endl;
    } else { // reach
        cout << "safe" << endl;
    }
    return 0;
}
