#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr;
    cin >> n;
    int people[n];
    people[0] = 1; // place jimmy at the front
    // read the "queue numbers"
    for (int i = 2; i <= n; ++i) {
        cin >> curr;
        people[curr + 1] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << people[i] ;
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
