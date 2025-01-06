#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t1 = -1, t2 = -1, res = 0;
    cin >> n;
    int s1[(n << 1)], s2[(n << 2)];
    // read in the socks
    for (int i = 0; i < (n << 1); ++i) {
        cin >> s2[++t2];
    }
    // move the socks to stack 1
    for (int i = 0; i < (n << 1); ++i) {
        s1[++t1] = s2[t2--];
    }
    // then simulate the stack
    while (t1 >= 0) {
        s2[++t2] = s1[t1--];
        while (t1 >= 0 && s2[t2] == s1[t1]) {
            // pop both
            s2[t2--] = -1;
            s1[t1--] = -1;
            ++res;
        }
        ++res;
    }
    if (t1 == -1 && t2 == -1) {
        cout << res << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}

