#include <bits/stdc++.h>
using namespace std;

int main() {
    // number of testcases
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        if (j > 1) {
            cout << endl;
        }
        // size of database
        int d;
        cin >> d;
        vector<string> names;
        vector<int> lows;
        vector<int> highs;
        // loop over the database
        for (int i = 0; i < d; ++i) {
            string name;
            int low, high;
            cin >> name >> low >> high;
            names.push_back(name);
            lows.push_back(low);
            highs.push_back(high);
        }
        // process queries
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int p;
            cin >> p;
            // loop over the database
            string maker = "";
            bool ok = true;
            for (int i = 0; i < d; ++i) {
                if (maker == "" && lows[i] <= p && p <= highs[i]) {
                    maker = names[i];
                } else if (maker != "" && lows[i] <= p && p <= highs[i]) {
                    ok = false;
                    break;
                }
            }
            if (maker == "" || !ok) {
                cout << "UNDETERMINED" << endl; 
            } else {
                cout << maker << endl;
            }
        }
    }
    return 0;
}
