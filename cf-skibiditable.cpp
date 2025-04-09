// CREDITS:https://codeforces.com/blog/entry/141434
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            string cmd;
            cin >> cmd;
            if (cmd == "->") { // coord -> num
                int x, y;
                cin >> x >> y;
                --x, --y;
                long long num = 0;
                for (int i = n - 1; i >= 0; --i) {
                    int lim = 1 << i; // 2^(n - 1)
                    if (!(x & lim) && !(y & lim)) // top left
                        num ^= 0ll << (i << 1); // add 0 * 4^(n - 1) 
                    else if ((x & lim) && (y & lim)) // bottom right
                        num ^= 1ll << (i << 1); // add 1 * 4^(n - 1) 
                    else if ((x & lim) && !(y & lim)) // bottom left
                        num ^= 2ll << (i << 1); // add 2 * 4^(n - 1) 
                    else if (!(x & lim) && (y & lim)) // top right
                        num ^= 3ll << (i << 1); // add 3 * 4^(n - 1) 
                }
                cout << num + 1 << "\n"; // +1 to account for base case 2^0
            } else { // num -> coord
                long long num;
                cin >> num;
                --num;
                int x = 0, y = 0;
                for (int i = n - 1; i >= 0; --i) {
                    long long base = 3ll << (i << 1);
                    if ((num & base) >> (i << 1) == 0) // top left
                        x ^= 0 << i, y ^= 0 << i;
                    else if ((num & base) >> (i << 1) == 1) // bottom right
                        x ^= 1 << i, y ^= 1 << i;
                    else if ((num & base) >> (i << 1) == 2) // bottom left
                        x ^= 1 << i, y ^= 0 << i;
                    else if ((num & base) >> (i << 1) == 3) // top right
                        x ^= 0 << i, y ^= 1 << i;
                }
                cout << x + 1 << " " << y + 1 << "\n";
            }
        }
    }
    return 0;
}

