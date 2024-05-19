#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string line;
        cin >> line;
        int res = 0;
        stack<int> s;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '\\') {
                // add index to stack for later
                s.push(i);
            } else if (line[i] == '/' && !s.empty()) {
                // update the res
                res += i - s.top();
                s.pop();
            }
        }
        cout << res << endl;
    }
    return 0;
}
