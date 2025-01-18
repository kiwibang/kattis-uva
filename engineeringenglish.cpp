#include <bits/stdc++.h>
using namespace std;

string get_lower(string& s) {
    string res = "";
    for (char c : s) res.push_back(tolower(c));
    return res;
}

int main() {
    string curr, temp;
    unordered_set<string> seen;
    while (true) {
        getline(cin, curr);
        if (cin.eof()) return 0;
        istringstream iss(curr);
        vector<string> words;
        while (iss >> temp) {
            words.push_back(temp);
        }
        for (int i = 0; i < words.size(); ++i) {
            temp = get_lower(words[i]);
            if (seen.find(temp) != seen.end()) {
                cout << ".";
            } else {
                cout << words[i];
            }
            if (i < words.size() - 1) cout << " ";
            seen.insert(temp);
        }
        cout << endl;
    }
    return 0;
}

