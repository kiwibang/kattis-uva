#include <bits/stdc++.h>
using namespace std;

int main() {
    const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while (true) {
        string curr;
        getline(cin, curr);
        if (cin.eof()) {
            break;
        }
        for (int i = 0; i < curr.size(); ++i) {
            if (isspace(curr[i])) {
                cout << " ";
                continue;
            }
            int cc = tolower(curr[i]);
            for (int j = 0; keyboard[j]; ++j) {
                if (cc == keyboard[j]) {
                    cout << keyboard[j - 2];
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
