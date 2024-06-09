#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int>& times, int t) {
    bool res = false;
    int co = 0, hits = 0;
    for (int i = 0; i < times.size(); ++i) {
        if (t % (times[i] * 2) < (times[i] - 5)) {
            ++hits;
        }
        if (t > times[i]) {
            ++co;
        }
    }
    if (hits == times.size() && co > 0) {
        res = true;
    }
    return res;
}

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3 && (a || b || c)) {
        vector<int> times;
        times.push_back(a);
        times.push_back(b);
        while (c != 0) {
            times.push_back(c);
            scanf("%d", &c);
        }
        bool found = false;
        int timegreen = 0;
        for (int i = 1; i <= 18000 && !found; ++i) {
            if (ok(times, i)) {
                found = true;
                timegreen = i;
            }
        }
        if (found) {
            int h = timegreen / 3600;
            timegreen %= 3600;
            int m = timegreen / 60;
            timegreen %= 60;
            int s = timegreen;
            printf("%02d:%02d:%02d\n", h, m, s);
        } else {
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }
    }
    return 0;
}
