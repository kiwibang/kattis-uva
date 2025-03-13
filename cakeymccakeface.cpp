#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> st(n), en(m);
    for (int i = 0; i < n; ++i) {
        cin >> st[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> en[i];
    }
    // get all differences since n and m are small and record the frequency of each difference, use map to order the difference automatically, at most O(nm) differences
    map<int, int> f;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int diff = en[j] - st[i];
            if (diff < 0) continue;
            if (f.find(diff) == f.end()) f[diff] = 0;
            ++f[diff];
        }
    } 
    // then get the difference that maximizes the number of pairs
    int res = 0, bd = 0;
    for (auto& p : f) {
        if (p.second > res) {
            res = p.second;
            bd = p.first;
        } 
    }
    cout << bd << endl;
    return 0;
}

