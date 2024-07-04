#include <bits/stdc++.h>
using namespace std;

int main() {
    // number of testcases
    int tc;
    cin >> tc;
    cin.ignore();
    string sub, pt;
    // read the first blank line
    getline(cin, sub);
    // loop over testcases
    for (int t = 0; t < tc; ++t) {
        // separate consecutive inputs (if any)
        if (t > 0) {
            cout << endl;
        }
        // read in plaintext alphabet
        getline(cin, pt);
        // read in substitution alphabet
        getline(cin, sub);
        map<char, char> mp;
        // convert the above to a map
        for (int i = 0; i < sub.size(); ++i) {
            mp[pt[i]] = sub[i];
        }
        // print the substitution alphabet
        cout << sub << endl;
        cout << pt << endl;
        // then read in the lines one-by-one, and translate + print
        while (true) {
            string currline;
            getline(cin, currline);
            if (currline.empty()) {
                break;
            }
            // translate the current line, and print
            for (int i = 0; i < currline.size(); ++i) {
                if (mp.find(currline[i]) == mp.end()) {
                    cout << currline[i];
                    continue;
                }
                cout << mp[currline[i]];
            }
            cout << endl;
        }
    }
    return 0;
}
