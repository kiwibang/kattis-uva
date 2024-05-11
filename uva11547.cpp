#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N, n;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &n);
        cout << abs((((((n * 567 / 9) + 7492) * 235) / 47) - 498) / 10 % 10) << endl;
    }
    return 0;
}
