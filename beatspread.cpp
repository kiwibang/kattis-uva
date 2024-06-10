#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int s, d;
        cin >> s >> d;
        if (d > s || (s + d) % 2 == 1) {
            cout << "impossible" << endl;
            continue;
        }
        int bigger = ((s + d) >> 1);
        cout << bigger << " " << s - bigger << endl;
    }
    return 0;
}
