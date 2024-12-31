#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> cars(n);
    for (int i = 0; i < n; ++i) cin >> cars[i];
    sort(cars.begin(), cars.end());
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        res = max(res, max(0, p * (i + 1) - cars[i]) + cars[0]);
    }
    cout << res << endl;
    return 0;
}

