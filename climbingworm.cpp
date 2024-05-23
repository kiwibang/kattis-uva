#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, h;
    cin >> a >> b >> h;
    int res = 0, height = 0;
    while (true) {
        height += a;
        ++res;
        if (height >= h) {
            cout << res << endl;
            return 0;
        }
        height -= b;
    }
    return 0;
}
