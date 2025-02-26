#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, currnum = 0;
        cin >> n >> x;
        int lim = ~x & (x + 1);
        int temp = x;
        int idx = 0;
        while (lim) {
            currnum = currnum + ((temp & 1) << idx++);
            temp >>= 1;
            lim >>= 1; 
        }
        // make the array 
        vector<int> res(n);
        int curror = 0, z = currnum;
        currnum = 0;
        for (int i = 0; i < n; ++i) {
            curror |= currnum;
            if ((curror != x && i == n - 1) || currnum > z) {
                res[i] = x;
            } else {
                res[i] = currnum++;;
            }
            cout << res[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

