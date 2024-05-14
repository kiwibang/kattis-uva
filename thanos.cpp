#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, p, r, f;
    cin >> t;
    while (t--) {
        cin >> p >> r >> f;
        long long ans = 0;
        while (p <= f) {
            p *= r;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
