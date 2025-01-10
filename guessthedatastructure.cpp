#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cmd, x;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        vector<bool> res(3, true);
        for (int i = 0; i < n; ++i) {
            cin >> cmd;
            if (cmd == 1) {
                cin >> x;
                s.push(x);
                q.push(x);
                pq.push(x);
            } else if (cmd == 2) {
                cin >> x;
                if (s.empty()) {
                    res[0] = false, res[1] = false, res[2] = false;
                    continue;
                }
                int sr = s.top(), qr = q.front(), pqr = pq.top();
                s.pop();
                q.pop();
                pq.pop();
                if (sr != x) res[0] = false;
                if (qr != x) res[1] = false;
                if (pqr != x) res[2] = false;
            }
        }
        int mc = 0;
        for (int i = 0; i < 3; ++i) if (res[i]) ++mc;
        if (mc == 0) {
            cout << "impossible" << endl;
        } else if (mc == 1) {
            if (res[0]) {
                cout << "stack" << endl;
            } else if (res[1]) {
                cout << "queue" << endl;
            } else if (res[2]) {
                cout << "priority queue" << endl;
            }
        } else {
            cout << "not sure" << endl;
        }
    }
    return 0;
}

