#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    string s, p, c;
    while (true) {
        cin >> x;
        if (x == 0) {
            break;
        }
        cin >> s >> p >> c;
        n = c.size();
        vector<char> m(n, '*');
        // get d
        int d = (int) (pow(n, 1.5) + x) % n;
        // get the char at position d
        char pp = c[d];
        // get the correct char index
        int idx = 0;
        for (; idx < s.size(); ++idx) {
            if (s[idx] == pp) {
                break;
            }
        }
        // set m
        m[d] = p[idx];
        // decrypt from d - 1 to 0
        for (int i = d - 1; i >= 0; --i) {
            // get the right index
            int a = 0;
            for (; a < s.size(); ++a) {
                if (s[a] == m[((i + 1) % n)]) {
                    break;
                }
            }
            // get the index of the current char in c
            int b = 0;
            for (; b < s.size(); ++b) {
                if (s[b] == c[i]) {
                    break;
                }
            }
            // get the char at m[i]
            m[i] = p[b ^ a];
        }
        // decrypt from n - 1 to d + 1
        for (int i = n - 1; i >= d + 1; --i) {
            // get the right index
            int a = 0;
            for (; a < s.size(); ++a) {
                if (s[a] == m[((i + 1) % n)]) {
                    break;
                }
            }
            // get the index of the current char in c
            int b = 0;
            for (; b < s.size(); ++b) {
                if (s[b] == c[i]) {
                    break;
                }
            }
            // get the char at m[i]
            m[i] = p[b ^ a];
        }
        for (int i = 0; i < n; ++i) {
            cout << m[i];
        }
        cout << endl;
    }
    return 0;
}
