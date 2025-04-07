minclude <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // read in input
        int n, r1, r2;
        cin >> n;
        vector<int> nums(n);
        unordered_map<int, int> f;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (f.find(nums[i]) == f.end()) f[nums[i]] = 0;
            f[nums[i]] = i + 1;
        }
        if (f.size() == n) { // is a permutation of 1 to n
                             // try i, j such that xi = 1, xj = n. if output equals and ≥ 1, then B, else A since 
            int oidx = f[1], nidx = f[n];
            cout << "? " << oidx << " " << nidx << endl;
            cin >> r1;
            cout << endl;
            cout << "? " << nidx << " " << oidx << endl;
            cin >> r2;
            cout << endl;
            if (r1 == r2 && r1 >= n - 1) {
                cout << "! B" << endl; 
            } else {
                cout << "! A" << endl; 
            }
        } else { // is not a permutation 
                 // find element that does not exist
            int ms = 1, el = (*f.begin()).first;
            for (; ms <= n; ++ms) {
                if (f.find(ms) == f.end()) {
                    break;
                }
            }
            // then run query
            cout << "? " << ms << " " << el << endl;
            cin >> r1;
            cout << endl;
            cout << "? " << ms << " " << el << endl;
            cin >> r2;
            cout << endl;
            cout << (r1 == 0 ? "! A" : "! B") << endl;
        }
        cout << endl;
    }
    return 0;
}

