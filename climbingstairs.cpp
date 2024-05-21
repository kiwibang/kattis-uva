#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, k;
    cin >> n >> r >> k;
    // go to office, then go to registration desk
    int res = k + abs(k - r);
    // go up and down 1 step until reach n steps. if reach n steps then ok
    res = max(res, abs(n - res) & 1 == 1 ? n + 1 : n);
    // need to go down from the registration desk to og home
    res += r;
    // print the res
    cout << res << endl;
    return 0;
}
