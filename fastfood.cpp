#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // read in input
        int n, m;
        cin >> n >> m;
        vector<vector<int> > prizes;
        vector<int> prizeValue;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            vector<int> coupons;
            for (int j = 0; j < k; ++j) {
                int curr;
                cin >> curr;
                coupons.push_back(curr);
            }
            prizes.push_back(coupons);
            int val;
            cin >> val;
            prizeValue.push_back(val);
        }
        vector<int> coupons;
        coupons.push_back(-1);
        for (int i = 0; i < m; ++i) {
            int curr;
            cin >> curr;
            coupons.push_back(curr);
        }

        // process input 
        long long res = 0;
        // for each prize, get the count of the coupon required with the min count
        for (int i = 0; i < prizes.size(); ++i) {
            int mn = 300;
            int mnCoupon = -1;
            for (int j = 0; j < prizes[i].size(); ++j) {
                // if min
                if (coupons[prizes[i][j]] < mn) {
                    mn = coupons[prizes[i][j]];
                    mnCoupon = prizes[i][j];
                }
            }
            // update the res
            res += mn * prizeValue[i];
        }
        cout << res << endl;
    }
    return 0;
}
