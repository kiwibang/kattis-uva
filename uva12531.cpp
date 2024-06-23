#include <bits/stdc++.h>
using namespace std;

int main() {
    // read the testcases, and answer accordingly
    while (true) {
        int angle;
        cin >> angle;
        if (cin.eof()) {
            break;
        }
        if (angle % 6 == 0) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
