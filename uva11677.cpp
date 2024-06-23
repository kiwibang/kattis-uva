#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    while (true) {
        cin >> h1 >> m1 >> h2 >> m2;
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) {
            break;
        }
        int startmns = h1 * 60 + m1;
        int endmns = h2 * 60 + m2;
        int d = endmns - startmns;
        if (d >= 0) {
            cout << d << endl;
        } else {
            cout << 1440 + d << endl;
        }
    }
    return 0;
}
