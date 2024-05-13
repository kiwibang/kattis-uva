#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    if (l + r == 0) {
        cout << "Not a moose" << endl;
        return 0;
    }
    if (l == r) {
        cout << "Even ";
    } else {
        cout << "Odd ";
    }
    cout << max(l, r) * 2 << endl;
    return 0;
}
