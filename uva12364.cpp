#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> brmap;
    brmap['1'] = "*.....";
    brmap['2'] = "*.*...";
    brmap['3'] = "**....";
    brmap['4'] = "**.*..";
    brmap['5'] = "*..*..";
    brmap['6'] = "***...";
    brmap['7'] = "****..";
    brmap['8'] = "*.**..";
    brmap['9'] = ".**...";
    brmap['0'] = ".***..";

    map<string, char> invmap;
    invmap["*....."] = '1';
    invmap["*.*..."] = '2';
    invmap["**...."] = '3';
    invmap["**.*.."] = '4';
    invmap["*..*.."] = '5';
    invmap["***..."] = '6';
    invmap["****.."] = '7';
    invmap["*.**.."] = '8';
    invmap[".**..."] = '9';
    invmap[".***.."] = '0';

    while (true) {
        int d;
        cin >> d;
        if (d == 0) {
            break;
        }
        char cc;
        cin >> cc;
        if (cc == 'S') {
            string msg;
            cin >> msg;
            vector<string> res(3, "");
            for (int i = 0; i < msg.size(); ++i) {
                string num = brmap[msg[i]];
                res[0] += num.substr(0, 2);
                res[1] += num.substr(2, 2);
                res[2] += num.substr(4, 2);
                if (i < msg.size() - 1) {
                    res[0] += " ";
                    res[1] += " ";
                    res[2] += " ";
                }
            }
            cout << res[0] << endl;
            cout << res[1] << endl;
            cout << res[2] << endl;
        } else {
            cin.ignore();
            vector<string> br(3, "");
            getline(cin, br[0]);
            getline(cin, br[1]);
            getline(cin, br[2]);
            for (int i = 0; i < br[0].size(); i += 3) {
                // get the current num
                string num = br[0].substr(i, 2) + br[1].substr(i, 2) + br[2].substr(i, 2);
                cout << invmap[num];
            }
            cout << endl;
        }
    }
    return 0;
}
