#include <bits/stdc++.h>
using namespace std;

int hp(vector<int> aa, vector<int> ba) {
    int res = 0, aidx = 1, bidx = 100;
    bool done = false;
    while (true) {
        while (aa[aidx] == 0) {
            ++aidx;
            if (aidx > 100) {
                done = true;
                break;
            }    
        }
        while (ba[bidx] == 0) {
            --bidx;
            if (bidx < 1) {
                done = true;
                break;
            }    
        }
        if (done) break;
        res = max(res, aidx + bidx);
        int m = min(aa[aidx], ba[bidx]);
        aa[aidx] -= m;
        ba[bidx] -= m;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a, b, mn, mx;
    vector<int> aa(101, 0), ba(101, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ++aa[a], ++ba[b];
        cout << hp(aa, ba) << endl;
    }
    return 0;
}

