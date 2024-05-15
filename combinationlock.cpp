#include <bits/stdc++.h>
using namespace std;

int main() {
    int st, a, b, c;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> st >> a >> b >> c;
        if (st == 0 && a == 0 && b == 0 && c == 0) {
            return 0;
        }
        // first two clockwise turns; still at st
        int res = 360 * 2;
        // clockwise turn to the first number; now at first number a
        res = st >= a ? res + ((double) (st - a) / 40) * 360 : res + ((double) (st - a + 40) / 40) * 360;
        // counter-clockwise turn; still at first number a
        res += 360;
        // counter-clockwise turn to second number; now at b
        res = a <= b ? res + ((double) (b - a) / 40) * 360 : res + ((double) (b - a + 40) / 40) * 360;
        // clockwise to third number; now at c
        res = b >= c ? res + ((double) (b - c) / 40) * 360 : res + ((double) (b - c + 40) / 40) * 360;
        cout << res << endl;    
    }
    return 0;
}
