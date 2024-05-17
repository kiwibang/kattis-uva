#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, x, cnt;
    int currCnt = 0;
    int res = 0;
    cin >> l >> x;
    string event;
    while (x--) {
        cin >> event >> cnt;
        if (string(event) == "enter") {
            if (currCnt + cnt > l) {
                ++res;
            } else {
                currCnt += cnt;
            }
        } else {
            currCnt -= cnt;
        }
    }
    cout << res << endl;
    return 0;
}
