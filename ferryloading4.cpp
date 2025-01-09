#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int l, m, res = 0, len, bank = 0;
        string dir;
        queue<int> left, right;
        cin >> l >> m;
        l *= 100;
        for (int i = 0; i < m; ++i) {
            cin >> len >> dir;
           if (dir == "left") {
                left.push(len);
           } else {
                right.push(len);
           } 
        }
        while (!left.empty() || !right.empty()) {
            if (!bank) {
                if (left.empty()) goto travel;
                // load the cars
                int cl = 0;
                while (!left.empty()) {
                    if (cl + left.front() > l) {
                        break;
                    }
                    cl += left.front();
                    left.pop();
                } 
            } else {
                if (right.empty()) goto travel;
                // load the cars
                int cl = 0;
                while (!right.empty()) {
                    if (cl + right.front() > l) {
                        break;
                    }
                    cl += right.front();
                    right.pop();
                } 
            }
            travel:
            ++res;
            bank ^= 1;
            if (left.empty() && right.empty()) goto pr;
        }
        pr:
        cout << res << endl;
    }
    return 0;
}

