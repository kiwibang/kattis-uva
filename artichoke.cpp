#include <bits/stdc++.h>
using namespace std;

double f(double p, double a, double b, double c, double d, double k);

int main() {
    double p, a, b, c, d, n, mx, curr, res = 0;
    cin >> p >> a >> b >> c >> d >> n;
    mx = f(p, a, b, c, d, 1);
    for (int i = 2; i <= n; ++i) {
        curr = f(p, a, b, c, d, i);
        mx = max(mx, curr);
        res = max(res, mx - curr);
    }
    cout << setprecision(9) << res << endl;
    return 0;
}

double f(double p, double a, double b, double c, double d, double k) {
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}
