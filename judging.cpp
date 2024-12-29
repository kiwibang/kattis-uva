#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    int n, res = 0;
    cin >> n;
    map<string, int> m1;
    string curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (m1.find(curr) == m1.end()) m1[curr] = 0;
        ++m1[curr];
    }
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (m1.find(curr) != m1.end()) {
            --m1[curr];
            ++res;
            if (!m1[curr]) m1.erase(curr);
        }
    }
    cout << res << endl;
    return 0;
}

