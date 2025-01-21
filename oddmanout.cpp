#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, curr;
        cin >> n;
        unordered_set<int> ppl;
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            if (ppl.find(curr) != ppl.end()) {
                ppl.erase(curr);
            } else {
                ppl.insert(curr);
            }
        }
        for (int p : ppl) {
            cout << "Case #" << tc << ": " <<  p << endl;
        }     
    }
    return 0;
}

