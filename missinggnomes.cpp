#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> missing;
    for (int i = 1; i <= n; ++i) {
        missing.insert(i);
    }
    vector<int> gn(m);
    for (int i = 0; i < m; ++i) {
        cin >> gn[i];
        missing.erase(gn[i]);
    }
    int prev = 1;
    for (int g : gn) {
        while (!missing.empty() && *missing.begin() < g) {
            cout << *missing.begin() << endl;
            missing.erase(missing.begin());
        }
        cout << g << endl;
        prev = g;
    }
    while (!missing.empty()) {
        cout << *missing.begin() << endl;
        missing.erase(missing.begin());
    }
    return 0;
}

