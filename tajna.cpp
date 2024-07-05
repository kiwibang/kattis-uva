#include <bits/stdc++.h>
using namespace std;

int main() {
    // read the message
    string msg;
    cin >> msg;
    // find the dimensions of the most suitable matrix
    int r = 0, n = msg.size(), cf;
    for (int c = n; c >= sqrt(n); --c) {
        double temprow = (double) n / c;    
        if (temprow == n / c) {
            if (temprow > r) {
                r = temprow;
                cf = c;
            }
        }
    }
    vector<vector<char> > b(r, vector<char>(cf, '\0'));
    int idx = 0;
    for (int j = 0; j < cf; ++j) {
        for (int i = 0; i < r; ++i) {
            b[i][j] = msg[idx++];
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < cf; ++j) {
            cout << b[i][j];
        }
    }
    cout << endl;
    return 0;
}
