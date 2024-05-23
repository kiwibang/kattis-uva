#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    long long totalArea = 0;
    for (int i = 0; i < n; ++i) {
        int wi, li;
        cin >> wi >> li;
        totalArea += wi * li;
    }
    cout << (int) totalArea / w << endl;
    return 0;
}
