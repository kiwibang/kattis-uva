#include <bits/stdc++.h>
using namespace std;

string process(string& st) {
    string res = "";
    for (char c : st) {
        if (isalpha(c)) {
            res += tolower(c);
        } else if (c == '-') {
            res += ' ';
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    unordered_set<string> s;
    while (n--) {
        string curr;
        getline(cin, curr);
        s.insert(process(curr));
    }
    cout << s.size() << endl;
    return 0;
}

