#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    bool isFirst = true;
    while (cin.get(c)) {
        // if single quote
        if (c == '"') {
            // if opening single quote
            if (isFirst) {
                // output `` to cout
                cout << "``";
                isFirst = false;
            } else { // if closing
                // output '' to cout
                cout << "''";
                isFirst = true;
            }
        } else { // normal char
            cout << c;
        }
    }
    return 0;
}
