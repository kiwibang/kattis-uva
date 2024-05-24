#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            return 0;
        }
        // read in the pokemon cards
        set<int> sa;
        set<int> sb;
        set<int> common;
        for (int i = 0; i < a; ++i) {
            int curr;
            cin >> curr;
            sa.insert(curr);
        }
        for (int i = 0; i < b; ++i) {
            int curr;
            cin >> curr;
            if (sa.find(curr) != sa.end()) {
                common.insert(curr);
            } else {
                sb.insert(curr);
            }
        }
        for (int e : common) {
            if (sa.find(e) != sa.end()) {
                sa.erase(e);
            }
            if (sb.find(e) != sb.end()) {
                sb.erase(e);
            }
        }
        cout << min(sa.size(), sb.size()) << endl;
    }
    return 0;
}
