#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<long, string>& a, const pair<long long, string>& b) {
    return a.first > b.first;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<long long, string> > songs;
    long long f;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> f >> s;
        songs.push_back({f * i, s});
    }
    stable_sort(songs.begin(), songs.end(), cmp);
    for (int i = 0; i < m; ++i) {
        cout << songs[i].second << endl;
    }
    return 0;
}

