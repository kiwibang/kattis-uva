#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr, sum = 0;
    cin >> n;
    while (n--) {
        cin >> curr;
        if (curr < 0) {
            sum += -curr;
        }
    }
    cout << sum << endl;
    return 0;
}
