#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, carry, a1, b1, c;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        carry = 0, c = 0;
        while (a > 0 || b > 0) {
            a1 = (a % 10), b1 = (b % 10);
            int d = a1 + b1 + c;
            if (d >= 10) {
                ++carry;
                c = 1;
            } else {
                c = 0;
            }
            a /= 10, b /= 10;
        }
        if (carry == 0) {
            cout << "No carry operation." << endl;
        } else if (carry == 1) {
            cout << carry << " carry operation." << endl;
        } else {
            cout << carry << " carry operations." << endl;
        }
    }
    return 0;
}

