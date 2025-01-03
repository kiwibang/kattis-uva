#include <bits/stdc++.h>
using namespace std;

long long count_inversions(vector<long long>& nums, int l, int r) {
    if (l == r) return 0; // size 1, already sorted
    if (r - l == 1) {
        if (nums[l] > nums[r]) {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            return 1;
        }
        return 0;
    }
    int m = l + (r - l) / 2;
    long long res = count_inversions(nums, l, m) + count_inversions(nums, m + 1, r);
    vector<long long> temp(r - l + 1, 0);
    int lidx = l, ridx = m + 1, tidx = 0;
    while (lidx <= m && ridx <= r) {
        if (nums[lidx] <= nums[ridx]) {
            temp[tidx++] = nums[lidx++];
        } else {
            temp[tidx++] = nums[ridx++];
            res += m - lidx + 1;
        }
    }
    while (lidx <= m) {
        temp[tidx++] = nums[lidx++];
    }
    while (ridx <= r) {
        temp[tidx++] = nums[ridx++];
    }
    for (int i = 0; i < temp.size(); ++i) {
        nums[i + l] = temp[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << count_inversions(nums, 0, n - 1) << endl;
    return 0;
}

