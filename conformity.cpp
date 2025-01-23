#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<vector<int>, int> cf;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> curr(5);
        cin >> curr[0] >> curr[1] >> curr[2] >> curr[3] >> curr[4];
        sort(curr.begin(), curr.end()); 
        if (cf.find(curr) == cf.end()) cf[curr] = 0;
        ++cf[curr];
        mx = max(mx, cf[curr]);
    }
    int res = 0;
    for (auto& p : cf) {
        if (p.second == mx) res += p.second;
    }
    cout << res << endl;
    return 0;
}

