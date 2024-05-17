#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    // loop over testcases
    while (true) {
        cin >> n >> m;
        if (cin.eof()) {
            break;
        }
        // keep count of the number of players that have scored at least 1 goal
        // in all matches
        int res = 0;
        // loop over players
        for (int i = 0; i < n; ++i) {
            // keep track of whether the player has scored in all matches so far
            int sa = 1;
            // loop over the matches that the player has played in
            int gs;
            for (int j = 0; j < m; ++j) {
                cin >> gs;
                int g = gs > 0 ? 1 : 0;
                sa &= g;
            }
            if (sa) {
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
