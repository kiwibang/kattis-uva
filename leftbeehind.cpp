#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> x >> y;
        if (x == 0 && y == 0) {
            return 0;
        }
        if (x + y == 13) {
            cout << "Never speak again." << endl;
        } else if (y > x) {
            cout << "Left beehind." << endl;
        } else if (x > y) {
            cout << "To the convention." << endl;
        } else {
            cout << "Undecided." << endl;
        }
    }
    return 0;
}
