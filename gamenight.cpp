#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 0, b = 0, c = 0, res, nm = 0;
    cin >> n;
    res = n;
    string s;
    cin >> s;
    s += s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            ++a;
        } else if (s[i] == 'B') {
            ++b;
        } else if (s[i] == 'C') {
            ++c;
        }
    }
    for (int i = 0; i < a; ++i) if (s[i] == 'A') ++nm; 
    for (int i = a; i < a + b; ++i) if (s[i] == 'B') ++nm; 
    for (int i = a + b; i < n; ++i) if (s[i] == 'C') ++nm; 
    res = min(res, n - nm);
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'A') --nm;
        if (s[i + a - 1] == 'A') ++nm;
        if (s[i + a - 1] == 'B') --nm;
        if (s[i + a + b - 1] == 'B') ++nm;
        if (s[i + a + b - 1] == 'C') --nm;
        if (s[i + a + b + c - 1] == 'C') ++nm;
        res = min(res, n - nm);
    }
    nm = 0;
    for (int i = 0; i < a; ++i) if (s[i] == 'A') ++nm; 
    for (int i = a; i < a + c; ++i) if (s[i] == 'C') ++nm; 
    for (int i = a + c; i < n; ++i) if (s[i] == 'B') ++nm; 
    res = min(res, n - nm);
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'A') --nm;
        if (s[i + a - 1] == 'A') ++nm;
        if (s[i + a - 1] == 'C') --nm;
        if (s[i + a + c - 1] == 'C') ++nm;
        if (s[i + a + c - 1] == 'B') --nm;
        if (s[i + a + b + c - 1] == 'B') ++nm;
        res = min(res, n - nm);
    }
    cout << res << endl;
    return 0;
}

