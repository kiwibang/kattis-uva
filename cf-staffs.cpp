#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        long long total = 0, currxcount = 0;
        long long cx = 1, cy = 1;
        vector<pair<long long, long long>> pts;
        while (true) {
            ++currxcount;
            pts.push_back({cx, cy});
            long long temp = ((currxcount) * (currxcount - 1) >> 1);
            if (temp + total > k) {
                pts.pop_back();
                --currxcount;
                total += ((currxcount) * (currxcount - 1) >> 1);
                currxcount = 0;
                cx = cy + 1, cy = cx;
                continue;
            } else if (temp + total == k) {
                break;
            }
            ++cy;
        }
        cout << pts.size() << endl;
        for (pair<long long, long long>& p : pts) {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}

