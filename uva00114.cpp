#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in number of cols, rows, cost of hitting a wall, and cost of bumpers
    int cl, rl, wallcost, numbumpers;
    cin >> cl >> rl >> wallcost >> numbumpers;

    // make the board
    vector<vector<bool> > board = vector<vector<bool> >(rl, vector<bool>(cl, false));

    // loop over the bumpers and write down their value and cost in the map below
    map<pair<int, int>, pair<int, int> > bp;
    int x, y, bumperval, bumpercost; 
    for (int i = 0; i < numbumpers; ++i) {
        cin >> x >> y >> bumperval >> bumpercost;
        bp[pair<int, int>(y - 1, x - 1)] = pair<int, int>(bumperval, bumpercost);
        board[y - 1][x - 1] = true;
    }

    // track the total score of the ballz
    int ballzscore = 0;
    // loop over the balls
    int dir, lifetime;
    // map to update the position of the ball
    // first coodinate == y, second coordinate == x
    const int dirs[][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    while (true) {
        // read the info of the balls
        cin >> x >> y >> dir >> lifetime;
        if (cin.eof()) {
            break;
        }
        --x;
        --y;
        // track the score of the current ball
        int currscore = 0;
        // simulate the movement of the ball - 1 loop == 1 movement
        while (--lifetime > 0) {
            // get the new position of the ball
            int newx = x + dirs[dir][1];
            int newy = y + dirs[dir][0];
            // case if new pos is a wall
            if (newx == 0 || newx == cl - 1 || newy == 0 || newy == rl - 1) {
                lifetime -=wallcost;
                dir = (dir + 3) % 4;
            } else if (board[newy][newx]) { // case where new pos is a bumper
                currscore += bp[pair<int, int>(newy, newx)].first;
                lifetime -= bp[pair<int, int>(newy, newx)].second;
                dir = (dir + 3) % 4;
            } else { // if empty
                x = newx;
                y = newy;
            }
        }
        // update the total score
        ballzscore += currscore;
        cout << currscore << endl;
    }
    // print the total score of all the ballz at the end
    cout << ballzscore << endl;
    return 0;
}
