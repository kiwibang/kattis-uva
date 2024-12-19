#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> bls(n);
    for (int i = 0; i < n; ++i) cin >> bls[i];
    unordered_map<int, int> arws;
    for (int i = 0; i < n; ++i) {
        int bl = bls[i];
        if(arws.find(bl) == arws.end()) { // no existing arrow => use 1 arrow to pop
            ++res;
            if (arws.find(bl - 1) == arws.end()) arws[bl - 1] = 0;
            ++arws[bl - 1]; // save the arrow for future balloons
            continue; // next iteration
        }
        // have existing arrow => use it and move down 1 height
        --arws[bl];
        if (!arws[bl]) arws.erase(bl);
        // arrow moves down 1 height
        if (arws.find(bl - 1) == arws.end()) arws[bl - 1] = 0;
        ++arws[bl - 1];
    }
    cout << res << endl;
    return 0;
}
