#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string curr;
    unordered_map<string, int> f;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (f.find(curr) == f.end()) {
            f[curr] = 0;
        }
        ++f[curr];
    }
    int mn = INT_MAX;
    for (auto& [costume, count] : f) {
        mn = min(mn, count);
    }
    vector<string> res;
    for (auto& [costume, count] : f) {
        if (count == mn) res.push_back(costume); 
    }
    sort(res.begin(), res.end());
    for (string& s : res) cout << s << endl;
    return 0;
}

