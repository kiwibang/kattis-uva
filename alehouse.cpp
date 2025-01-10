#include <bits/stdc++.h>
using namespace std;

struct cmp1 {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

// find the top k time slices
int main() {
    int n, k, a, b, res = 0;
    cin >> n >> k;
    vector<pair<int, int> > intervals;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp1> pq;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        intervals.push_back(pair<int, int>(a, b));
    }
    // sort by start point
    sort(intervals.begin(), intervals.end(), cmp2);
    // then process using priority queue ordered by 
    for (int i = 0; i < n; ++i) {
        // remove expired intervals
        while (!pq.empty() && pq.top().second < intervals[i].first - k) {
            pq.pop();
        }
        pq.push(intervals[i]);
        res = max(res, (int) pq.size());
    }
    cout << res << endl;
    return 0;
}

