#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<double>& a, vector<double>& b) {
    return a[0] < b[0];
}

int main() {
    double res = 0.0;
    int n, m, p;
    cin >> n >> m >> p;
    map<int, pair<double, double> > judges, tarrepos, featherstores;
    for (int i = 0; i < n; ++i) {
        judges[i] = pair<double, double>(-1.0, -1.0);
        cin >> judges[i].first >> judges[i].second;
    }
    for (int i = 0; i < m; ++i) {
        tarrepos[i] = pair<double, double>(-1.0, -1.0);
        cin >> tarrepos[i].first >> tarrepos[i].second;
    }
    for (int i = 0; i < p; ++i) {
        featherstores[i] = pair<double, double>(-1.0, -1.0);
        cin >> featherstores[i].first >> featherstores[i].second;
    }
    vector<vector<double> > comb1, comb2;
    for (int i = 0; i < n; ++i) {
        pair<double, double> jc = judges[i];
        pair<double, double> tc;
        for (int j = 0; j < m; ++j) {
            tc = tarrepos[j];
            comb1.push_back({sqrt(pow(jc.first - tc.first, 2) + pow(jc.second - tc.second, 2)), (double) i, (double) j});
        }
    }
    for (int i = 0; i < n; ++i) {
        pair<double, double> jc = judges[i];
        pair<double, double> fc;
        for (int j = 0; j < p; ++j) {
            fc = featherstores[j];
            comb2.push_back({sqrt(pow(jc.first - fc.first, 2) + pow(jc.second - fc.second, 2)), (double) i, (double) j});
        }
    }
    sort(comb1.begin(), comb1.end(), cmp);
    sort(comb2.begin(), comb2.end(), cmp);
    vector<bool> addedj(n, false), addedt(m, false), addedf(p, false);
    for (int i = 0; i < comb1.size(); ++i) {
        // only assign if the current judge and the current tar repo is unassigned
        if (!addedj[comb1[i][1]] && !addedt[comb1[i][2]]) {
            res += comb1[i][0];
            addedj[comb1[i][1]] = true;
            addedt[comb1[i][2]] = true;
        } 
    } 
    addedj = vector<bool>(n, false);
    for (int i = 0; i < comb2.size(); ++i) {
        // only assign if the current judge and the current tar repo is unassigned
        if (!addedj[comb2[i][1]] && !addedf[comb2[i][2]]) {
            res += comb2[i][0];
            addedj[comb2[i][1]] = true;
            addedf[comb2[i][2]] = true;
        } 
    } 
    cout << setprecision(12) << res << endl;
    return 0;
}
