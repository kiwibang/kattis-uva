#include <bits/stdc++.h>
using namespace std;

bool check(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, k;
        cin >> x >> k;
        if ((k == 1 && check(x)) || (k == 2 && x == 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

