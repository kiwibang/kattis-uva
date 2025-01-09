#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, tot = 0, curr, res = 0;
    bool ok = false;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (ok) continue;
        if (tot + curr > t) {
            ok = true;
            continue;
        }
        tot += curr;
        ++res;
    }
    cout << res << endl;
    return 0;
}

