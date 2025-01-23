#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, m, sc;
    cin >> n >> p >> m;
    string name;
    unordered_map<string, int> scores;
    // read in the name
    for (int i = 0; i < n; ++i) {
        cin >> name;
        scores[name] = 0;
    }
    // calculate the scores
    vector<string> winners;
    unordered_set<string> added;
    for (int i = 0; i < m; ++i) {
        cin >> name >> sc;
        scores[name] += sc;
        if (scores[name] >= p && added.find(name) == added.end()) {
            winners.push_back(name);
            added.insert(name);
        }
    }
    if (!winners.size()) {
        cout << "No winner!" << endl;
    } else {
        for (string& name : winners) cout << name << " wins!" << endl;
    }
    return 0;
}

