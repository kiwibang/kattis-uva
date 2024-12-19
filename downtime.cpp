#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, res = 0; // res = 1 to account for the first server needed
    cin >> n >> k;
    vector<int> rqs(n);
    for (int i = 0; i < n; ++i) cin >> rqs[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        while (!pq.empty() && pq.top() <= rqs[i]) pq.pop();
        pq.push(rqs[i] + 1000);
        res = max(res, (int) pq.size());
    }
    cout << (int) ceil((float) res / k) << endl;
    return 0;
}
