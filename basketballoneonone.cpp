#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    cin >> line;
    int a = 0, b = 0;
    for (int i = 0; i < line.length(); i += 2) {
        // get and update points
        char py = line[i];
        char pt = line[i + 1];
        if (py == 'A') {
            a += (pt - '0');
        } else {
            b += (pt - '0');
        }
        // check for winner
        if (a >= 11 && a - b >= 2) {
            cout << "A" << endl;
            return 0;
        }
        if (b >= 11 && b - a >= 2) {
            cout << "B" << endl;
            return 0;
        }
    }
    return 0;
}
