#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string curr;
    cin >> n;
    while (n--) {
        cin >> curr;
        stack<char> s;
        bool ok = true;
        for (int i = 0; i < curr.size(); ++i) {
            // normal ground
            if (curr[i] == '.') continue;
            // treasure
            if (curr[i] == '$' || curr[i] == '|' || curr[i] == '*') {
                s.push(curr[i]);
                continue;
            }
            // trader, jeweler, or banker
            char need = curr[i] == 't' ? '|' : curr[i] == 'j' ? '*' : '$';
            while (!s.empty() && s.top() != need) {
                s.pop();
            }
            if (s.empty()) {
                ok = false;
                break;
            }
            s.pop(); 
        }
        if (!ok || !s.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

