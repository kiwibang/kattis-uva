#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        string curr;
        bool noball = false;
        for (int i = 0; i < 5; ++i) {
            cin >> curr;
            int lineidx = -1;
            for (int j = 0; j < 5; ++j) {
                // normal cam; found bowler's foot
                if (curr[j] == '>') {
                    if (lineidx != -1) { // check no ball
                        noball = true;
                        break;
                    }
                } else if (curr[j] == '<') { // inverted cam; found bowler's foot
                    if (lineidx == -1) { // check no ball
                        noball = true;
                        break;
                    }
                } else if (curr[j] == '|') { // found the line
                    lineidx = j;
                }
            }
        }
        cout << "Case " << tc << ": ";
        if (noball) {
            cout << "No Ball" << endl;
        } else {
            cout << "Thik Ball" << endl;
        }
    }
    return 0;
}
