#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Lumberjacks:" << endl;
    int n;
    cin >> n;
    while (n--) {
        int lbs[10];
        for (int i = 0; i < 10; ++i) {
            cin >> lbs[i];
        }
        int r = 0;
        for (int i = 0; i < 9; ++i) {
            if (lbs[i] > lbs[i + 1]) {
                r++;
            } else {
                r--;
            }
        }
        if (abs(r) == 9) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
    }
    return 0;
}
