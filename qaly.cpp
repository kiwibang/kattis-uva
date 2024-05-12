#include <iostream>
using namespace std;

int main() {
    int n;
    double a, b, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &a, &b);
        res += (a * b);
    }
    cout << res << endl;
    return 0;
}
