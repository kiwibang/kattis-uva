#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> dirtyPushes(366, false);
    for (int i = 0; i < n; ++i) {
        // get the current dirty push
        int currDay;
        cin >> currDay;
        dirtyPushes[currDay] = true;
    }
    int res = 0;
    int currDirtiness = 0;
    int numDirty = 0;
    for (int j = 1; j <= 365; ++j) {
        currDirtiness += numDirty;
        if (currDirtiness >= 20) {
            currDirtiness = 0;
            numDirty = 0;
            ++res;
        }
        if (dirtyPushes[j]) {
            ++numDirty;
        }
    }
    if (numDirty > 0) {
        ++res;
    }
    cout << res << endl;
    return 0;
}
