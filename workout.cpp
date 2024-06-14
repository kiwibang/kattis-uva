#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ju, jr, jt;
    for (int i = 0; i < 10; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        ju.push_back(t1);
        jr.push_back(t2);
        jt.push_back(t1 + t2);
    }
    vector<int> usages, recovery, time, total;
    for (int i = 0; i < 10; ++i) {
        int u, r, t;
        cin >> u >> r >> t;
        usages.push_back(u);
        recovery.push_back(r);
        time.push_back(t);
        total.push_back(u + r);
    }
    // note invariant: time[i] represents the time that the (i + 1)th user starts their next set
    int currtime = 0;
    // do 3 sets
    for (int sets = 0; sets < 3; ++sets) {
        // do all of the 10 machines
        for (int i = 0; i < 10; ++i) {
            if (currtime >= time[i] && (currtime - time[i]) % total[i] <= usages[i]) {
                currtime += usages[i] - (currtime - time[i]) % total[i];
            }
            if (currtime >= time[i]) {
                time[i] = currtime - (currtime - time[i]) % total[i];
            }
            if (time[i] + total[i] < currtime + ju[i]) {
                time[i] = currtime + ju[i];
            } else if (currtime < time[i] && currtime + ju[i] > time[i]) {
                time[i] = currtime + ju[i];
            }
            currtime += jt[i];
        }
    }
    cout << currtime - jr[9] << endl;
    return 0;
}
