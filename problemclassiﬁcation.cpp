#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string s, cat, wd;
    unordered_map<string, int> f;
    unordered_map<string, vector<string>> wtocat;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        istringstream iss(s);
        iss >> cat;
        f[cat] = 0;
        int w;
        iss >> w;
        for (int j = 0; j < w; ++j) {
            iss >> wd;
            if (wtocat.find(wd) == wtocat.end()) wtocat[wd] = vector<string>();
            wtocat[wd].push_back(cat); 
        }
    }
    // count the words that fall in each category
    while (true) {
        getline(cin, s);
        if (cin.eof()) break;
        istringstream iss2(s);
        while (iss2 >> wd) {
            if (wtocat.find(wd) != wtocat.end()) {
                for (string& cat : wtocat[wd]) {
                    ++f[cat];
                }
            } 
        }
    }
    vector<pair<string, int>> res;
    for (auto& p : f) {
        res.push_back(p);
    }
    sort(res.begin(), res.end(), cmp);
    int mx = -1;
    for (auto& p : res) {
        if (mx == -1) {
            mx = p.second;
            cout << p.first << endl;
            continue;
        } else if (mx == p.second) {
            cout << p.first << endl;
        } else {
            break;
        }
    }
    return 0;
}

