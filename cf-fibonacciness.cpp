#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a1, a2, a3, a4, a5;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a1 >> a2 >> a4 >> a5;
        int res = 0;
        // try all 3, get max
        a3 = a1 + a2;
        int cnt = 1;
        if (a2 + a3 == a4) ++cnt;
        if (a3 + a4 == a5) ++cnt;
        res = max(res, cnt); 
        a3 = a4 - a2, cnt = 1;
        if (a1 + a2 == a3) ++cnt;
        if (a3 + a4 == a5) ++cnt;
        res = max(res, cnt); 
        a3 = a5 - a4, cnt = 1;
        if (a1 + a2 == a3) ++cnt;
        if (a2 + a3 == a4) ++cnt;
        res = max(res, cnt); 
        cout << res << endl;
    }
    return 0;
}

