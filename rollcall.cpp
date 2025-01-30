#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, string>& a, pair<string, string>& b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
    vector<pair<string, string>> names;
    unordered_map<string, int> fns;
    string fn, ln;
    while (true) {
       cin >> fn >> ln;
       if (cin.eof()) break;
       names.push_back({fn, ln});
       if (fns.find(fn) == fns.end()) fns[fn] = 0;
       ++fns[fn];
    }
    sort(names.begin(), names.end(), cmp);
    for (auto& p : names) {
        cout << p.first;
        if (fns[p.first] > 1) {
            cout << " " << p.second;
        }
        cout << endl;
    }
    return 0;
}

