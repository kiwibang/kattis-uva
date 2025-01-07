#include <bits/stdc++.h>
using namespace std;

char getclose(char c) {
    return c == '(' ? ')' : c == '[' ? ']' : c == '{' ? '}' : '*';
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    string l;
    getline(cin, l);
    stack<char> s;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (l[i] == ' ') continue;
        if (l[i] == '(' || l[i] == '[' || l[i] == '{') {
            s.push(l[i]);
            continue;
        }
        if (s.empty() || getclose(s.top()) != l[i]) {
            cout << l[i] << " " << i << endl;
            ok = false;
            break;
        } else {
            s.pop();
        } 
    }
    if (ok) cout << "ok so far" << endl;
    return 0;
}

