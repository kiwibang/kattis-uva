#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, ls, mx;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        ls = min(min(a, b), c);
        mx = max(max(a, b), c);
        cout << "Case " << i << ": "; 
        if (a != ls && a != mx) {
            cout << a << endl;
        } else if (b != ls && b != mx) {
            cout << b << endl;
        } else if (c != ls && c != mx) {
            cout << c << endl;
        }
    }
    return 0;
}
