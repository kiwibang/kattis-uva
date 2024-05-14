#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    cout << s << ":" << endl;
    for (int x = 2; x < s; ++x) {
        // first pair: y + 1 == x
        // if visually appealing
        if (s % (2 * x - 1) == 0 || (s + x - 1) % (2 * x - 1) == 0) {
            cout << x << "," << x - 1 << endl;
        }
        // second pair: y == x
        if (s % (2 * x) == 0 || (s + x) % (2 * x) == 0) {
            cout << x << "," << x << endl;
        }
    }
    return 0;
}
