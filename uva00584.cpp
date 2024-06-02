#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == "Game Over") {
            return 0;
        }
        // (10, -1) - strike
        // (x, y), where x + y == 10 - spare
        // (x, y), where x + y < 10 - normal roll
        // (x, -1) - last roll due to spare
        vector<pair<int, int> > score;
        int i = 0;
        while (i < line.size()) {
            pair<int, int> frame = pair<int, int>(-1, -1);
            // current frame is a strike
            if (line[i] == 'X') {
                frame.first = 10;
                score.push_back(frame);
                i += 2;
                continue;
            }
            // current frame is normal frame or spare
            // we always have the first roll strictly less than 10
            frame.first = line[i] - '0';
            i += 2;
            // then read the second roll. could be a spare or non-spare
            if (i < line.size()) {
                if (line[i] == '/') {
                    frame.second = 10 - frame.first;
                } else {
                    frame.second = line[i] - '0';
                }
            }
            score.push_back(frame);
            i += 2;
        }
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            pair<int, int> frame = score[i];
            // strike
            if (frame.first == 10 && frame.second == -1) {
                // add the base score of a strike
                res += 10;
                // case where next two rolls is normal or spare
                if (score[i + 1].second != -1) {
                    // add total score of next two rolls
                    res += score[i + 1].first + score[i + 1].second;
                } else { // case where next roll is strike and next next roll may be a strike
                    res += 10;
                    res += score[i + 2].first;
                }
            } else if (frame.first + frame.second == 10) { // spare
                // add the base score of a spare
                res += 10;
                // add the score of the next roll
                res += score[i + 1].first;
            } else { // normal roll
                // add the total 
                frame.second = frame.second == -1 ? 0 : frame.second;
                res += frame.first + frame.second;
            }
        }
        cout << res << endl;
    }
    return 0;
}
