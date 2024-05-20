#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int caseID = 0;
    while (caseID++ < t) {
        int n;
        cin >> n;
        int card;
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            cin >> card;
            if (card > mx) {
                mx = card;
            }
        }
        cout << "Case " << caseID << ": " << mx << endl;
    }
    return 0;
}
