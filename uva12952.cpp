#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if (cin.eof()) {
            return 0;
        }
        if (a == b) {
            cout << a << endl;
        } else {
            cout << max(a, b) << endl;
        }
    }
    return 0;
}
