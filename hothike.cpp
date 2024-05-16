#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ts[n];
    for (int i = 0; i < n; ++i) {
        cin >> ts[i];
    }
    cout << endl;
    int fh, sh, cm, bd, bt = 41;
    for (int i = 3; i <= n; ++i) {
        fh = ts[i - 3];
        sh = ts[i - 1];
        cm = max(fh, sh);
        if (cm < bt) {
            bd = i - 2;
            bt = cm;
        }
    }
    cout << bd << " " << bt << endl;
    return 0;
}
