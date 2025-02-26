#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    for (int i = 100; i <= 999; ++i) {
        int temp = i, temp2 = i;
        while (temp2) {
            temp = (temp * 10) + temp2 % 10;
            temp2 /= 10;
        }
        s.insert(temp);
    }
    int t;
    cin >> t;
    while (t--) {
        int pw;
        cin >> pw;
        auto lb = s.lower_bound(pw);
        --lb;
        auto ub = s.lower_bound(pw);
        int mndiff = INT_MAX, res, ldiff, rdiff;
        if (lb != s.end()) {
            ldiff = abs(pw - *lb);
            if (ldiff < mndiff) {
                mndiff = ldiff;
                res = *lb;
            }
        }
        if (ub != s.end()) {
            rdiff = abs(*ub - pw);
            if (rdiff < mndiff) {
                mndiff = rdiff;
                res = *ub;
            }
        }
        cout << res << endl;
    }
    return 0;
}

