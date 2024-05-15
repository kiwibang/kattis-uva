#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int x0;
    while (true) {
        getline(cin, line);
        if (line == "END") {
            return 0;
        }
        istringstream iss(line);
        iss >> x0;
        if (x0 == 0) {
            cout << 2 << endl;
            continue;
        }
        int i = 1;
        int prev = x0;
        while (true) {
            int curr = 0, temp = prev;
            while (temp > 0) {
                temp /= 10;
                ++curr;
            }
            if (prev == curr) {
                cout << i << endl;
                break;
            }
            prev = curr;
            ++i;
        }
    }
    return 0;
}
