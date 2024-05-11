#include <iostream>
using namespace std;

int main() {
    int N, n, m;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &n, &m);
        cout << (n / 3) * (m / 3) << endl;
    }
    return 0;
}
