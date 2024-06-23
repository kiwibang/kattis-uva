#include <bits/stdc++.h>
using namespace std;

int getmins(string time) {
    return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0'));
}

int main() {
    // number of testcases
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        // read in number of buses k, and current time
        int k;
        string currtime;
        cin >> k >> currtime;
        int mins = getmins(currtime), res = 9999999;
        // get the buses arrival time, and get the minimum
        for (int i = 0; i < k; ++i) {
            string bustime;
            int dur;
            cin >> bustime >> dur;
            int busmins = getmins(bustime);
            // get waiting time
            int waitingtime = busmins - mins;
            waitingtime = waitingtime >= 0 ? waitingtime : 1440 + waitingtime;
            // compute total time to reach destination assuming this bus was taken, and update result
            res = min(res, waitingtime + dur);
        }
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}
