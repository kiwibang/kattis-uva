#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int d, m, y, qy;
        cin >> d >> m >> y >> qy;
        int res = 0;
        if (d == 29 && m == 2) {
            for (int yr = y + 1; yr <= qy; ++yr) {
                if (isLeapYear(yr)) {
                    ++res;
                }
            }
        } else {
            res = qy - y;
        }
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}
