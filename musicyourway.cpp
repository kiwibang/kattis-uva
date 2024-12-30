#include <bits/stdc++.h>
using namespace std;

int main() {
    string rawattrs, attrs, fl;
    map<string, int> attrlist;
    vector<vector<string> > songs;
    getline(cin, rawattrs);
    fl = rawattrs;
    stringstream ss(rawattrs);
    int id = 0;
    while (ss >> attrs) attrlist[attrs] = id++;
    getline(cin, rawattrs);
    int m = stoi(rawattrs);
    for (int i = 0; i < m; ++i) {
        getline(cin, rawattrs);
        stringstream ss(rawattrs);
        vector<string> currsong;
        while (ss >> attrs) currsong.push_back(attrs);
        songs.push_back(currsong);
    }
    getline(cin, rawattrs);
    int n = stoi(rawattrs);
    for (int i = 0; i < n; ++i) {
        getline(cin, rawattrs);
        if (i > 0) cout << endl;
        cout << fl << endl;
        const int idx = attrlist[rawattrs];
        stable_sort(songs.begin(), songs.end(), [&idx](const auto& a, const auto& b) {
                    return a[idx] < b[idx];
                });
        for (vector<string>& s : songs) {
            for (int j = 0; j < s.size(); ++j) {
                cout << s[j];
                if (j < s.size() - 1) cout << " ";
            }
            cout << endl;
        } 
    }
    return 0;
}

