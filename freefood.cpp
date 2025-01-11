#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, res = 0;
    cin >> n;
    vector<bool> have(366, false);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        for (int j = a; j <= b; ++j) {
            have[j] = true;
        }
    }
    for (int i = 1; i <= 365; ++i) if (have[i]) ++res;
    cout << res << endl; 
    return 0;
}

