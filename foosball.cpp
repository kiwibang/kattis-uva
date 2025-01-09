#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string whiteo, whited, blacko, blackd, curr;
    cin >> whiteo >> blacko >> whited >> blackd;
    string fwhite = whiteo, swhite = whited, fblack = blacko, sblack = blackd;
    queue<string> q;
    for (int i = 0; i < n - 4; ++i) {
        cin >> curr;
        q.push(curr);
    }
    cin >> curr;
    vector<vector<string> > winningteams;
    int longestdynasty = 0, currdynasty = 0;
    char winningteam = '.';
    for (int i = 0; i < curr.size(); ++i) {
        if (curr[i] == 'W') {
            // end streak
            if (winningteam == 'B' || winningteam == '.') {
                if (currdynasty > longestdynasty) {
                    winningteams.clear();
                    longestdynasty = currdynasty;
                    winningteams.push_back({fblack, sblack});
                } else if (currdynasty == longestdynasty) {
                    winningteams.push_back({fblack, sblack});
                }
                currdynasty = 0;
                winningteam = 'W';
            }
            ++currdynasty;
            // swap white players
            string temp = whiteo;
            whiteo = whited;
            whited = temp;
            // black offense becomes defense
            q.push(blackd);
            blackd = blacko;
            blacko = q.front();
            q.pop();
            fblack = blackd;
            sblack = blacko;
        } else {
            // end streak
            if (winningteam == 'W' || winningteam == '.') {
                if (currdynasty > longestdynasty) {
                    winningteams.clear();
                    longestdynasty = currdynasty;
                    winningteams.push_back({fwhite, swhite});
                } else if (currdynasty == longestdynasty) {
                    winningteams.push_back({fwhite, swhite});
                }
                currdynasty = 0;
                winningteam = 'B';
            }
            ++currdynasty;
            // swap
            string temp = blacko;
            blacko = blackd;
            blackd = temp;
            // white offense becomes defense
            q.push(whited);
            whited = whiteo;
            whiteo = q.front();
            q.pop();
            fwhite = whited;
            swhite = whiteo;
        }
    }
    if (currdynasty > longestdynasty) {
        winningteams.clear();
        longestdynasty = currdynasty;
        if (winningteam == 'B') {
            winningteams.push_back({fblack, sblack});
        } else {
            winningteams.push_back({fwhite, swhite});
        }
    } else if (currdynasty == longestdynasty) {
        if (winningteam == 'B') {
            winningteams.push_back({fblack, sblack});
        } else {
            winningteams.push_back({fwhite, swhite});
        }
    }
    for (vector<string>& t : winningteams) {
        cout << t[0] << " " << t[1] << endl;
    }
    return 0;
}

