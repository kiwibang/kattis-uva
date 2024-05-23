#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 && m != 0)) {
        // loop over the n offers
        double bestValue = 9999999.0;
        int numTix, price;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            // offer exceeds m, skip
            if (a > m) {
                continue;
            }
            // offer does not exceed m, calculate value of lobang
            double stonks = (double) b / a;
            // if best lobang
            if (stonks < bestValue) {
                bestValue = stonks;
                numTix = a;
                price = b;
            } else if (stonks == bestValue && a > numTix) { // if equal lobang
                // tiebreak by number of tickets
                numTix = a;
                price = b;
            }
        }
        if (bestValue != 9999999.0) {
            cout << "Buy " << numTix << " tickets for $" << price << endl;
        } else {
            cout << "No suitable tickets offered" << endl;
        }
    }
    return 0;
}
