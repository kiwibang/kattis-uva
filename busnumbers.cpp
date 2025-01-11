#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cr;
    cin >> n;
    vector<bool> have(1001, false);
    for (int i = 0; i < n; ++i) {
        cin >> cr;
        have[cr] = true;
    }
    int i = 1;
    while (i <= 1000) {
        if (!have[i]) {
            ++i;
            continue;
        }
        int st = i, j = i;
        while (j <= 1000 && have[j]) {
            ++j;
        }
        
        if (j - i >= 3) {
            cout << i << "-" << j - 1 << " ";
            i = j;
        } else {
            cout << st << " ";
            ++i;
        }
    }
    cout << endl;
    return 0;
}

