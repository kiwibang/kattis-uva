#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, d, e;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> e;
        if (b - a == 1 && c - b == 1 && d - c == 1 && e - d == 1) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
