#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int p, h, o;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> p >> h >> o;
        if (o - p >= h) {
            cout << "Props win!" << endl;
        } else {
            cout << "Hunters win!" << endl;
        }
    }
    return 0;
}
