#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string orig, nw, exp = "";
    cin >> orig;
    cin >> nw;
    if (n & 1) { // odd overwrites, exp is flip of orig
        for (int i = 0; i < orig.size(); ++i) {
            if (orig[i] == '0') {
                exp += '1';
            } else {
                exp += '0';
            }
        }
    } else { // even
        exp = orig;
    }
    if (nw == exp) {
        cout << "Deletion succeeded" << endl;
    } else {
        cout << "Deletion failed" << endl;
    }
    return 0;
}
