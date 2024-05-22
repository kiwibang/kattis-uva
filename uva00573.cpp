#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        double h, u, d, f;
        cin >> h >> u >> d >> f;
        if (h == 0) {
            return 0;
        }
        f = (f / 100) * u;
        // go through the days
        int daysE = 0;
        double pos = 0;
        while (true) {
            ++daysE;
            // daytime hustling only if snail climbs a negative distance
            if (u > 0) {
                pos += u;
            }
            // check if climb out
            if (pos > h) {
                cout << "success on day " << daysE << endl; 
                break;
            }
            // nighttime resting
            pos -= d;
            // if fail
            if (pos < 0) {
                cout << "failure on day " << daysE << endl;
                break;
            }
            // factor for shagness
            u -= f;
        }
    }
    return 0;
}
