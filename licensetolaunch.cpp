#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mn = 1000000007, mnIdx, curr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr < mn) {
            mn = curr;
            mnIdx = i;
        }
    }
    cout << mnIdx << endl;
    return 0;
}
