#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    vector<bool> vert(n, false), horiz(n, false), updiag(2 * n - 1, false), downdiag(2 * n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        // check vert
        if (vert[y]) {
            cout << "INCORRECT" << endl;
            return 0;
        }
        // check horiz
        if (horiz[x]) {
            cout << "INCORRECT" << endl;
            return 0;
        }
        // check updiagonal
        int smlr = min(x, y), ux = x - smlr, uy = y - smlr,  uidx = n - 1- ux + uy;
        if (updiag[uidx]) {
            cout << "INCORRECT" << endl;
            return 0;
        }
        // check downdiagonal
        int didx = x + y;
        if (downdiag[didx]) {
            cout << "INCORRECT" << endl;
            return 0;
        }
        // update unplacable rows, cols, updiag, and downdiag
        vert[y] = true, horiz[x] = true, updiag[uidx] = true, downdiag[didx] = true;
    }   
    cout << "CORRECT" << endl;
    return 0;
}

