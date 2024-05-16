#include <bits/stdc++.h>
using namespace std;

int main() {
    string line, token;
    int m;
    string pid, status;
    // data structures
    map<string, int> d;
    int res = 0;
    int ac = 0;
    while (true) {
        // extracting the relevant info
        getline(cin, line);
        if (line == "-1") {
            break;
        }
        istringstream iss(line);
        getline(iss, token, ' ');
        m = stoi(token);
        getline(iss, pid, ' ');
        getline(iss, status, ' ');
        // process data
        if (!d.count(pid)) {
            d[pid] = 0;
        }
        // if correct
        if (status == "right") {
            res = res + (d[pid] * 20 + m);
            ++ac;
        } else {
            ++d[pid];
        }
    }
    cout << ac << " " << res << endl;
    return 0;
}
