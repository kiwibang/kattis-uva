#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, d, e;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> t;
        getline(cin, line);
        istringstream iss2(line);
        iss2 >> a >> b >> c >> d >> e;
        int count = 0;
        if (a == t) {
            ++count;
        }
        if (b == t) {
            ++count;
        }
        if (c == t) {
            ++count;
        }
        if (d == t) {
            ++count;
        }
        if (e == t) {
            ++count;
        }
        cout << count << endl;
    }
    return 0;
}
