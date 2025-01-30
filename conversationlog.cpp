#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string curr;
    unordered_map<string, vector<string>> ntos;
    while (n--) {
        getline(cin, curr);
        string name, word, mxword;
        unordered_map<string, int> fq;
        istringstream iss(curr);
        iss >> name;
        if (ntos.find(name) == ntos.end()) ntos[name] = vector<string>();
        while (iss >> word) {
            ntos[name].push_back(word);
        }
    }
    unordered_map<string, int> f;
    unordered_map<string, int> tf;
    for (auto& words : ntos) {
        unordered_set<string> added;
        for (string w : words.second) {
            if (added.find(w) == added.end()) {
                if (f.find(w) == f.end()) f[w] = 0;
                ++f[w];
                added.insert(w);
            }
            if (tf.find(w) == tf.end()) tf[w] = 0;
            ++tf[w];
        }
    }
    vector<pair<string, int>> res;
    for (auto& p : f) {
        string a = p.first;
        int cnt = p.second;
        if (cnt == ntos.size()) {
            res.push_back({a, tf[a]});
        }
    }
    if (res.size() == 0) {
        cout << "ALL CLEAR" << endl;
        return 0;
    }
    sort(res.begin(), res.end(), cmp);
    for (auto& p : res) {
        cout << p.first << endl;
    }
    return 0;
}

