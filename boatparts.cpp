#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, n, day = -1;
    cin >> p >> n;
    string curr;
    unordered_set<string> parts;
    for (int i = 1; i <= n; ++i) {
        cin >> curr;
        parts.insert(curr);
        if (parts.size() == p && day == -1) {
            day = i;
        }
    }
    if (day == -1) {
        cout << "paradox avoided" << endl;
    } else {
        cout << day << endl;
    }
    return 0;
}

