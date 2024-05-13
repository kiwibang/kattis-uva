#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int sl = s.length();
        if (s == "1" || s == "4" || s == "78") { // positive
            cout << "+" << endl;
        } else if (s[sl - 2] == '3' && s[sl - 1] == '5') { // negative
            cout << "-" << endl;
        } else if (s[0] == '9' && s[sl - 1] == '4') { // failed
            cout << "*" << endl;
        } else if (s[0] == '1' && s[1] == '9' && s[2] == '0') { // not completed
            cout << "?" << endl;
        } else {
            cout << "+" << endl;
        }
    }
    return 0;
}
