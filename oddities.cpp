#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (abs(a) & 1) {
            cout << a << " is odd" << endl;
        } else {
            cout << a << " is even" << endl;
        }
    }
    return 0;
}
