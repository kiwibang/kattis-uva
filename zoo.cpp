#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1, tc = 1;
    while (true) {
        cin >> n;
        if (!n) break;
        map<string, int> f;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string s, curr;
            vector<string> desc;
            getline(cin, s);
            istringstream iss(s);
            while (iss >> curr) {
                desc.push_back(curr);
            }
            string name = desc[desc.size() - 1];
            for (int j = 0; j < name.size(); ++j) {
                if (isupper(name[j])) {
                    name[j] = tolower(name[j]);
                }
            }
            if (f.find(name) == f.end()) f[name] = 0;
            ++f[name];
        }
        cout << "List " << tc++ << ":" << endl;
        for (auto& p : f) cout << p.first << " | " << p.second << endl;
    }
    return 0;
}

