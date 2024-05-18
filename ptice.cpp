#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string ans;
    cin >> n;
    cin >> ans;
    char adrian[] = {'A','B','C'};
    char bruno[] = {'B','A','B','C'};
    char goran[] = {'C','C','A','A','B','B'};
    int a = 0;
    int b = 0;
    int g = 0;
    // count scores
    for (int i = 0; i < n; ++i) {
        if (adrian[i % 3] == ans[i]) {
            ++a;
        }
        if (bruno[i % 4] == ans[i]) {
            ++b;
        }
        if (goran[i % 6] == ans[i]) {
            ++g;
        }
    }
    // compute the largest and winner
    int mx = max(a, max(b, g));
    cout << mx << endl;
    if (a == mx) {
        cout << "Adrian" << endl;
    }
    if (b == mx) {
        cout << "Bruno" << endl;
    }
    if (g == mx) {
        cout << "Goran" << endl;
    }
}
