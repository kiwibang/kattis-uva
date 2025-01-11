#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, n, cr;
    cin >> r >> n;
    vector<bool> booked(r + 1, false);
    for (int i = 0; i < n; ++i) {
        cin >> cr;
        booked[cr] = true;
    }
    for (int i = 1; i <= r; ++i) {
        if (!booked[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "too late" << endl;
    return 0;
}

