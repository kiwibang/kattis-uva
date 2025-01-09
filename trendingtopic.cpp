#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

void prs(map<string, int>& f, int cnt) {
    map<int, vector<string> > inv;
    for (auto fq : f) {
        inv[fq.second].push_back(fq.first);
    }
    auto it = prev(inv.end());
    vector<pair<string, int> > res;
    while (res.size() < cnt) {
        for (auto j : it->second) {
            res.push_back({j, it->first});
        }
        if (it == inv.begin()) break;
        it--;
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res) {
        cout << i.first << " " << i.second << endl;
    }    
}

int main() {
    string curr;
    queue<vector<string> > texts;
    map<string, int> f;
    vector<string> words;
    while (cin >> curr) {
        if (curr == "<text>") {
            words = vector<string>();
        } else if (curr == "</text>") {
            if (texts.size() == 7) {
                vector<string> rem = texts.front();
                for (string& s : rem) {
                    --f[s];
                    if (f[s] == 0) f.erase(s);
                }
                texts.pop();
            } 
            texts.push(words);
        } else if (curr == "<top") {
            int cnt;
            cin >> cnt;
            cin >> curr;
            cout << "<top " << cnt << ">" << endl;
            prs(f, cnt);
            cout << "</top>" << endl;
        } else {
            if (curr.size() < 4) continue;
            if (f.find(curr) == f.end()) f[curr] = 0;
            ++f[curr];
            words.push_back(curr);
        } 
    } 
    return 0;
}

