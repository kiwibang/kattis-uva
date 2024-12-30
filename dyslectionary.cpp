#include <bits/stdc++.h>
using namespace std;

void hp(vector<string>& w) {
    int mx = 0;
    for (int i = 0; i < w.size(); ++i) {
        mx = max(mx, (int) w[i].size());
        reverse(w[i].begin(), w[i].end());
    }
    sort(w.begin(), w.end());
    for (auto& wr : w) reverse(wr.begin(), wr.end());
    for (auto& wr : w) {
        string bl;
        bl.resize(mx - wr.length(), ' ');
        bl += wr;
        swap(wr, bl);
    }
    for (auto wr : w) cout << wr << endl;
}

int main() {
    int id = 0;
    vector<string> words;
    string curr;
    while (getline(cin, curr)) {
        if (curr == "") {
            hp(words);
            cout << endl;
            words.clear();
            continue;
        }
        words.push_back(curr);
    }
    hp(words);
    return 0;
}

