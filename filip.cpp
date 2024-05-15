#include <bits/stdc++.h>
using namespace std;

int flip(int n);

int main() {
    int a, b;
    cin >> a >> b;
    a = flip(a);
    b = flip(b);
    if (a > b) {
        cout << a << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}

int flip(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;
    }
    return res;
}
