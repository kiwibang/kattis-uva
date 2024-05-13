#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string line;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (line.length() == 5) {
            cout << 3 << endl;
        } else {
            int diff1 = 0;
            int diff2 = 0;
            if (line[0] != 'o') {
                ++diff1;
            }
            if (line[1] != 'n') {
                ++diff1;
            }
            if (line[2] != 'e') {
                ++diff1;
            }
            if (line[0] != 't') {
                ++diff2;
            }
            if (line[1] != 'w') {
                ++diff2;
            }
            if (line[2] != 'o') {
                ++diff2;
            }
            cout << "diff 1 " << diff1 << endl;
            cout << "diff 2 " << diff2 << endl; 
            if (diff1 <= 1 && (line.find('o') == 0 || line.find('n') == 1 || line.find('e') == 2)) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}
