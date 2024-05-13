#include <iostream>
using namespace std;

int main() {
    int t, l, w, h;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin.ignore();
        cin >> l >> w >> h;
        cout << "Case " << i << ": ";
        if (l <= 20 && w <= 20 && h <= 20) {
            cout << "good" << endl;
        } else {
            cout << "bad" << endl;
        }
    }
    return 0;
}
