// credits: https://github.com/mpfeifer1/Kattis/blob/master/srednji.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long res = 0, s = 0;
    int n, b, midx;
    cin >> n >> b;
    vector<int> nums(n);
    map<long long, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] == b) midx = i;
    }
    // go left
    for (int i = midx - 1; i >= 0; --i) {
        if (nums[i] > b) {
            ++s;
        } else {
            --s;
        }
        ++mp[s];
    }
    res = mp[0];
    s = 0;
    for (int i = midx + 1; i < n; ++i) {
        if (nums[i] > b) {
            ++s;
        } else {
            --s;
        }
        res += mp[-s];
    }
    cout << res << endl;
    return 0;
}

