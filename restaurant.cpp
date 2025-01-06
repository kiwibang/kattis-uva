#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string cmd;
    int m;
    for (int tc = 0;; ++tc) {
        cin >> n;
        if (!n) break;
        if (tc > 0) cout << endl;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cmd >> m;
            if (cmd == "TAKE") {
                // case where stack 1 is empty and stack 2 contains stuff
                if (s1 == 0 && s2 > 0) {
                    // move all plates from stack 2 into stack 1
                    s1 = s2;
                    s2 = 0;
                    cout << "MOVE 2->1 " << s1 << endl;
                    // then take the required number of plates
                    s1 -= m;
                    cout << "TAKE 1 " << m << endl;
                } else if (s1 > 0 && s2 == 0) {
                    // take all plates from s1
                    s1 -= m; 
                    cout << "TAKE 1 " << m << endl;
                } else if (s1 == 0 && s2 == 0) {
                    // shouldnt reach here
                } else { // case where both s1 and s2 have
                    // take from s1 first 
                    if (s1 >= m) { // case where there is enough from s1
                        // take from stack 1
                        cout << "TAKE 1 " << m << endl;
                        s1 -= m;
                    } else { // case where there is not enough from s1
                        // calculate remainder
                        int rem = m - s1;
                        // take all from s1
                        cout << "TAKE 1 " << s1 << endl;
                        // add all from s2 to s1
                        s1 = s2;
                        s2 = 0;
                        cout << "MOVE 2->1 " << s1 << endl;
                        // then take the remainder from s1
                        s1 -= rem;
                        cout << "TAKE 1 " << rem << endl;
                    }
                }
            } else if (cmd == "DROP") {
                // drop the plates into stack 2 first
                s2 += m;
                cout << "DROP 2 " << m << endl; 
            }
        } 
    }
    return 0;
}

