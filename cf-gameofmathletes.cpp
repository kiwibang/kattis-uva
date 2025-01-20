#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, curr;
        cin >> n >> k;
        // count the frequency of the integers
        vector<int> f(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            ++f[curr];
        }
        // then count the number of pairings
        int score = 0;
        for (int a = 1; a <= n; ++a) {
            int b = k - a; // calculate target value of b
            if (b >= 1 && b <= n) { // case where b is within range => number of pairings = min(f[a], f[b])
                if (f[a] == 0 || f[b] == 0) continue;
                if (a == b) {
                    score += (f[a] >> 1);
                    f[a] = 0;
                } else {
                    int temp = min(f[a], f[b]);
                    score += temp;
                    f[a] -= temp;
                    f[b] -= temp;
                }
            } 
        }
        cout << score << endl;
    }
    return 0;
}

