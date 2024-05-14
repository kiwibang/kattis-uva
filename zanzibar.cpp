#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count, prev, curr, sum;
    cin >> n;
    while (n--) {
        prev = -1;
        curr = -1;
        sum = 0;
        while (true) {
            cin >> curr;
            if (curr == 0) {
                break;
            }
            if (prev == -1) {
                prev = curr;
            } else {
                sum += max(0, curr - prev * 2);
            }
            prev = curr;
        }
        cout << sum << endl;
    }
    return 0;
}
