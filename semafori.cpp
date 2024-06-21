#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int> > havelight(l + 1, pair<int, int>(-1, -1));
    for (int i = 0; i < n; ++i) {
        int d, r, g;
        cin >> d >> r >> g;
        havelight[d].first = r;
        havelight[d].second = g;
    }
    // count the number of seconds waited at each traffic light
    int res = 0;
    for (int i = 1; i <= l; ++i) {
        ++res;
        // if at traffic light
        if (havelight[i].first != -1) {
            // check if light is red
            if (res % (havelight[i].first + havelight[i].second) < havelight[i].first) {
                // if so, count number of seconds waited, and add to res
                res += (havelight[i].first - (res % (havelight[i].first + havelight[i].second)));
            }
        }
    }
    cout << res << endl;
    return 0;
}
