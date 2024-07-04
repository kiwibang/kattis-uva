#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string line;
    getline(cin, line);
    int i = 0;
    while (i < line.size()) {
        if (!isvowel(line[i])) {
            cout << line[i];
            ++i;
            continue;
        }
        cout << line[i];
        i += 3;
    }
    cout << endl;
    return 0;
}
