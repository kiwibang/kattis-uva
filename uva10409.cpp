#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        int top = 1;
        int north = 2;
        int west = 3;
        for (int i = 0; i < n; ++i) {
            string dir;
            cin >> dir;
            if (dir == "north") {
                int temp = north;
                north = top;
                top = 7 - temp;
            } else if (dir == "south") {
                int temp = top;
                top = north;
                north = 7 - temp;
            } else if (dir == "east") {
                int temp = top;
                top = west;
                west = 7 - temp;
            } else if (dir == "west") {
                int temp = west;
                west = top;
                top = 7 - temp;
            }
        }
        cout << top << endl;
    }
    return 0;
}
