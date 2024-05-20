#include <bits/stdc++.h>
using namespace std;

int main() {
    int l;
    string highway;
    while (true) {
        cin >> l;
        if (l == 0) {
            return 0;
        }
        cin >> highway;
        int mn = l;
        int lr = -l, ld = -l;
        for (int i = 0; i < l; ++i) {
            if (highway[i] == 'Z') {
                mn = 0;
                break;
            }
            if (highway[i] == 'R') {
                mn = min(mn, i - ld);
                lr = i;
            } else if (highway[i] == 'D') {
                mn = min(mn, i - lr);
                ld = i;
            }
        }
        cout << mn << endl;
    }
    return 0;
}
