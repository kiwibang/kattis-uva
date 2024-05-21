#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the input
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // handle the cases
    if (t == 1) {
        cout << 7 << endl;
    } else if (t == 2) {
        if (a[0] > a[1]) {
            cout << "Bigger" << endl;
        } else if (a[0] < a[1]) {
            cout << "Smaller" << endl;
        } else {
            cout << "Equal" << endl;
        }
    } else if (t == 3) {
        int mn = min(a[0], min(a[1], a[2]));
        int mx = max(a[0], max(a[1], a[2]));
        if (a[0] != mn && a[0] != mx) {
            cout << a[0] << endl;
        } else if (a[1] != mn && a[1] != mx) {
            cout << a[1] << endl;
        } else {
            cout << a[2] << endl;
        }
    } else if (t == 4) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        cout << sum << endl;
    } else if (t == 5) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & 1) == 0) {
                sum += a[i];
            }
        }
        cout << sum << endl;
    } else if (t == 6) {
        for (int i = 0; i < n; ++i) {
            cout << (char) ((a[i] % 26) + 'a');
        }
        cout << endl;
    } else { // t == 7
        int i = 0;
        set<int> encountered;
        while (true) {
            encountered.insert(i);
            i = a[i];
            if (i < 0 || i >= n) {
                cout << "Out" << endl;
                return 0;
            }
            if (i == n - 1) {
                cout << "Done" << endl;
                return 0;
            }
            if (encountered.find(i) != encountered.end()) {
                cout << "Cyclic" << endl;
                return 0;
            }
        }
    }
    return 0;
}
