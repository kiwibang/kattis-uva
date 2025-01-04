#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long res = 0;
    char cc;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cc;
        res = (res << 1) + (cc == 'O');
    }
    cout << res << endl;
    return 0;
}

