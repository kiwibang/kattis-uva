#include <bits/stdc++.h>
using namespace std;

int getd(string typed, string suggested, map<char, pair<int, int> >& mp) {
    int res = 0;
    for (int i = 0; i < typed.size(); ++i) {
        res += (abs(mp[typed[i]].first - mp[suggested[i]].first) + abs(mp[typed[i]].second - mp[suggested[i]].second));
    }
    return res;
}

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    // set up the maps
    vector<string> keyboard;
    keyboard.push_back("qwertyuiop");
    keyboard.push_back("asdfghjkl");
    keyboard.push_back("zxcvbnm");
    // map each character to a coordinate
    map<char, pair<int, int> > chartocoord;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < keyboard[i].size(); ++j) {
            chartocoord[keyboard[i][j]] = pair<int, int>(i, j);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        int l;
        cin >> s >> l;
        // list of suggested words with their distance to the typed word
        vector<pair<string, int> > words;
        for (int i = 0; i < l; ++i) {
            string temp;
            cin >> temp;
            int diff = getd(s, temp, chartocoord);
            words.push_back(pair<string, int>(temp, diff));
        }
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < l; ++i) {
            cout << words[i].first << " " << words[i].second << endl;
        }
    }
    return 0;
}
