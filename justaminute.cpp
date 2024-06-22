#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a = 0.00, b = 0.00;
    for (int i = 0; i < n; ++i) {
        double m, s;
        cin >> m >> s;
        a += m;
        b += s;
    }
    double avg = a == 0 ? 0 : b / (a * 60);
    if (avg <= 1) {
        cout << "measurement error" << endl;
    } else {
        cout << setprecision(11) << avg << endl;
    }
    return 0;
}
