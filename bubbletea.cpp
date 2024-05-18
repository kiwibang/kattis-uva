#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int teaPrices[n];
    for (int i = 0; i < n; ++i) {
        cin >> teaPrices[i];
    }
    int m;
    cin >> m;
    int toppingPrices[m];
    for (int i = 0; i < m; ++i) {
        cin >> toppingPrices[i];
    }
    int mn = 1000000000;
    vector<vector<int> > mixedMatrix;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<int> temp;
        while (k--) {
            int curr;
            cin >> curr;
            temp.push_back(curr);
            mn = min(mn, teaPrices[i] + toppingPrices[curr - 1]);
        }
        mixedMatrix.push_back(temp);
    }
    int x;
    cin >> x;
    cout << max(0, (x / mn) - 1) << endl;
    return 0;
}
