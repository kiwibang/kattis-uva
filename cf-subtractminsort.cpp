#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            int temp = min(nums[i - 1], nums[i]);
            nums[i - 1] -= temp;
            nums[i] -= temp;
            if (nums[i - 1] > 0 && nums[i] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

