#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int w = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'W') {
            ++w;
        } else {
            ++b;
        }
    }
    if (w == b) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
