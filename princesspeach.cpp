#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y, cr, res = 0;
    cin >> n >> y;
    vector<bool> ok(n, true);
    for (int i = 0; i < y; ++i) {
        cin >> cr;
        ok[cr] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (ok[i]) {
            cout << i << endl;
        } else {
            ++res;
        }
    }
    cout << "Mario got " << res << " of the dangerous obstacles." << endl;
    return 0;
}

