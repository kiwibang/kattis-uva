#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (cin.eof()) {
            return 0;
        }
        istringstream iss(line);
        int n, i, j;
        iss >> n >> i >> j;
        int rounds = 0;
        while (i != j) {
            i = (int) ceil((double) i / 2);
            j = (int) ceil((double) j / 2);
            ++rounds;
        }
        cout << rounds << endl;
    }
    return 0;
}
