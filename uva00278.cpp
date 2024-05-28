#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        char piece;
        int m, n;
        cin >> piece >> m >> n;
        switch (piece) {
            case 'r':
                cout << min(m, n) << endl;
                continue;
            case 'k':
                if ((m & 1) == 1 && (n & 1) == 1) {
                    cout << (m * n + 1) / 2 << endl;
                } else {
                    cout << (m * n) / 2 << endl;
                }
                continue;
            case 'Q':
                cout << min(m, n) << endl;
                continue;
            case 'K':
                cout << ((m + 1) / 2) * ((n + 1) / 2) << endl;
                continue;
        }
    }
    return 0;
}
