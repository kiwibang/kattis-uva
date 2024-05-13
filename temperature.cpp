#include <iostream>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    if (y == 1) {
        if (x == 0) {
            cout << "ALL GOOD" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        return 0;
    }
    cout << fixed;
    cout.precision(9);
    cout << - (x / (y - 1)) << endl;
    return 0;
}
