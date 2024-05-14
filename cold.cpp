#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 0, curr;
    cin >> n;
    while (n--) {
        cin >> curr;
        if (curr < 0) {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
