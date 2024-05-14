#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, t, prev, sum;
    while (true) {
        cin >> n;
        if (n == -1) {
            return 0;
        }
        prev = -1;
        sum = 0;
        while (n--) {   
            cin >> s >> t;
            if (prev == -1) {
                sum += t * s;
            } else {
                sum += (t - prev) * s;
            }
            prev = t;
        }
        cout << sum << " miles" << endl;
    }
    return 0;
}
