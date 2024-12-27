#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, p;
    cin >> c >> p;
    vector<int> h(c);
    for (int i = 0; i < c; ++i) cin >> h[i];    
    int res = 0;
    if (p == 1) {
        res += c;
        for (int i = 0; i < c - 3; ++i) {
            if (h[i] == h[i + 1] && h[i + 1] == h[i + 2] && h[i + 2] == h[i + 3]) ++res;
        }
    } else if (p == 2) {
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] == h[i + 1]) ++res;
        }
    } else if (p == 3) {
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] && h[i + 1] + 1 == h[i + 2])++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] - 1 == h[i + 1]) ++res;
        }
    } else if (p == 4) {
        for (int i = 0; i < c - 2; ++i) {
            if (h[i + 2] == h[i + 1] && h[i + 1] + 1 == h[i]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] + 1 == h[i + 1]) ++res;
        }
    } else if (p == 5) {
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] && h[i + 1] == h[i + 2]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] == h[i + 1] + 1) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] + 1 == h[i + 1]) ++res;
        }
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] + 1 && h[i + 1] + 1 == h[i + 2]) ++res;
        }
    } else if (p == 6) {
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] && h[i + 1] == h[i + 2]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] == h[i + 1]) ++res;
        }
        for (int i = 0; i < c - 2; ++i) {
            if (h[i + 1] == h[i + 2] && h[i] + 1 == h[i + 1]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] == h[i + 1] + 2) ++res;
        }
    } else if (p == 7) {
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] && h[i + 1] == h[i + 2]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] == h[i + 1]) ++res;
        }
        for (int i = 0; i < c - 2; ++i) {
            if (h[i] == h[i + 1] && h[i + 2] + 1 == h[i + 1]) ++res;
        }
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] + 2 == h[i + 1]) ++res;
        }
    }
    cout << res << endl;
    return 0;
}

