#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    string sch, team;
    vector<string> winners;
    unordered_set<string> schools;
    for (int i = 0; i < n; ++i) {
        cin >> sch >> team;
        if (schools.find(sch) != schools.end()) { // added already 
            continue;
        } else {
            winners.push_back(sch + " " + team);
            schools.insert(sch);
            if (winners.size() == 12) break;
        }
    }
    for (string winner : winners) cout << winner << endl;
    return 0;
}

