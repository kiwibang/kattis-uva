#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int> > s; 
vector<int> mountains;
int res = 0, n, mxidx = -1, mxmountain = -1;

void hp(int idx) {
    int mx = 0;
    while (!s.empty() && mountains[idx] >= s.top().first) {
        mx = max(mx, mountains[idx] - s.top().first + s.top().second);
        s.pop();
    }
    s.push({mountains[idx], mx});
    res = max(res, mx);
}

int main() {
    cin >> n;
    mountains = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> mountains[i];
        if (mountains[i] > mxmountain) {
            mxidx = i;
            mxmountain = mountains[i];
        }
    }
    s.push({mxmountain, 0});
    for (int i = mxidx - 1; i >= 0; --i) {
        hp(i);
    }
    while (!s.empty()) s.pop();
    s.push({mxmountain, 0});
    for (int i = mxidx + 1; i < n; ++i) {
        hp(i);
    }
    cout << res << endl;
    return 0;
}

