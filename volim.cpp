#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, timeElapsed = 0;
    cin >> k >> n;
    while (n--) {
        int t;
        char c;
        cin >> t >> c;
        // update time elapsed in either case
        timeElapsed += t;
        // check if 210 seconds has elapsed
        if (timeElapsed >= 210) {
            continue;
        }
        if (c == 'T') { // correct ans
            // update k
            k = k + 1 > 8 ? 1 : k + 1;
        }
    }
    cout << k << endl;
    return 0;
}
