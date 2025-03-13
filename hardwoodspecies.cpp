#include <bits/stdc++.h>
using namespace std;

int main() {
    string tree;
    map<string, double> mp;
    double total = 0;
    while (true) {
        getline(cin, tree);
        if (cin.eof()) break;
        if (mp.find(tree) == mp.end()) mp[tree] = 0;
        ++mp[tree];
        ++total;
    }
    for (auto& p : mp) {
        cout << p.first << " " << p.second * 100 / total << endl;
    }
    return 0;
}

