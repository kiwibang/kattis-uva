#include <iostream>
using namespace std;

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, K, P = 0;
        scanf("%d %d %d", &N, &K, &P);
        int res = (K + P) % N;
        res = res == 0 ? N : res;
        cout << "Case " << (i + 1) << ": " << res << endl;
    }
    return 0;
}
