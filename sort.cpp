#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] != b[1] ? a[1] > b[1] : a[2] < b[2];
}

int main() {
    int n, c, curr;
    cin >> n >> c;
    map<int, pair<int, int> > f;
    vector<vector<int> > ps;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (f.find(curr) == f.end()) f[curr] = pair<int,int>(0, i);
        ++f[curr].first;
    }
    for (auto& p : f) ps.push_back({p.first, p.second.first, p.second.second});
    sort(ps.begin(), ps.end(), cmp);
    for (int i = 0; i < ps.size(); ++i) {
        while (ps[i][1]--) {
            cout << ps[i][0];
            if (ps[i][1] > 0) cout << " ";
        }
        if (i < ps.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

