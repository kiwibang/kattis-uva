#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, n;
    cin >> C >> n;
    int count = 0;
    bool impossible = false;
    for (int i = 0; i < n; ++i) {
        int left, entered, stayed;
        cin >> left >> entered >> stayed;
        if (impossible) {
            continue;
        }
        // update the train capacity 
        count = count - left + entered;
        // case where at least one passenger left at the first stop
        // or case at least one passenger entered at the last stop
        // or case where at least one passenger waited at the last stop
        if ((i == 0 && left > 0) || (i == n - 1 && entered > 0) || (i == n - 1 && stayed > 0) || (i == n - 1 && count > 0) || (count < C && stayed > 0) || (count < 0 || count > C)) {
            impossible = true;
            continue;
        }
    }
    if (impossible) {
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
    }
    return 0;
}
