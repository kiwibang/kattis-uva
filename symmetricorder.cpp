#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    bool t;
    for (int i = 1;; ++i) {
        cin >> n;
        if (!n) break;
        vector<string> res(n);
        l = 0, r = n - 1;
        t = true;
        for (int j = 0; j < n; ++j) {
            if (!t) {
                cin >> res[r--];
            } else {
                cin >> res[l++];
            }
            t = !t;
        }
        cout << "SET " << i << endl;
        for (string& name : res) cout << name << endl;
    }
    return 0;
}

