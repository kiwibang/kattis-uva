#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = 0;
    int b = 0;
    int l = 0;
    int r = 0;
    while (n--) {
        string temp;
        cin >> temp;
        t = temp[0] == '0' ? t + 1 : t;
        b = temp[1] == '0' ? b + 1 : b;
        l = temp[2] == '0' ? l + 1 : l;
        r = temp[3] == '0' ? r + 1 : r;
    }
    int sw, tb, lr, mn;
    mn = min(t + b, l + r);
    sw = (mn * 2) / 4;
    tb = (t + b) - sw * 2;
    lr = (l + r) - sw * 2;
    cout << sw << " " << tb << " " << lr << endl;
    return 0;
}
