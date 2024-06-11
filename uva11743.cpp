#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string l;
    getline(cin, l);
    n = stoi(l);
    while (n--) {
        // read in the current credit card
        string card = "";
        cin >> l;
        card += l;
        cin >> l;
        card += l;
        cin >> l;
        card += l;
        cin >> l;
        card += l;
        // apply the algorithm
        int sum = 0;
        int turn = 0;
        for (int i = 15; i >= 0; --i) {
            int val = (card[i] - '0');
            if (!turn) {
                sum += val;
            } else {
                val *= 2;
                if (val >= 10) {
                    sum += ((val / 10) + (val % 10));
                } else {
                    sum += val;
                }
            }
            turn = 1 - turn;
        }
        if ((sum % 10) == 0) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
