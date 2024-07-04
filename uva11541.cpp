#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        string curr;
        cin >> curr;
        cout << "Case " << t << ": ";
        int i = 0;
        while (i < curr.size()) {
            // get the char
            char cc = curr[i++];
            int cnt = 0;
            while (i < curr.size() && isdigit(curr[i])) {
                cnt = (cnt * 10) + (curr[i++] - '0');
            }
            for (int j = 0; j < cnt; ++j) {
                cout << cc;
            }
        }
        cout << endl;
    }
    return 0;
}
