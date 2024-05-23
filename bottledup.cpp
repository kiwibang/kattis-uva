#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, v1, v2;
    cin >> s >> v1 >> v2;
    // try to fill with the bigger bottle as much as possible
    int res1 = s / v1;
    int res2 = (s - res1 * v1) / v2;
    int mn0 = 9999999;
    int mn1 = 9999999;
    int mn2 = 9999999;
    while (res1 >= 0) {
        if (res1 * v1 + res2 * v2 == s && ((res1 + res2) < mn0)) {
            mn0 = res1 + res2;
            mn1 = res1;
            mn2 = res2;
            break;
        }
        --res1;
        while (true) {
            if (res1 * v1 + (res2 + 1) * v2 > s) {
                break;
            }
            ++res2;
        }
    }
    if (mn0 == 9999999) {
        cout << "Impossible" << endl;
    } else {
        cout << mn1 << " " << mn2 << endl;
    }
    return 0;
}
