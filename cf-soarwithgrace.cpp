
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, numsame = 0, sameidx;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> atopos(n + 1), btopos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            atopos[a[i]] = i;
        }
        unordered_map<int, int> atob;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            btopos[b[i]] = i;
            if (a[i] == b[i]) {
                ++numsame;
                sameidx = i;
            }
        }
        if ((n % 2 == 0 && numsame != 0) || (n % 2 == 1 && numsame != 1)) {
            cout << "-1" << "\n";
            continue;
        }
        bool ok = true;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; ++i) {
            int ca = a[i], cb = b[i], mn = min(ca, cb), mx = max(ca, cb);
            pair<int, int> p = {mn, mx};
            if (mp.find(p) == mp.end()) mp[p] = 0;
            ++mp[p];
        }
        for (pair<pair<int, int>, int> p : mp) {
            if (p.first.first != p.first.second && p.second != 2) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "-1" << "\n";
            continue;
        }
        vector<pair<int, int>> swap;
        if (n % 2 == 1 && sameidx != n / 2) {
            int t1 = a[sameidx];
            a[sameidx] = a[n / 2];
            a[n / 2] = t1;
            atopos[a[sameidx]] = sameidx, atopos[a[n / 2]] = n / 2;
            int t2 = b[sameidx];
            b[sameidx] = b[n / 2];
            b[n / 2] = t2;
            btopos[b[sameidx]] = sameidx, btopos[b[n / 2]] = n / 2;
            swap.push_back({sameidx + 1, (n / 2) + 1});
        }
        for (int i = 0; i < n; ++i) {
            if (b[i] != a[n - 1 - i]) {
                int tg = btopos[a[n - 1 - i]];
                // swap a
                int t1 = a[i];
                a[i] = a[tg];
                a[tg] = t1;
                atopos[a[i]] = i, atopos[a[tg]] = tg;
                // swap b
                int t2 = b[i];
                b[i] = b[tg];
                b[tg] = t2;
                btopos[b[i]] = i, btopos[b[tg]] = tg;
                swap.push_back({i + 1, tg + 1});
            }
        }
        cout << swap.size() << "\n";
        for (pair<int, int>& p : swap) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
