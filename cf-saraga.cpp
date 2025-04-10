#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> ls, lt;
    int n = s.size(), m = t.size();
    for (int i = 1; i < n; ++i) {
        if (ls.find(s[i]) == ls.end()) ls[s[i]] = i;
    }
    for (int i = m - 2; i >= 0; --i) {
        if (lt.find(t[i]) == lt.end()) lt[t[i]] = i;
    }
    string res = "-1";
    int mn = INT_MAX;
    for (auto [c, i] : ls) {
        if (lt.count(c)) {
            int tpos = lt[c];
            string cur = s.substr(0, i) + t.substr(tpos);
            if (cur.size() < mn) {
                res = cur;
                mn = cur.size();
            }
        }
    }
    cout << res << '\n';
    return 0;
}

