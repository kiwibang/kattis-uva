#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, x;
    getline(cin, s);
    while (getline(cin, s)) {
        if (s == "___________") {
            break;
        }
        x = "";
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i] == ' ') {
                x += '0';
            } 
            if (s[i] == 'o') {
                x += '1';
            }
        }
        cout << (char) stoi(x, nullptr, 2);
    }
    return 0;
}
