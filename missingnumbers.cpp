#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prev = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int curr;
        cin >> curr;
        for (int j = prev + 1; j < curr; ++j) {
            ok = false;
            cout << j << endl;
        }
        prev = curr;
    }
    if (ok) {
        cout << "good job" << endl;
    }
    return 0;
}
