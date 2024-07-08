#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    cout << str[0];
    bool prevhy = false;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == '-') {
            prevhy = true;
            continue;
        }
        if (prevhy) {
            cout << str[i];
            prevhy = false;
            continue;
        }
        prevhy = false;
    }
    cout << endl;
    return 0;
}
