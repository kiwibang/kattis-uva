#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string curr;
        unordered_set<string> s;
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            s.insert(curr);
        }
        cout << s.size() << endl;
    }
    return 0;
}

