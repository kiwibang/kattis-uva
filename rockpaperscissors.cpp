#include <bits/stdc++.h>
using namespace std;

bool checkWin(string m1, string m2) {
    return (m1 == "rock" && m2 == "scissors") || (m1 == "scissors" && m2 == "paper") || (m1 == "paper" && m2 == "rock");
}
int main() {
    int tc = 1;
    while (true) {
        // read in number of players n, number of matches k
        int n, k;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        if (tc > 1) {
            cout << endl;
        }
        // record the number of wins and losses
        vector<vector<double> > matches = vector<vector<double> >(n + 1, vector<double>(2, 0));
        cin >> k;
        k = (k * n * (n - 1)) / 2;
        for (int i = 0; i < k; ++i) {
            int p1, p2;
            string m1, m2;
            // read in the details of the match
            cin >> p1 >> m1 >> p2 >> m2;
            // see whether the player wins or loses
            // tie
            if (m1 == m2) {
                continue; // ignore
            }
            // p1 wins, p2 loses
            if (checkWin(m1, m2)) {
                ++matches[p1][0];
                ++matches[p2][1];
            } else { // p2 wins, p1 loses
                ++matches[p2][0];
                ++matches[p1][1];
            }
        }
        // output one line for every player, the win average as defined in the question
        for (int i = 1; i <= n; ++i) {
            double wins = matches[i][0];
            double losses = matches[i][1];
            // case where no wins nor losses => player has a nan win average
            if (wins == 0 && losses == 0) {
                cout << "-" << endl;
                continue;
            }
            // else, print the win average
            cout << fixed << setprecision(3) << wins / (wins + losses) << endl;
        }
        ++tc;
    }
    return 0;
}
