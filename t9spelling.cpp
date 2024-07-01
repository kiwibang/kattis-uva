#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> chartostr;
    chartostr['a'] = "2";
    chartostr['b'] = "22";
    chartostr['c'] = "222";
    chartostr['d'] = "3";
    chartostr['e'] = "33";
    chartostr['f'] = "333";
    chartostr['g'] = "4";
    chartostr['h'] = "44";
    chartostr['i'] = "444";
    chartostr['j'] = "5";
    chartostr['k'] = "55";
    chartostr['l'] = "555";
    chartostr['m'] = "6";
    chartostr['n'] = "66";
    chartostr['o'] = "666";
    chartostr['p'] = "7";
    chartostr['q'] = "77";
    chartostr['r'] = "777";
    chartostr['s'] = "7777";
    chartostr['t'] = "8";
    chartostr['u'] = "88";
    chartostr['v'] = "888";
    chartostr['w'] = "9";
    chartostr['x'] = "99";
    chartostr['y'] = "999";
    chartostr['z'] = "9999";
    chartostr[' '] = "0";

    map<char, int> grpmap;
    grpmap['a'] = 2;
    grpmap['b'] = 2;
    grpmap['c'] = 2;
    grpmap['d'] = 3;
    grpmap['e'] = 3;
    grpmap['f'] = 3;
    grpmap['g'] = 4;
    grpmap['h'] = 4;
    grpmap['i'] = 4;
    grpmap['j'] = 5;
    grpmap['k'] = 5;
    grpmap['l'] = 5;
    grpmap['m'] = 6;
    grpmap['n'] = 6;
    grpmap['o'] = 6;
    grpmap['p'] = 7;
    grpmap['q'] = 7;
    grpmap['r'] = 7;
    grpmap['s'] = 7;
    grpmap['t'] = 8;
    grpmap['u'] = 8;
    grpmap['v'] = 8;
    grpmap['w'] = 9;
    grpmap['x'] = 9;
    grpmap['y'] = 9;
    grpmap['z'] = 9;
    grpmap[' '] = 0;

    int tc;
    cin >> tc;
    cin.ignore();
    for (int t = 1; t <= tc; ++t) {
        cout << "Case #" << t << ": ";
        string msg;
        getline(cin, msg);
        int prevchar = msg[0];
        cout << chartostr[prevchar];
        for (int i = 1; i < msg.size(); ++i) {
            if (grpmap[prevchar] == grpmap[msg[i]]) {
                cout << " ";
            }
            cout << chartostr[msg[i]];
            prevchar = msg[i];
        }
        cout << endl;
    }
    return 0;
}
