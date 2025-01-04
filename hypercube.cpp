#include <bits/stdc++.h>
using namespace std;

long long hp(long long num) {
    long long mask = num;
    while (mask) {
        mask >>= 1;
        num ^= mask;
    }
    return num;
}

long long tol(string st) {
    long long res = 0;
    for (int i = 0; i < st.size(); ++i) {
        res = (res * 2) + (st[i] - '0');
    }
    return res;
}

int main() {
    int n;
    string astr, bstr;
    cin >> n >> astr >> bstr;
    long long a = tol(astr), b = tol(bstr);
    cout << hp(b) - hp(a) - 1 << endl;
    return 0;
}

