#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        string time;
        cin >> time;
        if (time == "0:00") {
            break;
        }
        double hr = stoi(time.substr(0, time.find(':')));
        double mn = stoi(time.substr(time.find(':') + 1, time.size()));
        hr = hr * 30 + mn * 0.5;
        mn = mn * 6;
        double res = hr - mn;
        if (res < 0) {
            res *= -1;
        }
        if (res > 180) {
            res = 360 - res;
        }
        cout << fixed << setprecision(3) << res << endl;
    }
    return 0;
}
