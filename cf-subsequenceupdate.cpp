#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        // create two subarrays, and then sort them separately
        vector<int> a(nums.begin(), nums.begin() + r), b(nums.begin() + l - 1, nums.end());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int len = r - l + 1;
        long long asum = 0, bsum = 0;
        for (int i = 0; i < len; ++i) asum += a[i];
        for (int i = 0; i < len; ++i) bsum += b[i];
        cout << min(asum, bsum) << endl;
    }
    return 0;
}

