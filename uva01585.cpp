#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum, consec;
    string line;
    cin >> n;
    while (n--) {
        cin >> line;
        consec = 0;
        sum = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == 'X') {
                consec = 0;
            } else {
                ++consec;
                sum += consec;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
