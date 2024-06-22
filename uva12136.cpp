#include <bits/stdc++.h>
using namespace std;

int getm(string time) {
    return stoi(time.substr(0, time.find(':'))) * 60 + stoi(time.substr(time.find(':') + 1, time.size()));
}

pair<int, int> getid(string s, string e) {
    return pair<int, int>(getm(s), getm(e));
}

bool overlap(pair<int, int> i1, pair<int, int> i2) {
    return i2.first <= i1.second && i1.first <= i2.second;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string startw, endw, startm, endm;
        cin >> startw >> endw >> startm >> endm;
        pair<int, int> i1 = getid(startw, endw);
        pair<int, int> i2 = getid(startm, endm);
        cout << "Case " << i << ": ";
        if (overlap(i1, i2)) {
            cout << "Mrs Meeting" << endl;
        } else {
            cout << "Hits Meeting" << endl;
        }
    }
    return 0;
}
