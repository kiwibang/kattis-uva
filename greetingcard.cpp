#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_hash(int x, int y) {
    return (((ll) x) << 32) + y;
}


int main() {
    int n, res = 0;
    cin >> n;
    unordered_set<ll> s; 
    vector<int> x(n), y(n);
    // init direction vector
    vector<int> dx = {-2018, -1680, -1680, -1118, -1118, 0, 0, 1118, 1118, 1680, 1680, 2018};
    vector<int> dy = {0, -1118, 1118, -1680, 1680, -2018, 2018, -1680, 1680, -1118, 1118, 0};
    // then insert all points into set
    for (int i = 0; i < n; ++i) {
       cin >> x[i] >> y[i];
       s.insert(get_hash(x[i], y[i])); 
    }
    // then process each point, check neighbour
    for (int i = 0; i < n; ++i) {
        int cx = x[i], cy = y[i];
        s.erase(get_hash(cx, cy));
        for (int j = 0; j < 12; ++j) {
            // current  neighbour point
            int nx = cx + dx[j], ny = cy + dy[j];
            if (nx < 0 || ny < 0) continue;
            // if we have neighbour point, update res
            if (s.find(get_hash(nx, ny)) != s.end()) ++res; 
        } 
    }
    cout << res << endl;
    return 0;
}
