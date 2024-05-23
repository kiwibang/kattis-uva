#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dirtyPushes;
    for (int i = 0; i < n; ++i) {
        // get the current dirty push
        int currDay;
        cin >> currDay;
        dirtyPushes.push_back(currDay);
    }
    int res = 0;
    int currDirtiness = 0;
    int numDirty = 0;
    int idx = 0;
    for (int j = 1; j <= 365; ++j) {
        currDirtiness += numDirty;
        if (currDirtiness >= 20) {
            currDirtiness = 0;
            numDirty = 0;
            ++res;
        }
        if (dirtyPushes[idx] == j) {
            ++idx;
            ++numDirty;
        }
    }
    if (numDirty > 0) {
        ++res;
    }
    cout << res << endl;
    return 0;
}
