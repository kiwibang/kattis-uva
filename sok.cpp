#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, i, j, k;
    cin >> a >> b >> c >> i >> j >> k;
    double mn = min(a / i, min(b / j, c / k));
    cout << fixed << setprecision(6) << max(0.0, a - (mn * i)) << " " << max(0.0, b - (mn * j)) << " " << max(0.0, c - (mn * k));
    return 0;
}
