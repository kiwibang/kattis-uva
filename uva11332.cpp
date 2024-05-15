#include <bits/stdc++.h>
using namespace std;

int f(int n);

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }
        while (n >= 10) {
            n = f(n);
        }
        cout << n << endl;
    }
    return 0;
}
int f(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}
