#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    // if same
    if (a.second == b.second) {
        return a.first > b.first; 
    }
    return a.second > b.second;
}

void simulate(vector<vector<int> >& b, int& sum, map<int, pair<int, int> >& itc, map<pair<int, int>, int>& cti, set<int>& pegs) {
    if (pegs.size() == 0) {
        return;
    }
    while (true) {
        // loop over all the pegs, and get the list of available moves in terms of destination hole
        // store the moves in a list of pairs, where the first item is the souce hole, second item is the dest hole
        int bestsrc = -1;
        int bestdst = -1;
        for (const int& peg : pegs) {
            pair<int, int> pegCoord = itc[peg];
            int x = pegCoord.first;
            int y = pegCoord.second;
            int destx, desty, capx, capy;
            // check vertical
            // go up
            destx = x - 2;
            desty = y;
            capx = x - 1;
            capy = y;
            if (cti.find(pair<int, int>(destx, desty)) != cti.end() && cti.find(pair<int, int>(capx, capy)) != cti.end() && b[capx][capy] == 1 && b[destx][desty] == 0) {
                if (cti[pair<int, int>(destx, desty)] > bestdst) {
                    bestdst = cti[pair<int, int>(destx, desty)];
                    bestsrc = peg;
                } else if (cti[pair<int, int>(destx, desty)] == bestdst && peg > bestsrc) {
                    bestsrc = peg;
                }
            }
            // go down 
            destx = x + 2;
            desty = y;
            capx = x + 1;
            capy = y;
            if (cti.find(pair<int, int>(destx, desty)) != cti.end() && cti.find(pair<int, int>(capx, capy)) != cti.end() && b[capx][capy] == 1 && b[destx][desty] == 0) {
                if (cti[pair<int, int>(destx, desty)] > bestdst) {
                    bestdst = cti[pair<int, int>(destx, desty)];
                    bestsrc = peg;
                } else if (cti[pair<int, int>(destx, desty)] == bestdst && peg > bestsrc) {
                    bestsrc = peg;
                }
            }
            // check horizontal
            // go left
            destx = x;
            desty = y - 2;
            capx = x;
            capy = y - 1;
            if (cti.find(pair<int, int>(destx, desty)) != cti.end() && cti.find(pair<int, int>(capx, capy)) != cti.end() && b[capx][capy] == 1 && b[destx][desty] == 0) {
                if (cti[pair<int, int>(destx, desty)] > bestdst) {
                    bestdst = cti[pair<int, int>(destx, desty)];
                    bestsrc = peg;
                } else if (cti[pair<int, int>(destx, desty)] == bestdst && peg > bestsrc) {
                    bestsrc = peg;
                }
            }
            // go right
            destx = x;
            desty = y + 2;
            capx = x;
            capy = y + 1;
            if (cti.find(pair<int, int>(destx, desty)) != cti.end() && cti.find(pair<int, int>(capx, capy)) != cti.end() && b[capx][capy] == 1 && b[destx][desty] == 0) {
                if (cti[pair<int, int>(destx, desty)] > bestdst) {
                    bestdst = cti[pair<int, int>(destx, desty)];
                    bestsrc = peg;
                } else if (cti[pair<int, int>(destx, desty)] == bestdst && peg > bestsrc) {
                    bestsrc = peg;
                }
            }
        }
        // case where no moves can be made
        if (bestdst == -1) {
            break;
        }
        // make the move
        pair<int, int> srcCoord = itc[bestsrc];
        pair<int, int> dstCoord = itc[bestdst];
        int srcx, srcy, dstx, dsty, tgx, tgy;
        srcx = srcCoord.first;
        srcy = srcCoord.second;
        dstx = dstCoord.first;
        dsty = dstCoord.second;
        tgx = (srcx + dstx) / 2;
        tgy = (srcy + dsty) / 2;
        // remove the source peg
        b[srcx][srcy] = 0;
        pegs.erase(bestsrc);
        // update the sum
        sum -= bestsrc;
        // remove the peg that was jumped over
        b[tgx][tgy] = 0;
        pegs.erase(cti[pair<int, int>(tgx, tgy)]);
        // update the sum
        sum -= cti[pair<int, int>(tgx, tgy)];
        // place the jumping peg at the destination
        b[dstx][dsty] = 1;
        pegs.insert(bestdst);
        // update the sum
        sum += bestdst;
    }
}

