#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr;
    vector<string> words;
    while (cin >> curr) {
        words.push_back(curr);
    }
    set<string> res;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if (words[i] == words[j]) continue;
            res.insert(words[i] + words[j]);
            res.insert(words[j] + words[i]);
        }
    }
    for (string w : res) {
        cout << w << endl;
    }
    return 0;
}

