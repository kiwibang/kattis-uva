#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> singles(n);
        for (int i = 0; i < n; ++i) cin >> singles[i];
        int mn = INT_MAX;
        set<int> cdsingles;
        for (int i = n - 1; i >= 0; --i) {
            // case where current is less than the min so far => CD sales needed
            if (singles[i] > mn) cdsingles.insert(singles[i]);
            mn = min(mn, singles[i]);
        }
        cout << cdsingles.size() << endl;
        for (int i = 1; i <= n; ++i) if (cdsingles.find(i) != cdsingles.end()) cout << i << endl; 
    }
    return 0;
}

