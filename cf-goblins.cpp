#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string mn;
        cin >> mn;
        long long up = 0, down = 0;
        for (int i = 0; i < n; ++i) {
            if (mn[i] == '-') {
                ++up;
            } else {
                ++down;
            }
        }
        long long left = ceil((float) up / 2), right = up / 2;
        cout << left * right * down << endl;
    }
    return 0;
}

