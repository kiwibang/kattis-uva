#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> curr;
            res[i] |= curr; 
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

