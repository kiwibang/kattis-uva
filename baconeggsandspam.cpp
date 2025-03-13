#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        cin.ignore();
        map<string, set<string>> f2n;
        for (int i = 0; i < n; ++i) {
            string l, t, name;
            getline(cin, l);
            istringstream iss(l);
            iss >> name;
            while (iss >> t) {
                if (f2n.find(t) == f2n.end()) f2n[t] = set<string>();
                f2n[t].insert(name);
            }
        }
        for (auto& p : f2n) {
            cout << p.first << " ";
            for (string nm : p.second) {
                cout << nm << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

