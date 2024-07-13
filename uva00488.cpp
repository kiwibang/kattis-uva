#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        int a, f;
        cin >> a >> f;
        // print f waves
        for (int i = 0; i < f; ++i) {
            // print the waves
            for (int j = 1; j <= a; ++j) {
                for (int k = 1; k <= j; ++k) {
                    cout << j;
                }
                cout << endl;
            }
            for (int j = a - 1; j >= 1; --j) {
                for (int k = 1; k <= j; ++k) {
                    cout << j;
                }
                cout << endl;
            }
            if (i < f - 1)
                cout << endl;
        }
    }
    return 0;
}
