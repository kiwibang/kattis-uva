#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<float, float>& a, const pair<float, float>& b) {
    return a.first < b.first;
}

int main() {
    int nx, ny;
    float w;
    while (true) {
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0.0) break;
        vector<pair<float, float> > endtoend;
        vector<pair<float, float> > sidetoside;
        float curr;
        for (int i = 0; i < nx; ++i) {
            cin >> curr;
            float first = max(0.0, curr - w / 2.0);
            float second = min(75.0, curr + w / 2.0);
            pair<float, float> cp = pair<float, float>(first, second);
            endtoend.push_back(cp);
        }
        for (int i = 0; i < ny; ++i) {
            cin >> curr;
            float first = max(0.0, curr - w / 2.0);
            float second = min(100.0, curr + w / 2.0);
            pair<float, float> cp = pair<float, float>(first, second);
            sidetoside.push_back(cp);
        }
        sort(endtoend.begin(), endtoend.end(), cmp);
        sort(sidetoside.begin(), sidetoside.end(), cmp);
        float laste = 0.0;
        bool ok = true;
        for (int i = 0; i < nx; ++i) {
            if (laste < endtoend[i].first) {
                ok = false;
                goto nxt;
            }
            laste = endtoend[i].second;
        }
        if (laste < 75.0) {
            ok = false;
            goto nxt;
        }
        laste = 0.0;
        for (int i = 0; i < ny; ++i) {
            if (laste < sidetoside[i].first) {
                ok = false;
                goto nxt;
            }
            laste = sidetoside[i].second;
        }
        if (laste < 100.0) {
            ok = false;
            goto nxt;
        }
nxt:
        if (!ok) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

