#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> valmap;
    valmap['B'] = 1;
    valmap['U'] = 10;
    valmap['S'] = 100;
    valmap['P'] = 1000;
    valmap['F'] = 10000;
    valmap['T'] = 100000;
    valmap['M'] = 1000000;
    int n;
    cin >> n;
    while (n--) {
        string hlgy;
        cin >> hlgy;
        long long res = valmap[hlgy[0]];
        int prev = valmap[hlgy[0]], asc = 1, desc = 1, consec = 1, lol = 1;
        for (int i = 1; i < hlgy.size(); ++i) {
            if (prev > valmap[hlgy[i]]) {
                asc = 0;
                consec = 1;
            } else if (prev < valmap[hlgy[i]]) {
                desc = 0;
                consec = 1;
            } else {
                ++consec;
                if (consec > 9) {
                    lol = 0;
                    break;
                }
            }
            res += valmap[hlgy[i]];
            prev = valmap[hlgy[i]];
        }
        if (!lol) {
            cout << "error" << endl;
            continue;
        }
        if (!asc && !desc) {
            cout << "error" << endl;
            continue;
        }
        cout << res << endl;
    }
    return 0;
}
