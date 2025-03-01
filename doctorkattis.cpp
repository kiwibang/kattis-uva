#include <bits/stdc++.h>
using namespace std;

struct cat {
    string name;
    int il;
    int at;
    cat() {
        name = "";
        il = -1;
        at = -1;
    }
    cat(string nm, int i, int a) {
        name = nm;
        il = i;
        at = a;
    }   
};

struct cmp {
    bool operator()(const cat& a, const cat& b) const {
        return a.il != b.il ? a.il > b.il : a.at < b.at;
    }
};

int main() {
    int n;
    cin >> n;
    unordered_map<string, cat> mp;
    set<cat, cmp> s;
    int currat = 0;
    while (true) {
        int cmd;
        cin >> cmd;
        if (cin.eof()) break;
        if (cmd == 0) {
            string name; 
            int il;
            cin >> name >> il;
            cat ccat = cat(name, il, currat++);
            mp[name] = ccat;
            s.insert(ccat);
        } else if (cmd == 1) {
            string name;
            int delta;
            cin >> name >> delta;
            cat ccat = mp[name];
            s.erase(ccat);
            ccat.il += delta;
            mp[name] = ccat;
            s.insert(ccat);
        } else if (cmd == 2) {
            string name;
            cin >> name;
            s.erase(mp[name]);
            mp.erase(name);
        } else if (cmd == 3) {
            if (mp.size()) {
                cout << (*s.begin()).name << endl;
            } else {
                cout << "The clinic is empty" << endl;
            }
        }
    }
    return 0;
}

