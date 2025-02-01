#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n, m;
    cin >> c >> n >> m;
    vector<long long> f(c + 1, 0);
    for (int i = 0; i < n; ++i) {
        int ci;
        cin >> ci;
        ++f[ci];
    }
    vector<int> days;
    for (int i = 0; i < m; ++i) {
        int di;
        cin >> di;
        days.push_back(di);
    }
    vector<long long> res(51, 0);
    for (int i = 0; i <= 50; ++i) {
        for (int j = 1; j <= c; ++j) res[i] += f[j];
        vector<long long> temp(c + 1, 0);
        for (int j = 1; j <= c; ++j) {
            if ((j << 1) > c) {
                temp[j] += (f[j] << 1);
            } else {
                temp[j << 1] += f[j];
            }
        }
        f = temp;
    }
    for (int day : days) {
        cout << res[day] << endl;
    }
    return 0;
}

