#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the inputs
    int n;
    cin >> n;
    char cs[5][4 * n];
    for (int i = 0; i < 5; ++i) {
        cin >> cs[i];
    }
    for (int i = 0; i < n * 4; i += 4) {
        // check first char
        if (cs[0][i] == '.') {
            cout << 1;
        } else if (cs[3][i] == '*') {
            cout << 2;
        } else {
            cout << 3;
        }
    }
    cout << endl;
    return 0;
}
