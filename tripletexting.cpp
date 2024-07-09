#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    cin >> line;
    int n = line.size();
    string w1 = line.substr(0, n / 3), w2 = line.substr(n / 3, n / 3), w3 = line.substr(2 * n / 3, n / 3);
    if (w1 == w2) {
        cout << w1 << endl;
    } else if (w1 == w3) {
        cout << w1 << endl;
    } else if (w2 == w3) {
        cout << w2 << endl;
    }
    return 0;
}
