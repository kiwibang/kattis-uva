// i gave up. adapted from: https://morris821028.github.io/2014/06/10/oj/uva/uva-11638/
#include <bits/stdc++.h>
using namespace std;

bool check_trigger(int threshold, int temperature, bool is_high_trigger) {
    if (is_high_trigger) {
        return temperature > threshold;
    } else {
        return temperature < threshold;
    }
}

int main() {
    // number of testcases
    int t;
    cin >> t;
    // loop over testcases
    for (int tc = 1; tc <= t; ++tc) {
        // measurment interval
        int m;
        cin >> m;
        // startup delay
        int s;
        cin >> s;
        // threshold temps
        vector<int> temps(4, 0);
        for (int i = 0; i < 4; ++i) {
            cin >> temps[i];
        }
        // modes
        int c;
        cin >> c;
        // process modes
        vector<int> enabled(4, 0);
        vector<int> ishigh(4, 0);
        for (int i = 0; i < 4; ++i) {
            enabled[i] = ((c >> i) & 1);
        }
        for (int i = 4; i < 8; ++i) {
            ishigh[i - 4] = ((c >> i) & 1);
        }
        int k;
        cin >> k;
        int hasrung[4] = {};
        // then simulate 
        int ctime = 0, starttime, endtime;
        for (int l = 0; l < k; ++l) {
            int dur, temp;
            cin >> dur >> temp;
            starttime = ctime;
            endtime = ctime + dur;
            if (endtime < s) {

            } else {
                int last_read = endtime / m * m;
                if(starttime <= last_read && last_read <= endtime && last_read >= s) {
                    for(int i = 0; i < 4; i++) {
                        if(ishigh[i] == 0) {
                            hasrung[i] |= (temp < temps[i]) & enabled[i];
                        } else {
                            hasrung[i] |= (temp > temps[i]) & enabled[i];
                        }
                    }
                }
            }
            ctime = endtime;
        }
        cout << "Case " << tc << ":";
        for (int i = 0; i < 4; ++i) {
            if (hasrung[i]) {
                cout << " yes";
            } else {
                cout << " no";
            }
        }
        cout << endl;
    }
    return 0;
}
