#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, curr;
        cin >> n;
        if (cin.eof()) break;
        vector<int> nums(n);
        vector<bool> h(n);
        h[0] = true;
        bool jolly = true;
        for (int i = 0; i < n; ++i) cin >> nums[i];
        for (int i = 1; i < n; ++i) {
            int diff = abs(nums[i] - nums[i - 1]);
            if (diff < 1 || diff >= n) {
                jolly = false;
                break;
            }
            h[diff] = true;
        }
        for (bool t : h) { 
            if (!t) {
                jolly = false;
                break;
            }
        }
        if (!jolly) {
            cout << "Not Jolly" << endl;
            continue;
        }
        cout << "Jolly" << endl;
    }
    return 0;
}
