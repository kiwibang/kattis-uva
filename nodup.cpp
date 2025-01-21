#include <bits/stdc++.h>
using namespace std;

int main() {
    string l, t;
    getline(cin, l);
    istringstream iss(l);
    unordered_set<string> s;
    while (iss >> t) {
        if (s.find(t) != s.end()) {
            cout << "no" << endl;
            return 0;
        }
        s.insert(t);
    }
    cout << "yes" << endl;
    return 0;
}

