#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, a, b, sm = 0;
    cin >> n >> k;
    vector<int> as(n), bs(n), mxunits(n), res(n);
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bs[i];
    }
    for (int i = 0; i < n; ++i) {
        mxunits[i] = as[i] / bs[i];
        // cout << mxunits[i] << " ";
        sm += mxunits[i];
    }
    //cout << endl;
    //cout << sm << endl;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        long long remhrs = sm - mxunits[i], part = max(0ll, k - remhrs);
        if (mxunits[i] < part) { // cannot fulfil their part
            ok = false;
            break;
        }
        // update project hours
        k -= part;
        sm -= mxunits[i];
        res[i] = part;
    }
    if (!ok) {
        for (int i = 0; i < n; ++i) cout << "0 ";
        cout << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}

