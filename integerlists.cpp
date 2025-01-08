#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string program, ints, currint = "";
        int n;
        cin >> program >> n >> ints;
        deque<int> dq;
        if (n == 0) goto process;
        for (int i = 1; i < ints.size(); ++i) {
            if (ints[i] == ',' || ints[i] == ']') {
                dq.push_back(stoi(currint));
                currint = "";
                continue;
            }
            currint += ints[i];
        }
process:
        bool reverse = false, error = false;
        for (int i = 0; i < program.size(); ++i) {
            if (program[i] == 'R') {
                reverse = !reverse;
            } else {
                if (!dq.size()) {
                    error = true;
                    break;
                }
                if (reverse) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }
        if (error) {
            cout << "error" << endl; 
        } else {
            cout << "[";
            if (reverse) {
                while (!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (dq.size() > 0) cout << ",";
                }
            } else {
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (dq.size() > 0) cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
    return 0;
}

