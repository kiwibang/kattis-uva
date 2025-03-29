#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int evenones = 0, oddones = 0, evencap = 0, oddcap = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (a[i] == '1') ++evenones;
                if (b[i] == '1') ++oddones;
                ++oddcap;
            } else {
                if (a[i] == '1') ++oddones;
                if (b[i] == '1') ++evenones;
                ++evencap;
            }
        }
        if (evenones > evencap || oddones > oddcap) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

