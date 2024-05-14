#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int i = 1;
    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> curr;
        int mn = 1000001;
        int mx = -1000001;
        int n;
        ss >> n;
        for (int j = 0; j < n; j++) {
            ss >> num;
            mn = min(mn, num);
            mx = max(mx, num);
        }
        if (mn == 1000001 && mx == -1000001) {
            return 0;
        }
        cout << "Case " << i++ << ": " << mn << " " << mx << " " << mx - mn << endl;
    }
    return 0;
}
