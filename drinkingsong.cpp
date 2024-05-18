#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string line;
    cin >> line;
    while (n > 0) {
        if (n == 1) {
            cout << n << " bottle of " << line << " on the wall, " << n << " bottle of " << line << "." << endl;
            cout << "Take it down, pass it around, no more bottles of " << line << "." << endl;    
        } else {
            cout << n << " bottles of " << line << " on the wall, " << n << " bottles of " << line << "." << endl;
            if (n - 1 == 1) {
                cout << "Take one down, pass it around, " << n - 1 << " bottle of " << line << " on the wall." << endl;
            } else {
                cout << "Take one down, pass it around, " << n - 1 << " bottles of " << line << " on the wall." << endl;
            }
        }
        cout << endl;
        --n;
    }
    return 0;
}
