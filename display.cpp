#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> timemap;
    timemap['1'] = "    +    |    |    +    |    |    +";
    timemap['2'] = "+---+    |    |+---+|    |    +---+";
    timemap['3'] = "+---+    |    |+---+    |    |+---+";
    timemap['4'] = "+   +|   ||   |+---+    |    |    +";
    timemap['5'] = "+---+|    |    +---+    |    |+---+";
    timemap['6'] = "+---+|    |    +---+|   ||   |+---+";
    timemap['7'] = "+---+    |    |    +    |    |    +";
    timemap['8'] = "+---+|   ||   |+---+|   ||   |+---+";
    timemap['9'] = "+---+|   ||   |+---+    |    |+---+";
    timemap['0'] = "+---+|   ||   |+   +|   ||   |+---+";
    while (true) {
        string time;
        cin >> time;
        if (time == "end") {
            cout << "end" << endl;
            break;
        }
        vector<string> res(7, "");
        for (int i = 0; i < time.size(); ++i) {
            if (time[i] == ':') {
                res[0] += " ";
                res[1] += " ";
                res[2] += "o";
                res[3] += " ";
                res[4] += "o";
                res[5] += " ";
                res[6] += " ";
            } else {
                string curr = timemap[time[i]];
                res[0] += curr.substr(0, 5);
                res[1] += curr.substr(5, 5);
                res[2] += curr.substr(10, 5);
                res[3] += curr.substr(15, 5);
                res[4] += curr.substr(20, 5);
                res[5] += curr.substr(25, 5);
                res[6] += curr.substr(30, 5);
            }
            if (i < time.size() - 1) {
                res[0] += "  ";
                res[1] += "  ";
                res[2] += "  ";
                res[3] += "  ";
                res[4] += "  ";
                res[5] += "  ";
                res[6] += "  ";
            }
        }
        for (int i = 0; i < 7; ++i) {
            cout << res[i] << endl;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
