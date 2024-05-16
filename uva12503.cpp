#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> instrs;
        string instr;
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            cin >> instr;
            if (instr == "LEFT") {
                --pos;
                instrs.push_back(-1);
            } else if (instr == "RIGHT") {
                ++pos;
                instrs.push_back(1);
            } else {
                int j;
                cin >> instr >> j;
                pos += instrs[j - 1];
                instrs.push_back(instrs[j - 1]);
            }
        }
        cout << pos << endl;
    }
    return 0;
}
