#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string prev, curr;
    bool isIncreasing = false, isDecreasing = false;
    getline(cin, prev);
    for (int i = 1; i < n; ++i) {
        getline(cin, curr);
        if (prev > curr) {
            isDecreasing = true;
        } else {
            isIncreasing = true;
        }
        if (isIncreasing && isDecreasing) {
            cout << "NEITHER" << endl;
            return 0;
        }
        prev = curr;
    }
    if (isIncreasing) {
        cout << "INCREASING" << endl;
    } else {
        cout << "DECREASING" << endl;
    }
    return 0;
}
