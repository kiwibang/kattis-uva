#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m, memrd, memwr, res = 0;
        cin >> n;
        unordered_map<int, int> memtowt;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            int ctime = 1;
            for (int j = 0; j < m - 1; ++j) {
                cin >> memrd;
                if (memtowt.find(memrd) != memtowt.end()) {
                    ctime = max(ctime, memtowt[memrd] + 1);
                }
            }
            res = max(res, ctime);
            cin >> memwr;
            memtowt[memwr] = ctime;
        }
        cout << tc << " " << res << endl;
    }
    return 0;    
}

