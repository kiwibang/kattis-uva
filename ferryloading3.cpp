#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        if (i > 0) cout << endl;
        int n, t, m, at;
        cin >> n >> t >> m;
        queue<pair<int, int> > left, right;
        string dir;
        for (int j = 0; j < m; ++j) {
            cin >> at >> dir;
            if (dir == "left") {
                left.push(pair<int, int>(at, j));
            } else if (dir == "right") {
                right.push(pair<int, int>(at, j));
            }
        }
        vector<pair<int, int> > res;
        int currtime = 0;
        bool bank = false;
        while (!left.empty() || !right.empty()) {
            if (!bank) { // boat at left bank
                // then load the cars
                int load = 0;
                while (!left.empty() && left.front().first <= currtime && load < n) {
                    res.push_back(pair<int, int>(currtime + t, left.front().second));
                    left.pop();
                    ++load;
                }
                if (load) {
                    bank = !bank;
                    currtime += t;
                } else if (!right.empty() && right.front().first <= currtime) {
                    bank = !bank;
                    currtime += t;
                } else if (!right.empty() && !left.empty() && right.front().first < left.front().first) {
                    bank = !bank;
                    currtime = right.front().first + t;
                } else if (!left.empty()) {
                    currtime = left.front().first;
                } else {
                    bank = !bank;
                    currtime = right.front().first + t;
                }
            } else { // boat at right bank
                // then load the cars
                int load = 0;
                while (!right.empty() && right.front().first <= currtime && load < n) {
                    res.push_back(pair<int, int>(currtime + t, right.front().second));
                    right.pop();
                    ++load;
                }
                if (load) {
                    bank = !bank;
                    currtime += t;
                } else if (!left.empty() && left.front().first <= currtime) {
                    bank = !bank;
                    currtime += t;
                } else if (!left.empty() && !right.empty() && left.front().first < right.front().first) {
                    bank = !bank;
                    currtime = left.front().first + t;
                } else if (!right.empty()) {
                    currtime = right.front().first;
                } else {
                    bank = !bank;
                    currtime = left.front().first + t;
                }
            }
        }
        sort(res.begin(), res.end(), cmp);
        for (int j = 0; j < m; ++j) {
            cout << res[j].first << endl;
        }
    }
    return 0;
}

