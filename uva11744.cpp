#include <bits/stdc++.h>
using namespace std;

bool compute(string a, string b, string& c, string& d) {
    c = "", d = "";
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            c += "1";
        } else {
            c += "0"; 
        }
        if ((a[i] == '0') || (b[i] == '0')) {
            d += "0";
        } else {
            d += "1";
        }
    }
    if (d[0] == '1') {
        d = "overflow";
        return false;
    }
    d = d.substr(1);
    d += "0";
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] != '0') {
            return true;
        }
    }
    return false;
}
int main() {
    // get the number of testcases
    int t;
    cin >> t;
    // loop over the testcases
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        // read the current values of a and b
        string a, b, c, d;
        cin >> a >> b;
        // print the inital values of a and b
        cout << a << " " << b << endl;
        // apply algorithm until either b == 0 or b ≤ 2^31
        while (compute(a, b, c, d)) {
            a = c;
            b = d;
            cout << a << " " << b << endl;
        }
        cout << c << " " << d << endl;
    }
    return 0;
}
