#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int ng, nm;
        cin >> ng >> nm;
        map<int, int> dg;
        map<int, int> dm;
        vector<int> mg;
        vector<int> mm;
        for (int i = 0; i < ng; ++i) {
            int curr;
            cin >> curr;
            if (!dg[curr]) {
                dg[curr] = 0;
                mg.push_back(curr);
            }
            ++dg[curr];
        }
        for (int i = 0; i < nm; ++i) {
            int curr;
            cin >> curr;
            if (!dm[curr]) {
                dm[curr] = 0;
                mm.push_back(curr);
            }
            ++dm[curr];
        }
        sort(mg.begin(), mg.end());
        sort(mm.begin(), mm.end());
        int i = 0;
        int j = 0;
        int n = mg.size();
        int m = mm.size();
        while (i < n && j < m) {
            if (mg[i] < mm[j]) {
                i++; // kill all the weakest monsters in godzilla army
            } else {
                j++; // kill all the weakest monsters in mechagodzilla army
            }
        }
        if (i >= n && j < m) {
            cout << "MechaGodzilla" << endl;
        } else if (i < n && j >= m) {
            cout << "Godzilla" << endl;
        } else {
            cout << "uncertain" << endl;
        }
    }
    return 0;
}
