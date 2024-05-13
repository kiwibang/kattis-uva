#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> a >> b;
        if (a == -1 && b == -1) {
            return 0;
        }
        int down = a == b ? 0 : a > b ? a - b : 100 + a - b; 
        int up = a == b ? 0 : a > b ? 100 + b - a : b - a;
        cout << min(down, up) << endl;
    }
    return 0;
}
