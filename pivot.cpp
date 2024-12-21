#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    // set up query arrays 
    vector<int> mxl(n, INT_MIN), mnr(n, INT_MAX);
    mxl[0] = nums[0];
    mnr[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) mxl[i] = max(mxl[i - 1], nums[i]);
    for (int i = n - 2; i >= 0; --i) mnr[i] = min(mnr[i + 1], nums[i]);
    if (nums[0] < mnr[1]) ++res;
    if (nums[n - 1] >= mxl[n - 2]) ++res;
    for (int i = 1; i < n - 1; ++i) if (nums[i] >= mxl[i - 1] && nums[i] < mnr[i + 1]) ++res;
    cout << res << endl;
    return 0;   
}

