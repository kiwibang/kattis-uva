#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, m, x, y;
    while (true) {
        cin >> k;
        if (k == 0) {
            return 0;
        }
        cin >> n >> m;
        while (k--) {
            cin >> x >> y;
            if (x == n || y == m) { // divisia
                cout << "divisa" << endl;
            } else if (x < n && y > m) { // northwest
                cout << "NO" << endl;
            } else if (x > n && y > m) { // northeast
                cout << "NE" << endl;
            } else if (x < n && y < m) { // southwest
                cout << "SO" << endl;
            } else { // southeast
                cout << "SE" << endl;
            }
        }
    }
    return 0;
}
