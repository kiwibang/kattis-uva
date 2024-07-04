#include <bits/stdc++.h>
using namespace std;

int main() {
    string msg;
    cin >> msg;
    int lefth = 0, righth = 0;
    for (int i = 0; i < msg.size(); ++i) {
        if (i < msg.size() / 2) {
            lefth += (msg[i] - 'A');
        } else {
            righth += (msg[i] - 'A');
        }
    }
    // change the vals
    for (int i = 0; i < msg.size(); ++i) {
        if (i < msg.size() / 2) {
            msg[i] = ((msg[i] - 'A' + lefth) % 26) + 'A';
        } else {
            msg[i] = ((msg[i] - 'A' + righth) % 26) + 'A';
        }
    }
    // get the decoded message
    for (int i = 0; i < msg.size() / 2; ++i) {
        int rot = msg[i + msg.size() / 2] - 'A';
        cout << (char) (((msg[i] - 'A' + rot) % 26) + 'A');
    }
    cout << endl;
    return 0;
}
