#include <bits/stdc++.h>
using namespace std;

int tomins(string time, string tod) {
    // get hr and mins
    int hr = stoi(time.substr(0, time.find(':')));
    int min = stoi(time.substr(time.find(':') + 1, time.size()));
    int res;
    if (tod == "a.m.") {
        if (hr == 12) {
            hr = 0;
        }
        res = hr * 60 + min;
    } else {
        if (hr == 12) {
            hr = 0;
        }
        res = 12 * 60 + hr * 60 + min;
    }
    return res;
}

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    int tc = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<pair<string, int> > times;
        for (int i = 0; i < n; ++i) {
            string time, tod;
            cin >> time >> tod;
            times.push_back(pair<string, int>(time + " " + tod, tomins(time, tod)));
        }
        sort(times.begin(), times.end(), cmp);
        if (tc++ > 1) {
            cout << endl;
        }
        for (int i = 0; i < times.size(); ++i) {
            cout << times[i].first << endl;
        }
    }
    return 0;
}
