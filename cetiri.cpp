#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, mn, mx, md;
    cin >> a >> b >> c;
    mn = min(a, min(b, c));
    mx = max(a, max(b, c));
    md = a != mn && a != mx ? a : b != mn && b != mx ? b : c;
    int diff = min(mx - md, md - mn);
    if (mn + diff != md) { // 2nd number missing
        cout << mn + diff << endl;
    } else if (mn + diff == md && mn + 2 * diff != mx) { // 3rd num missing
        cout << mn + 2 * diff << endl;
    } else { // 4th num missing
        cout << mx + diff << endl;
    }
    return 0;
}
