#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int adj = 1440;
    while (n--) {
        char r;
        int d, h, m;
        cin >> r >> d >> h >> m;
        int mins = h * 60 + m;
        if (r == 'F') {
            mins = (mins + d) % adj;
        } else if (r == 'B') {
            mins -= d;
            if (mins < 0) {
                mins += adj;
            }
        }
        cout << mins / 60 << " " << mins % 60 << endl;
    }
    return 0;
}
