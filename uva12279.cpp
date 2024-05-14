#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 42;
    int j = 1;
    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }
        int supposeCount = 0;
        int giveCount = 0;
        int curr;
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            if (curr == 0) {
                ++giveCount;
            } else {
                ++supposeCount;
            }
        }
        cout << "Case " << j++ << ": " << supposeCount - giveCount << endl;
    }
    return 0;
}
