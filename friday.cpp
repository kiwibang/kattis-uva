#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        vector<int> months(m, 0);
        for (int i = 0; i < m; ++i) {
            cin >> months[i];
        }
        int currday = 7, res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= months[i]; ++j) {
                if (currday == 5 && j == 13) {
                    ++res;
                } 
                ++currday;
                if (currday > 7) {
                    currday = 1;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
