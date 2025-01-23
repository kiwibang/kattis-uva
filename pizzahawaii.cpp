#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, string>& a, pair<string, string>& b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        if (tc > 0) cout << endl;
        int n;
        cin >> n;
        unordered_map<string, unordered_set<string>> foreigni, locali;
        // loop over the pizzas
        for (int i = 0; i < n; ++i) {
            string currpizza, ingredient;
            cin >> currpizza;
            // read in the foreign ingredients
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> ingredient;
                if (foreigni.find(ingredient) == foreigni.end()) foreigni[ingredient] = unordered_set<string>();
                foreigni[ingredient].insert(currpizza);
            }
            // read in the local ingredients
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> ingredient;
                if (locali.find(ingredient) == locali.end()) locali[ingredient] = unordered_set<string>();
                locali[ingredient].insert(currpizza);
            }
        }        
        // then get all the pairs of words that appear on the same set of pizzas
        vector<pair<string, string>> res;
        for (auto& w1 : foreigni) {
            string a = w1.first;
            unordered_set<string> s1 = w1.second;
            for (auto& w2 : locali) {
                string b = w2.first;
                unordered_set<string> s2 = w2.second;
                if (s1 == s2) res.push_back({a, b});
            }
        }
        sort(res.begin(), res.end(), cmp);
        for (auto& p : res) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
    return 0;
}

