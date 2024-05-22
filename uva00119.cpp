#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cnt = 1;
    // loop over the testcases
    while (cin >> n) {
        map<string, long> moneyMap;
        vector<string> names;
        for (int i = 0; i < n; ++i) {
            string name;
            cin >> name;
            names.push_back(name);
            moneyMap[name] = 0;
        }
        for (int i = 0; i < n; ++i) {
            string giver;
            int amount, peopleCount; 
            cin >> giver >> amount >> peopleCount;
            if (peopleCount == 0) {
                continue;
            }
            int amountPerPerson = amount / peopleCount;
            moneyMap[giver] -= amountPerPerson * peopleCount;
            for (int j = 0; j < peopleCount; ++j) {
                string rec;
                cin >> rec;
                moneyMap[rec] += amountPerPerson;
            }
        }
        if (cnt++ > 1) {
            cout << endl;
        }
        for (int i = 0; i < n; ++i) {
            cout << names[i] << " " << moneyMap[names[i]] << endl;
        }
    }
    return 0;
}
