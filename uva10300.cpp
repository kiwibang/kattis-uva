#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f, sz, ac, envl, res;
    cin >> n;
    while (n--) {
        cin >> f;
        res = 0;
        while (f--) {
            cin >> sz >> ac >> envl;
            res += sz * envl;
        }
        cout << res << endl;
    }
    return 0;
}