int main() {
    // map that will map the holes id to a coordinate
    map<int, pair<int, int> > itc;
    itc[1] = pair<int, int>(0, 2);
    itc[2] = pair<int, int>(0, 3);
    itc[3] = pair<int, int>(0, 4);
    itc[4] = pair<int, int>(1, 2);
    itc[5] = pair<int, int>(1, 3);
    itc[6] = pair<int, int>(1, 4);
    itc[7] = pair<int, int>(2, 0);
    itc[8] = pair<int, int>(2, 1);
    itc[9] = pair<int, int>(2, 2);
    itc[10] = pair<int, int>(2, 3);
    itc[11] = pair<int, int>(2, 4);
    itc[12] = pair<int, int>(2, 5);
    itc[13] = pair<int, int>(2, 6);
    itc[14] = pair<int, int>(3, 0);
    itc[15] = pair<int, int>(3, 1);
    itc[16] = pair<int, int>(3, 2);
    itc[17] = pair<int, int>(3, 3);
    itc[18] = pair<int, int>(3, 4);
    itc[19] = pair<int, int>(3, 5);
    itc[20] = pair<int, int>(3, 6);
    itc[21] = pair<int, int>(4, 0);
    itc[22] = pair<int, int>(4, 1);
    itc[23] = pair<int, int>(4, 2);
    itc[24] = pair<int, int>(4, 3);
    itc[25] = pair<int, int>(4, 4);
    itc[26] = pair<int, int>(4, 5);
    itc[27] = pair<int, int>(4, 6);
    itc[28] = pair<int, int>(5, 2);
    itc[29] = pair<int, int>(5, 3);
    itc[30] = pair<int, int>(5, 4);
    itc[31] = pair<int, int>(6, 2);
    itc[32] = pair<int, int>(6, 3);
    itc[33] = pair<int, int>(6, 4);
    // map that maps the coordinates to the hole id
    map<pair<int, int>, int> cti;
    cti[pair<int, int>(0, 2)] = 1;
    cti[pair<int, int>(0, 3)] = 2;
    cti[pair<int, int>(0, 4)] = 3;
    cti[pair<int, int>(1, 2)] = 4;
    cti[pair<int, int>(1, 3)] = 5;
    cti[pair<int, int>(1, 4)] = 6;
    cti[pair<int, int>(2, 0)] = 7;
    cti[pair<int, int>(2, 1)] = 8;
    cti[pair<int, int>(2, 2)] = 9;
    cti[pair<int, int>(2, 3)] = 10;
    cti[pair<int, int>(2, 4)] = 11;
    cti[pair<int, int>(2, 5)] = 12;
    cti[pair<int, int>(2, 6)] = 13;
    cti[pair<int, int>(3, 0)] = 14;
    cti[pair<int, int>(3, 1)] = 15;
    cti[pair<int, int>(3, 2)] = 16;
    cti[pair<int, int>(3, 3)] = 17;
    cti[pair<int, int>(3, 4)] = 18;
    cti[pair<int, int>(3, 5)] = 19;
    cti[pair<int, int>(3, 6)] = 20;
    cti[pair<int, int>(4, 0)] = 21;
    cti[pair<int, int>(4, 1)] = 22;
    cti[pair<int, int>(4, 2)] = 23;
    cti[pair<int, int>(4, 3)] = 24;
    cti[pair<int, int>(4, 4)] = 25;
    cti[pair<int, int>(4, 5)] = 26;
    cti[pair<int, int>(4, 6)] = 27;
    cti[pair<int, int>(5, 2)] = 28;
    cti[pair<int, int>(5, 3)] = 29;
    cti[pair<int, int>(5, 4)] = 30;
    cti[pair<int, int>(6, 2)] = 31;
    cti[pair<int, int>(6, 3)] = 32;
    cti[pair<int, int>(6, 4)] = 33;
    cout << "HI Q OUTPUT" << endl;
    // read the number of game instances
    int n;
    cin >> n;
    // read in the game instances
    while (n--) {
        // read in each game instance, and simulate
        vector<vector<int> > board = vector<vector<int> >(7, vector<int>(7, 0));
        set<int> pegs;
        int curr, sum = 0;
        while (true) {
            cin >> curr;
            // check if end of current instance
            if (curr == 0) {
                break;
            }
            // get the coordinates of the peg
            int x = itc[curr].first;
            int y = itc[curr].second;
            // otherwise, add the peg to the board
            board[x][y] = 1;
            pegs.insert(curr);
            // update the sum of the id of the holes with pegs
            sum += curr;
        }
        // simulate the game based on the given rules
        simulate(board, sum, itc, cti, pegs);
        // print the result of the current board
        cout << sum << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
