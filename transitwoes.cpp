#include <bits/stdc++.h>
using namespace std;

int main() {
    // get the inputs
    int s, t, n;
    cin >> s >> t >> n;
    // walking times
    vector<int> d(n + 1, 0);
    // bus times
    vector<int> b(n, 0);
    // interval times
    vector<int> c(n, 0);
    for (int i = 0; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    // simulate the routes
    int currtime = s;
    // walk for d0 time to the first bus stop
    currtime += d[0];
    // take the buses -- remember i + 1 for walking times
    for (int i = 0; i < n; ++i) {
        // you are at the ith bus stop - compute the wait time
        int waittime = c[i] % 5 == 0 ? 0 : c[i] - (currtime % c[i]);
        currtime += waittime;
        // take the current bus
        int bustime = b[i];
        currtime += bustime;
        // then walk to the next stop
        int walktime = d[i + 1];
        currtime += walktime;
        // cout << "bus stop: " << i + 1 << " | wait time: " << waittime << " | bustime: " << bustime << " | walktime: " << walktime << endl;
    }
    // cout << currtime << " " << t << endl;
    // case where can make it
    if (currtime <= t) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
