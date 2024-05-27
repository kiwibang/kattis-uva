#include <bits/stdc++.h>
using namespace std;

int main() {
    // get inputs
    string line;
    set<string> dict;
    while (cin >> line && line != "#") {
        dict.insert(line);
    }
    cin.ignore();
    string text;
    getline(cin, text);
    // process inputs
    // try all values of k
    int maxMatches = -1;
    int maxK = -1;
    string res;
    for (int k = 0; k < 26; ++k) {
        // translate the string
        string converted = "";
        for (int i = 0; i < text.length(); ++i) {
            char c = text[i];
            int id = c == ' ' ? 0 : (c - 'A' + 1);
            char toinsert = id < k ? 26 - k + id + 'A' : id > k ? id - k + 'A' - 1 : ' ';
            converted.push_back(toinsert);
        }   
        // count number of words that match
        istringstream iss(converted);
        string currWord;
        int matches = 0;
        while (iss >> currWord) {
            if (dict.find(currWord) != dict.end()) {
                ++matches;
            }
        }
        if (matches > maxMatches) {
            maxMatches = matches;
            maxK = k;
            res = converted;
        }
    }
    istringstream is(res);
    string cword;
    vector<string> words;
    int linelength = 0;
    while (is >> cword) {
        words.push_back(cword);
    }
    string s = "";
    for (int i = 0; i < words.size(); ++i) {
        string temp;
        if (i == 0) {
            temp = words[i];
        } else {
            temp = s + " " + words[i];
        }
        if (temp.size() > 60) {
            cout << s << endl;
            s = words[i];
        } else {
            s = temp;
            if (i == words.size() - 1 && s.size() != 0) {
                cout << s;
            }
        }
    }
    cout << endl;
    return 0;
}
