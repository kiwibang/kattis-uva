#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i - 1] == 's' && str[i] == 's') {
            cout << "hiss" << endl;
            return 0;
        }
    }
    cout << "no hiss" << endl;
    return 0;
}
