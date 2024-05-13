#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r, n;
    int i = 1;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> r >> n;
        if (r == 0 && n == 0) {
            return 0;
        }
        cout << "Case " << i++ << ": ";
        int ans = max(0, static_cast<int>(ceil(static_cast<double>(r - n) / n)));
        if (ans > 26) {
            cout << "impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}