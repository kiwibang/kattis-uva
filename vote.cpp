#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long totalVotes = 0;
        int winner = -1;
        int maxVotes = -1;
        int votes[n];
        for (int i = 1; i <= n; ++i) {
            cin >> votes[i - 1];
            totalVotes += votes[i - 1];
            if (votes[i - 1] > maxVotes) {
                winner = i;
                maxVotes = votes[i - 1];
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (votes[i] == maxVotes) {
                ++count;
            }
        }
        if (count > 1) {
            cout << "no winner" << endl;
            continue;
        }
        if (maxVotes > totalVotes / 2) {
            cout << "majority "; 
        } else {
            cout << "minority ";
        }
        cout << "winner " << winner << endl;
    }
    return 0;
}
