#include <bits/stdc++.h>
using namespace std;

double convert(double f) {
    return (f * 5 - 160) / 9;
}

double convert2(double c) {
    return ((c * 9) / 5) + 32;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        double init, delta;
        cin >> init >> delta;
        init = convert2(init) + delta;
        cout << fixed << setprecision(2) << "Case " << tc << ": " << convert(init) << endl;
    }
    return 0;
}
