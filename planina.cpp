#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long res = 2;
    for (int i = 0; i < n; i++) {
        res = res * 2 - 1;
    }
    cout << res * res << endl;
    return 0;
}
