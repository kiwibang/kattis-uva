#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a + b == c || a * b == c || a - b == c || b - a == c || (double) a / b == c || (double) b / a == c) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
