#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the number of testcases
    int tc;
    cin >> tc;
    while (tc--) {
        // read in the current number
        int curr;
        cin >> curr;
        // track a and b
        int a = 0, b = 0, temp = curr;
        while (temp > 0) {
            if (temp & 1) {
                ++a;
            }
            temp >>= 1;
        }
        temp = curr;
        while (temp > 0) {
            // get the last digit
            int dg = temp % 10;
            // count the number of 1s in the last digit
            while (dg > 0) {
                if (dg & 1) {
                    ++b;
                }
                dg >>= 1;
            }
            temp /= 10;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
