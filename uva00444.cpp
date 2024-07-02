#include <bits/stdc++.h>
using namespace std;

bool ok (int num) {
    return (65 <= num && num <= 90) || (97 <= num && num <= 122) || num == 32 || num == 33 || num == 44 || num == 46 || num == 58 || num == 59 || num == 63;
}
string decode(string msg) {
    reverse(msg.begin(), msg.end());
    string res = "";
    int currmsg = 0;
    for (int i = 0; i < msg.size(); ++i) {
        currmsg = currmsg * 10 + (msg[i] - '0');
        if (currmsg >= 2 && ok(currmsg)) {
            res.push_back((char) currmsg);
            currmsg = 0;
        }
    }
    return res;
}

string encode(string msg) {
    string res = "";
    for (int i = 0; i < msg.size(); ++i) {
        res += to_string((int) msg[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string msg;
    while (true) {
        getline(cin, msg);
        if (cin.eof()) {
            break;
        }
        // not encoded
        if (isalpha(msg[0])) {
            cout << encode(msg) << endl;
        } else { // encoded
            cout << decode(msg) << endl;
        }
    }
    return 0;
}
