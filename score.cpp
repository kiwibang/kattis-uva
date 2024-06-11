#include <bits/stdc++.h>
using namespace std;

int ts(string tm) {
    int p = tm.find(':');
    return stoi(tm.substr(0, p)) * 60 + stoi(tm.substr(p + 1, 2));
}

int main() {
    // read in the number of scores
    int n;
    cin >> n;
    // init the home and away team scores, and the current time
    int hp = 0, ap = 0, prevtime = 0;
    int ht = 0, at = 0, pw = -1;
    while (n--) {
        // read the current score
        char team;
        int pts;
        string time;
        cin >> team >> pts >> time;
        // parse the time into seconds
        int ct = ts(time);
        // add points
        if (team == 'H') {
            hp += pts;
        } else {
            ap += pts;
        }
        // if home leading
        if (pw == 0) {
            ht += (ct - prevtime);
        } else if (pw == 1) { // if away leading
            at += (ct - prevtime);
        }
        // update the winning team
        pw = hp == ap ? -1 : hp > ap ? 0 : 1;
        // update the previous time
        prevtime = ct;
    }
    // account for endgame
    if (pw == 0) {
        ht += (1920 - prevtime);
    } else {
        at += (1920 - prevtime);
    }
    // print the winner
    if (hp > ap) {
        cout << "H ";
    } else {
        cout << "A ";
    }
    // print home team winning time
    cout << ht / 60 << ":" << fixed << setw(2) << setfill('0') << ht % 60 << " " << at / 60 << ":" << fixed << setw(2) << setfill('0') << at % 60 << endl;
    return 0;
}
