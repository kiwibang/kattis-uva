#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double b, p;
        cin >> b >> p;
        cout << fixed << setprecision(4) << (60 / (p / (b - 1))) << " " << (60 * b) / p << " " << (60 / (p / (b + 1))) << endl;
    }
    return 0;
}
