#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, string> nametoparty;
    unordered_map<string, int> nametovotes;
    string name, party;
    for (int i = 0; i < n; ++i) {
        getline(cin, name);
        getline(cin, party);
        nametoparty[name] = party;
        nametovotes[name] = 0;
    }
    int m, mx = 0;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
        getline(cin, name);
        ++nametovotes[name];
        mx = max(mx, nametovotes[name]);
    }
    string winner = "";
    bool tie = false;
    for (auto& [name, votes] : nametovotes) {
        if (votes == mx && winner == "") {
            winner = name;
            continue;
        }
        if (votes == mx) {
            tie = true;
        }
    }
    if (tie) {
        cout << "tie" << endl;
        return 0;
    }
    cout << nametoparty[winner] << endl;
    return 0;
}

