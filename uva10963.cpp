#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int w;
        int y1, y2;
        bool canClose = true;
        cin >> w; 
        cin >> y1 >> y2;
        int gap = y1 - y2;
        while (w--) {
            if (gap != (y1 - y2)) {
                canClose = false;
            }
        }
        if (canClose) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
        if (cnt > 0) {
            cout << "\n";
        }
    }
    return 0;
}
