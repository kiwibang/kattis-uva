#include <bits/stdc++.h>
using namespace std;

int getStars(int rank) {
    if (21 <= rank && rank <= 25) {
        return 2;
    } else if (16 <= rank && rank <= 20) {
        return 3;
    } else if (11 <= rank && rank <= 15) {
        return 4;
    } else if (1 <= rank && rank <= 10) {
        return 5;
    } else {
        return 99999;
    }
}

int main() {
    string matchHistory;
    cin >> matchHistory;

    int currRank = 25;
    int currStars = 0;
    int starsNeeded = getStars(currRank);
    int consecWins = 0;
    for (int i = 0; i < matchHistory.size(); ++i) {
        if (matchHistory[i] == 'W') {
            // gain a star for the win
            ++currStars;
            ++consecWins;
            // if consecutive wins is currently 3 or more, player gets a bonus star
            if (consecWins >= 3 && 6 <= currRank && currRank <= 25) {
                ++currStars;
            }
            // if get enough stars for current rank and more
            if (currStars > starsNeeded && currRank >= 1) {
                // rank up
                --currRank;
                // extra stars goes towards the new rank
                currStars = currRank == 0 ? 0 : currStars - starsNeeded;
                // get the stars needed for the new rank
                starsNeeded = getStars(currRank);
            }
        } else if (matchHistory[i] == 'L') {
            // if between rank 1 to 20 inclusive, then possible to lose stars
            if (1 <= currRank && currRank <= 20) {
                --currStars;
                // if decrease rank
                if (currStars < 0 && currRank < 20) {
                    ++currRank;
                    starsNeeded = getStars(currRank);
                    currStars = starsNeeded + currStars;
                } else if (currStars < 0 && currRank == 20) { // if rank 20, cannot decrease rank
                    currStars = 0;
                }
            }
            // in all cases, win streak (if any) is broken
            consecWins = 0;
        }
    }
    // print out the result
    if (currRank <= 0) {
        cout << "Legend" << endl;
    } else {
        cout << currRank << endl;
    }
    return 0;
}
