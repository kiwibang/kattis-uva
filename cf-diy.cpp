#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long num;
        cin >> n;
        map<long long, int> f;
        for (int i = 0; i < n; ++i) {
            cin >> num; 
            if (!f.count(num)) f[num] = 0;
            ++f[num];
        }
        // get min x1 and min y1
        long long x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
        for (auto it = f.begin(); it != f.end(); ++it) {
            if (it->second < 2) continue; // cannot make x1/y1
            // else we make x1
            if (x1 == INT_MAX) {
                x1 = it->first;
                it->second -= 2; // 2 elements of it->first needed
            }
            // make y1 if enough elements
            if (y1 == INT_MAX && it->second >= 2) {
                y1 = it->first;
                it->second -= 2; // 2 elements of it->first needed
                break;
            }
        }
        // get max x2 and max y2
        for (auto it = f.rbegin(); it != f.rend(); ++it) {
            if (it->second < 2) continue; // cannot make x2/y2
            // else we make x2
            if (x2 == INT_MIN) {
                x2 = it->first;
                it->second -= 2; // 2 elements of it->first needed
            }
            // make y2 if enough elements
            if (y2 == INT_MIN && it->second >= 2) {
                y2 = it->first;
                it->second -= 2; // 2 elements of it->first needed
                break;
            }
        }
        if (x1 == INT_MAX || x2 == INT_MIN || y1 == INT_MAX || y2 == INT_MIN) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if ((x2 - x1) * (y2 - y1) > (x2 - y1) * (y2 - x1)) {
                cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y1 << " " << x2 << " " << y2 << '\n';
            } else {
                cout << y1 << " " << x1 << " " << y1 << " " << y2 << " " << x2 << " " << x1 << " " << x2 << " " << y2 << '\n';
            }
        }
    }
    return 0;
}

