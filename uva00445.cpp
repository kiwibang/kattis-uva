#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 0;
    while (true) {
        if (tc++ > 0) {
            cout << endl;
        }
        string curr;
        while (true) {
            getline(cin, curr);
            if (curr.empty()) {
                break;
            }
            int idx = 0;
            while (idx < curr.size()) {
                int n = 0;
                while (idx < curr.size() && isdigit(curr[idx])) {
                    n += (curr[idx++] - '0');
                }
                char c = curr[idx] == 'b' ? ' ' : curr[idx];
                for (int i = 0; i < n; ++i) {
                    cout << c;
                }
                ++idx;
                if (idx < curr.size() && curr[idx] == '!') {
                    cout << endl;
                    ++idx;
                }
            }
            cout << endl;
        }
        if (cin.eof()) {
            break;
        }
    }
    return 0;
}
