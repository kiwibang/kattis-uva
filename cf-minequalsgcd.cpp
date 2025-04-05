#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long long a, long long b) {
    return !b ? a : gcd(b, a % b);
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        long long mn = LLONG_MAX, d = 0;
        bool mnadded = false;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            mn = min(mn, nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            // min seen first time
            if (!mnadded && nums[i] == mn) {
                mnadded = true;
                continue;
            }
            // update gcd if mn is divisor of nums[i]
            if (!(nums[i] % mn)) {
                if (d == 0) {
                    d = nums[i];
                    continue;
                }
                d = gcd(d, nums[i]);
            }
        }
        cout << ((d == mn) ? "Yes" : "No") << "\n";
    }
    return 0;
}
