#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr;
    long long c = 0;
    cin >> n;
    set<int> tree;
    vector<int> numtoht(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        // find the next smallest element of the set and the next largest element
        tree.insert(curr);
        auto sml = tree.find(curr);
        auto lrg = tree.find(curr);
        int ht = 0;
        if (sml != tree.begin()) {
            sml--;
            ht = max(ht, numtoht[*sml]);
        }
        if (lrg != tree.end()) {
            ++lrg;
            if (lrg != tree.end()) ht = max(ht, numtoht[*lrg]);
        }
        numtoht[curr] = ht + 1;
        c += ht;
        cout << c << endl;
    }
    return 0;
}

