#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, curr;
    cin >> s;
    for (int j = 1; j <= s; ++j) {
        bool canSolve = true;
        for (int i = 0; i < 13; ++i) {
            cin >> curr;
            if (curr == 0) {
                canSolve = false;
            }
        }
        if (canSolve) {
            cout << "Set #" << j << ": " << "Yes" << endl;
        } else {
            cout << "Set #" << j << ": " << "No" << endl;
        }
    }
    return 0;
}
