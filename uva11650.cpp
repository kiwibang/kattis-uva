#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string time;
        cin >> time;
        int hr = (time[0] - '0') * 10 + (time[1] - '0');
        int mn = (time[3] - '0') * 10 + (time[4] - '0');
        // reflect 
        hr = hr == 12 ? 0 : hr;
        int d = abs(720 - (hr * 60 + mn));
        if (d == 0) {
            cout << setfill('0') << setw(2) << hr << ":";
            cout << setfill('0') << setw(2) << mn << endl;
        } else {
            hr = d / 60;
            if (hr == 0) {
                hr = 12;
            }
            mn = d % 60; 
            cout << setfill('0') << setw(2) << hr << ":";
            cout << setfill('0') << setw(2) << mn << endl;
        }
    }
    return 0;
}
