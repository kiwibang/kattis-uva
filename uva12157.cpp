#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        int call;
        long long mile = 0;
        long long juice = 0;
        for (int j = 0; j < n; ++j) {
            cin >> call;
            mile += (call / 30) * 10 + 10;
            juice += (call / 60) * 15 + 15;
        }
        cout << "Case " << i << ": ";
        if (mile < juice) {
            cout << "Mile " << mile << endl; 
        } else if (mile > juice) {
            cout << "Juice " << juice << endl;
        } else {
            cout << "Mile " << "Juice " << mile << endl;
        }
    }
    return 0;
}
