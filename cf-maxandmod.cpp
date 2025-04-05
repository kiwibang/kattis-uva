#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (!(n & 1)) {
            cout << "-1\n";
            continue;
        }   
        cout << n;
        for (int i = 1; i <= n - 1; ++i) cout << " " <<  i;
        cout << "\n";
    }
    return 0;
}
 
