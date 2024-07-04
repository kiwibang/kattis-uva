#include <bits/stdc++.h>
using namespace std;

int main() {
    string c, k;
    cin >> c >> k;
    for (int i = 0; i < c.length(); ++i) {
        int rot = k[i] - 'A';
        if (i & 1) { // odd
            cout << (char) (((c[i] + rot - 'A') % 26) + 'A');
        } else { // even
            int pos = c[i] - rot - 'A';
            if (pos < 0) {
                pos += 26;
            }
            cout << (char) (pos + 'A');
        }
    }
    cout << endl;
    return 0;
}
