#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 0, curr;
    double total = 0;
    cin >> n;
    while (n--) {
        cin >> curr;
        if (curr != -1) {
            ++count;
            total += curr;
        }
    }
    cout << total / count << endl;
    return 0;
}
