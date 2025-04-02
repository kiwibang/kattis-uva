#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt;
        cin >> n;
        unordered_map<string, int> f;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s >> cnt;
            if (f.find(s) == f.end()) f[s] = 0;
            f[s] += cnt;
        }
        vector<pair<string, int>> res;
        for (auto& p : f) {
            res.push_back(p);
        }
        sort(res.begin(), res.end(), cmp);
        cout << res.size() << endl;
        for (pair<string, int> p : res) cout << p.first << " " << p.second << endl;
    }
    return 0;
}

