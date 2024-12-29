#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    if (t == 1) {
        int l = 0, r = n - 1, sum;
        while (l <= r) {
            sum = nums[l] + nums[r];
            if (sum == 7777) {
                cout << "Yes" << endl;
                goto en;
            }
            if (sum > 7777) {
                --r;
            } else {
                ++l;
            }
        }
        cout << "No" << endl;
    } else if (t == 2) {
        for (int i = 1; i < n; ++i) {
             if (nums[i - 1] == nums[i]) {
                cout << "Contains duplicate" << endl;
                goto en;
            }
        }
        cout << "Unique" << endl;
    } else if (t == 3) {
        map<int, int> f;
        int mx = 0, mxnum;
        for (int num : nums) {
            if (!f.count(num)) f[num] = 0;
            ++f[num];
            if (f[num] > mx) {
                mx = f[num];
                mxnum = num;
            }
        }
        if (mx > n / 2) {
            cout << mxnum << endl;
        }  else {
            cout << -1 << endl;
        }
    } else if (t == 4) {
        if (n & 1) {
            cout << nums[n / 2] << endl;
        } else {
            cout << nums[n / 2 - 1] << " " << nums[n / 2] << endl;
        }
    } else if (t == 5) {
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (100 <= num && num <= 999) {
                cout << num; 
                if (i < n - 1) cout << " ";
            }
        }
        cout << endl;
    }
    en:
    return 0;
}

