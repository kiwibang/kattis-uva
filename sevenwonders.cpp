#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0, c = 0, g = 0;
    string line;
    cin >> line;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == 'T') {
            ++t;
        } else if (line[i] == 'C') {
            ++c;
        } else {
            ++g;
        }
    }
    cout << (t * t) + (c * c) + (g * g) + min(t, min(c, g)) * 7 << endl;
    return 0;
}
