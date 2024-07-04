#include <bits/stdc++.h>
using namespace std;

int main() {
    char mode;
    string msg;
    cin >> mode >> msg;
    if (mode == 'E') {
        int i = 0, count;
        string res = "";
        while (i < msg.size()) {
            count = 0;
            char curr = msg[i];
            while (i < msg.size() && curr == msg[i]) {
                ++count;
                ++i;
            }
            res += curr;
            res += (count + '0');
        }
        cout << res << endl;
    } else {
        int i = 0;
        while (i < msg.size()) {
            char curr = msg[i++];
            int count = (msg[i++] - '0');
            for (int j = 0; j < count; ++j) {
                cout << curr;
            }
        }
        cout << endl;
    }
    return 0;
}
