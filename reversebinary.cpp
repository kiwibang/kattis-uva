#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    while (n) {
        res = (res << 1) + (n & 1);
        n >>= 1;
    }
    cout << res << endl;
    return 0;
}

