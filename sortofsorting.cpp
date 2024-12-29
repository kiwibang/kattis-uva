#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

int main() {
    int n, id = 0;
    while (true) {
        cin >> n;
        if (!n) break;
        vector<string> names(n);
        for (int i = 0; i < n; ++i) cin >> names[i];
        stable_sort(names.begin(), names.end(), cmp);
        for (string name : names) cout << name << endl;
        cout << endl;
    }
    return 0;
}

