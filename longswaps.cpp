#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, scp;
    int k, n;
    cin >> s >> k;
    n = s.size();
    scp = s;
    if (k <= n / 2) {
        cout << "Yes" << endl;
        return 0;
    }
    sort(scp.begin(), scp.end());
    for (int i = n - k; i <= k - 1; ++i) {
        if (scp[i] != s[i]) {
            cout << "No" << endl;
            return 0;
        }   
    } 
    cout << "Yes" << endl;
    return 0;
}

