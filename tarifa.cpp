#include <iostream>
using namespace std;

int main() {
    int X, N, P, res = 0;
    scanf("%d", &X);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P);
        res += (X - P);
    }
    res += X;
    cout << res << endl;
    return 0;
}
