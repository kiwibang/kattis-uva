#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    double lower = 0, upper = 0, whitespace = 0, symbols = 0, n = str.size();
    for (char c : str) {
        if (islower(c)) {
            ++lower;
        } else if (isupper(c)) {
            ++upper;
        } else if (c == '_') {
            ++whitespace;
        } else {
            ++symbols;
        }
    }
    cout << whitespace / n << endl; 
    cout << lower / n << endl;
    cout << upper / n << endl;
    cout << symbols / n << endl;
    return 0;
}

