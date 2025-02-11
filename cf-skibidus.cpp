#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string curr;
        cin >> curr;
        cout << curr.substr(0, curr.size() - 2) << "i" << endl;
    }
    return 0;
}

