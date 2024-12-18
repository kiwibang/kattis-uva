#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the inputs
    int n;
    cin >> n;
    vector<int> plays(n);
    for (int i = 0; i < n; ++i) cin >> plays[i];
    int pos = 20, left = 4, adv = 0;
    for (int i = 0; i < n; ++i) {
        int cpl = plays[i];
        pos += cpl;
        adv += cpl;
        // case where safety 
        if (pos <= 0) {
            cout << "Safety" << endl;
            return 0;
        }
        // case where touchdown
        if (pos >= 100) {
            cout << "Touchdown" << endl;
            return 0;
        }
        // if neither, check for nothing event
        if (adv >= 10) {
            left = 4;
            adv = 0;
        } else {
            --left;
            if (left == 0) {
                cout << "Nothing" << endl;
                return 0;
            }
        }
    }
    cout << "Nothing" << endl;
    return 0;
}
