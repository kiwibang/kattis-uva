#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (res.size() == 0 || curr > res[res.size() - 1]) res.push_back(curr);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) cout << " ";
    } 
    cout << endl;
    return 0;
}
