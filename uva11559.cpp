#include <bits/stdc++.h>
using namespace std;

int main() {
    while (!cin.eof()) {
        int n, b, h, w;
        cin >> n >> b >> h >> w;
        if (cin.eof()) {
            return 0;
        }
        int price;
        int res = 3000000;
        while (h--) {
            cin >> price;
            int availability;
            for (int i = 0; i < w; ++i) {
                cin >> availability;
                int totalCost = price * n;
                if (n <= availability && totalCost <= b) {
                    res = min(res, totalCost);
                }
            }
        }
        if (res != 3000000) {
            cout << res << endl;
        } else {
            cout << "stay home" << endl;
        }
    }
    return 0;
}
