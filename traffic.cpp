#include <bits/stdc++.h>
using namespace std;

void solve(float p1, float p2, vector<int>& e1, vector<int>& e2) {
    if (p1 > p2) {
        solve(p2, p1, e2, e1);
        return;
    }
    int n = e1.size(), m = e2.size(), i = 0, j = 0;
    bool m1 = false, m2 = false;
    int lim = n == 0 && m == 0 ? 0 : n == 0 ? e2[m - 1] : m == 0 ? e1[n - 1] : max(e1[n - 1], e2[m - 1]);
    // simulate the passage of time
    for (int k = 0; k <= lim; ++k) {
        // update movements
        if (m1) ++p1;
        if (m2) ++p2;
        // check if there is a collision
        if (p1 + 4.4 >= p2) {
            cout << "bumper tap at time " << k << endl;
            return;
        }
        // check if current time is equals to the current events
        if (i < n && e1[i] == k) {
            m1 = !m1;
            ++i;
        }
        if (j < m && e2[j] == k) {
            m2 = !m2;
            ++j;
        }
    }
    if (m1 && !m2) {
        while (p1 + 4.4 < p2) {
            ++p1;
            ++lim;
        }
        cout << "bumper tap at time " << lim << endl;
        return;
    }
    cout << "safe and sound" << endl;
}
int main() {
    float p1, p2;
    cin >> p1 >> p2;
    int n, m, curr;
    cin >> n;
    vector<int> e1(n);
    for (int i = 0; i < n; ++i) cin >> e1[i];
    cin >> m;
    vector<int> e2(m);
    for (int i = 0; i < m; ++i) cin >> e2[i];
    solve(p1, p2, e1, e2);
    return 0;
}

