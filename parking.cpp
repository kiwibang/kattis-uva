#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, arr, dpt;
    cin >> a >> b >> c;
    vector<int> time = vector<int>(101, 0);
    for (int i = 0; i < 3; ++i) {
        cin >> arr >> dpt;
        for (int j = arr; j < dpt; ++j) {
            ++time[j];
        }
    }
    int total = 0;
    for (int i = 1; i <= 100; ++i) {
        if (time[i] == 1) {
            total += a;
        } else if (time[i] == 2) {
            total += (b * 2);
        } else if (time[i] == 3) {
            total += (c * 3);
        }
    }
    cout << total << endl;
    return 0;
}

