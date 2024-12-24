#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    vector<vector<int> > playlists(m, vector<int>(s, 0));
    vector<vector<int> > prefsums(m, vector<int>(s, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < s; ++j) cin >> playlists[i][j];
        prefsums[i][0] = playlists[i][0];
        for (int j = 1; j < s; ++j) prefsums[i][j] = prefsums[i][j - 1] + playlists[i][j];
    }
    // find the smallest index
    int l;
    for (int j = 0; j < s; ++j) {
        int crr = prefsums[0][j];
        bool ok = true;
        for (int i = 1; i < m; ++i) {
            if (prefsums[i][j] != crr) {
                ok = false;
                break;
            }
        }
        if (ok) {
            l = j;
            break;
        }
    }
    vector<int> res(playlists[0].begin(), playlists[0].begin() + l + 1);
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

