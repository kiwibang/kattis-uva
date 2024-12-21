#include <bits/stdc++.h>
using namespace std;

int main() {
    // count the number of actions at each timestamp. max number of actions at any second 
    // is the ans, after dividing it by 2 and ceil the result
    vector<int> serving(43201, 0);
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, t;
        cin >> d >> t;
        ++serving[t - 2 * d], ++serving[t - d], ++serving[t];
    }
    int res = 0;
    for (int i = 0; i <= 43200; ++i) res = max(res, serving[i]);
    cout << (int) ceil(res / 2.0) << endl;
    return 0;
}

