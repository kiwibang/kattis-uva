#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, l, M, L, tm, tl;
    cin >> m >> l >> M >> L >> tm >> tl;
    int mfirst, lfirst;
    bool mpos = true, lpos = true;

    // format: abs(start point, end point)
    // go to m, then move to M, then move to l, then move to L
    mfirst = abs(0 - m) + abs(m - M);
    // cannot make it
    if (mfirst > tm) {
        mpos = false;
    }
    mfirst += abs(M - l) + abs(L - l);
    if (mfirst > tl) {
        mpos = false;
    }

    // go to l, then move to L, then move to m, then move to M
    lfirst = abs(0 - l) + abs(L - l);
    if (lfirst > tl) {
        lpos = false;
    }
    lfirst += abs(L - m) + abs(M - m);
    if (lfirst > tm) {
        lpos = false;
    }

    int mdrop, ldrop;
    bool mposd = true, lposd = true;
    // go to m, pick up, then go to l, drop off, go to L, to to l, pick up, then 
    // go to M
    mdrop = abs(0 - m) + abs(m - l) + abs(l - L);
    if (mdrop > tl) {
        mposd = false;
    }
    mdrop += abs(L - l) + abs(l - M);
    if (mdrop > tm) {
        mposd = false;
    }

    // go to l, pick up, go to m, drop off, go to M, got to m, pick up, then
    // go to L
    ldrop = abs(0 - l) + abs(l - m) + abs(m - M);
    if (ldrop > tm) {
        lposd = false;
    }
    ldrop += abs(M - m) + abs(m - L);
    if (ldrop > tl) {
        lposd = false;
    }
    
    if (!mpos && !lpos && !mposd && !lposd) {
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
    }
    return 0;
}
