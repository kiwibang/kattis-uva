// adapted from: https://github.com/Mangern/kattis/blob/main/magicsequence/main.cpp
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 6;
int a1[mx];
int a2[mx];
int f[8];

void hp() {
    int n;
    long long a, b, c, x, y;
    // read in input
    cin >> n >> a >> b >> c >> x >> y;
    // build array s
    int* s = a1;
    int* temp = a2;
    s[0] = a;
    b %= c;
    a %= c;
    for (int i = 1; i < n; ++i) {
        s[i] = (s[i - 1] * b + a) % c;
    }
    // radix sort in custom base
    for (int digits = 0; digits < 30; digits += 3) {
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            ++f[(s[i] >> digits) & 0b111];
        }
        f[1] += f[0];
        f[2] += f[1];
        f[3] += f[2];
        f[4] += f[3];
        f[5] += f[4];
        f[6] += f[5];
        f[7] += f[6];
        for (int i = n - 1; i >= 0; --i) {
            temp[(f[(s[i] >> digits) & 0b111]--) - 1] = s[i];
        }
        for (int i = 0; i < n; ++i) s[i] = temp[i];
    }
    // then compute and output hash value
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res = (res * x + s[i]) % y;
    }
    cout << res << endl;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    // read in number of testcases
    cin >> t;
    while (t--) {
        hp();
    }
    return 0;
}

