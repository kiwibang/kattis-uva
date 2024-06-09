#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string curr;
        cin >> curr;
        int sum = 0;
        int turn = 0;
        for (int i = curr.size() - 1; i >= 0; --i) {
            if (turn == 0) {
                sum += (curr[i] - '0');
            } else {
                int temp = (curr[i] - '0') * 2;
                temp = temp > 9 ? (temp / 10) + temp % 10 : temp;
                sum += temp;
            }
            turn = 1 - turn;
        }
        if (sum % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }
    return 0;
}
