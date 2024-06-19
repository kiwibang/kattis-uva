#include <bits/stdc++.h>
using namespace std;

// converts a string into seconds
int gettime(string time) {
    int hr = (time[0] - '0') * 10 + (time[1] - '0');
    int min = (time[3] - '0') * 10 + (time[4] - '0');
    int secs = (time[6] - '0') * 10 + (time[7] - '0');
    return hr * 3600 + min * 60 + secs;
}

map<int, int> numtosegs;
// gets the cost of showing scoreboard from prevtime to currtime
int getcost(int score, int prevtime, int currtime) {
    int delta = currtime - prevtime;
    if (score < 10) {
        return numtosegs[score] * delta;
    } 
    if (score < 100) {
        return (numtosegs[((score / 10) % 10)] + numtosegs[score % 10]) * delta;
    }
    return (numtosegs[((score / 100) % 10)] + numtosegs[((score / 10) % 10)] + numtosegs[score % 10]) * delta;
}

int main() {
    numtosegs[0] = 6;
    numtosegs[1] = 2;
    numtosegs[2] = 5;
    numtosegs[3] = 5;
    numtosegs[4] = 4;
    numtosegs[5] = 5;
    numtosegs[6] = 6;
    numtosegs[7] = 3;
    numtosegs[8] = 7;
    numtosegs[9] = 6;

    int tc = 1;
    // loop over the testcases
    while (true) {
        // get the start time
        string info, time, team;
        int cscore;
        cin >> info >> time;
        // if no more testcases, terminate the program
        if (cin.eof()) {
            return 0;
        }
        // track the previous time and the previous score
        int prevtime = gettime(time), prevscorehome = 0, prevscoreaway = 0;
        long long res = 0;
        // then read the scores
        while (true) {
            cin >> info >> time;
            int currtime = gettime(time);
            // cout << currtime - prevtime << endl;
            // add the cost of displaying the scores for both home and team
            res += getcost(prevscorehome, prevtime, currtime);
            res += getcost(prevscoreaway, prevtime, currtime);
            if (info == "END") {
                break;
            }
            cin >> team >> cscore;
            // update the scores
            if (team == "home") {
                prevscorehome += cscore;
            } else if (team == "guest") {
                prevscoreaway += cscore;
            }
            prevtime = currtime;
        }
        // print the result
        cout << "Case " << tc++ << ": " << res << endl;
    }
    return 0;
}
