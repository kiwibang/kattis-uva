#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        iss >> a >> b >> c;
        if (a != b && a != c) { // a
            cout << "A" << endl;
        } else if (b != a && b != c) { // b
            cout << "B" << endl;
        } else if (c != a && c != b) { // c
            cout << "C" << endl;
        } else { // no winner
            cout << "*" << endl;
        }
    }
    return 0;
}
