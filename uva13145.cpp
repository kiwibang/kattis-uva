#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string line;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin.ignore();
        getline(cin, line);
        for (int i = 0; i < line.size(); ++i) {
            if (!isalpha(line[i])) {
                cout << line[i];
                continue;
            }
            char base = isupper(line[i]) ? 'A' : 'a';
            int offset = (line[i] - base + n) % 26;
            offset =  offset < 0 ? 26 + offset : offset;
            cout << (char) (offset + base);
        }
        cout << endl;
    }
    return 0;
}
