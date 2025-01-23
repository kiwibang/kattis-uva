#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> inside;
    string cmd, name;
    for (int i = 0; i < n; ++i) {
        cin >> cmd >> name;
        if (cmd == "entry") {
            cout << name << " entered";
            if (inside.find(name) != inside.end()) { // anomaly
                cout << " (ANOMALY)" << endl;       
            } else {
                cout << endl;
            }
            inside.insert(name);
        } else {
            cout << name << " exited";
            if (inside.find(name) == inside.end()) { // anomaly
                cout << " (ANOMALY)" << endl;        
            } else {
                cout << endl;
            }
            inside.erase(name);
        }
    }
    return 0;
}

