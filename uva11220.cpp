#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the number of testcases
    int tc;
    cin >> tc;
    cin.ignore();
    string curr, currword, currmsg;
    getline(cin, curr);
    // loop over the testcases
    for (int t = 1; t <= tc; ++t) {
        if (t > 1) {
            cout << endl;
        }
        cout << "Case #" << t << ":" << endl;
        // decode the message
        while (true) {
            // get the current line
            getline(cin, curr);
            if (curr.empty()) {
                break;
            }
            // loop over the words
            istringstream iss(curr);
            int idx = 0;
            currmsg = "";
            while (iss >> currword) {
                if (idx < currword.size()) {
                    currmsg += currword[idx++];
                }
            }
            cout << currmsg << endl;
        }
    }
    return 0;
}
