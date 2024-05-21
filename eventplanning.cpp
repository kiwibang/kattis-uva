#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, h, w;
    cin >> n >> b >> h >> w;
    int minCost = (b << 1);
    for (int i = 0; i < h; ++i) {
        // get the price
        int p;
        cin >> p;
        // get the capacity of the hotel
        int cap;
        bool ok = false;
        for (int j = 0; j < w; ++j) {
            cin >> cap;
            // if can accomodate, set flag to true
            if (cap >= n) {
                ok = true;
            }
        }
        // update the min if there is a day where all participants can be 
        // accomodated for at least one day
        if (ok) {
            minCost = min(minCost, n * p);
        }
    }
    if (minCost > b) {
        cout << "stay home" << endl;
    } else {
        cout << minCost << endl;
    }
    return 0;
}
