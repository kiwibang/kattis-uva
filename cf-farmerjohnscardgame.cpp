#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // track which cow got which card
        vector<int> cardtocow(n * m);
        // i represents the cow id
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int curr;
                cin >> curr;
                cardtocow[curr] = i;
            }
        }
        // check ok
        bool ok = true;
        for (int i = 0; i + n < cardtocow.size(); ++i) {
            if (cardtocow[i] != cardtocow[i + n]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << cardtocow[i] + 1;
                if (i < n - 1) cout << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}

