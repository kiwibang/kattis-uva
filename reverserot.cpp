#include <bits/stdc++.h>
using namespace std;

int main() {
    int rot;
    string curr, alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    while (true) {
        // get the input
        cin >> rot >> curr;
        if (cin.eof()) {
            break;
        }
        // then encode the message
        for (int i = 0; i < curr.size(); ++i) {
            int idx = isalpha(curr[i]) ? (curr[i] - 'A' + rot) % 28 : curr[i] == '_' ? (26 + rot) % 28 : (27 + rot) % 28;
            curr[i] = alpha[idx];
        }
        // print the encoded message in reverse
        for (int i = curr.size() - 1; i >= 0; --i) {
            cout << curr[i];
        }
        cout << endl;
    }
    return 0;
}
