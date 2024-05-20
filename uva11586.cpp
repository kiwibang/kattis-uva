#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string line;
        getline(cin, line);
        int mc = 0, fc = 0;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                continue;
            } else if (line[i] == 'M') {
                ++mc;
            } else {
                ++fc;
            }
        }
        if (mc == fc && mc > 1) {
            cout << "LOOP" << endl;
        } else {
            cout << "NO LOOP" << endl;
        }
    }
    return 0;
}
